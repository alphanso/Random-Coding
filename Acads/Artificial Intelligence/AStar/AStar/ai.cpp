#pragma once
#include "stdafx.h"
#include "global_var.h"
//#include "heuristics.cpp"
//using namespace std;

namespace AStar{
#ifndef _AI_
#define _AI_

	//returns path from start to current_node
	std::vector<State> reconstruct_path(std::map<State, State>came_from, State current_node){
		std::vector<State> p;
		if (came_from.find(current_node) != came_from.end()){
			p = reconstruct_path(came_from, came_from[current_node]);
			p.push_back(current_node);
		}
		else
			p.push_back(current_node);
		return p;
	}

	//main ai program
	std::vector<State> Astar(State start,State goal, int hno){

		std::set<State> closedset;   // closed list
		std::set<State> openset;     // open list

		openset.insert(start);

		std::map<State,State> came_from;    // The map of navigated nodes.
		std::map<State, int> g_score,f_score,h_score;

		g_score[start] = 0;    // Cost from start along best known path.
		h_score[start] = heuristic_cost_estimate(start, goal, hno); //heuristic
		f_score[start] = g_score[start] + h_score[start];    // Estimated total 

		std::set< std::pair<int,State> > openQ;
		openQ.insert(make_pair(f_score[start],start));

		while (!openset.empty()){ // as long as openset is not empty = more nodes to be expanded
			std::set < std::pair<int,State> >::iterator p = openQ.begin();
			State x = p->second;
			int v = p->first;

			// transfer from closed set to open set
			openQ.erase(p);
			openset.erase(x);
			closedset.insert(x);

			//if x == goal return path
			if (isequal(x, goal)){
				nodes_expanded = closedset.size();
				nodes_reached = closedset.size() + openset.size();
				return reconstruct_path(came_from, goal);
			}

			std::vector<State> neighbor_states = neighbors(x);
			bool tentative_is_better;

			for(int y=0;y<neighbor_states.size();y++){
				int tentative_g_score = g_score[x] + dist_between(x,neighbor_states[y]);

				if (closedset.find(neighbor_states[y])!=closedset.end()){
					if (tentative_g_score < g_score[neighbor_states[y]]){ // update needed if new value better
						g_score[neighbor_states[y]]=tentative_g_score; // update g-value of node in CL
						update_children(neighbor_states[y],came_from,g_score,h_score,f_score); // recursively update g- and f-value of children
						came_from[neighbor_states[y]] = x; // update parent-pointers of n
					}
					continue;
				}

				// checks whether neighbor is in openset and inserts it if it cannot find it in there
				if (openset.find(neighbor_states[y])==openset.end()){
					openset.insert(neighbor_states[y]);
					h_score[neighbor_states[y]] = heuristic_cost_estimate(neighbor_states[y], goal, hno);
					tentative_is_better = true; 
				} else if (tentative_g_score < g_score[neighbor_states[y]]){
					tentative_is_better = true;
					openQ.erase(openQ.find(make_pair(f_score[neighbor_states[y]],neighbor_states[y])));
				} else {
					tentative_is_better = false;
				}

				if (tentative_is_better){
					came_from[neighbor_states[y]] = x; // Parentpointer Redirection
					g_score[neighbor_states[y]] = tentative_g_score;
					f_score[neighbor_states[y]] = g_score[neighbor_states[y]] + h_score[neighbor_states[y]];
					openQ.insert(make_pair(f_score[neighbor_states[y]], neighbor_states[y]));
				}
			}
		}
		std::vector<State> answer;
		//cout<<"failure"<<endl;
		//MessageBox::Show("FAILURE","Ooops");
		return answer;
	}





	//main ai program cannibals
	std::vector<State> c_Astar(State start,State goal, int hno){

		std::set<State> closedset;   // closed list
		std::set<State> openset;     // open list

		openset.insert(start);

		std::map<State,State> came_from;    // The map of navigated nodes.
		std::map<State, int> g_score,f_score,h_score;

		g_score[start] = 0;    // Cost from start along best known path.
		h_score[start] = c_heuristic_cost_estimate(start, goal, hno); //heuristic
		f_score[start] = g_score[start] + h_score[start];    // Estimated total 

		std::set< std::pair<int,State> > openQ;
		openQ.insert(make_pair(f_score[start],start));

		while (!openset.empty()){
			std::set < std::pair<int,State> >::iterator p = openQ.begin();
			State x = p->second;
			int v = p->first;

			openQ.erase(p);
			openset.erase(x);
			closedset.insert(x);

			//if x == goal return path
			if (isequal(x, goal)){
				nodes_expanded = closedset.size();
				nodes_reached = closedset.size() + openset.size();
				return reconstruct_path(came_from, goal);
			}

			std::vector<State> neighbor_states = c_neighbors(x);

			bool tentative_is_better;

			for(int y=0;y<neighbor_states.size();y++){
				int tentative_g_score = g_score[x] + c_dist_between(x,neighbor_states[y]);

				if (closedset.find(neighbor_states[y])!=closedset.end()){
					if (tentative_g_score < g_score[neighbor_states[y]]){ // update needed
						g_score[neighbor_states[y]]=tentative_g_score; // update g-value of node in CL
						c_update_children(neighbor_states[y],came_from,g_score,h_score,f_score); // recursively update g- and f-value of children
						came_from[neighbor_states[y]] = x; // update parent-pointers of n
					}
					continue;
				}

				if (openset.find(neighbor_states[y])==openset.end()){
					openset.insert(neighbor_states[y]);
					h_score[neighbor_states[y]] = c_heuristic_cost_estimate(neighbor_states[y], goal, hno);
					tentative_is_better = true;
				} else if (tentative_g_score < g_score[neighbor_states[y]]){
					tentative_is_better = true;
					openQ.erase(openQ.find(make_pair(f_score[neighbor_states[y]],neighbor_states[y])));
				} else {
					tentative_is_better = false;
				}

				if (tentative_is_better){
					came_from[neighbor_states[y]] = x;
					g_score[neighbor_states[y]] = tentative_g_score;
					f_score[neighbor_states[y]] = g_score[neighbor_states[y]] + h_score[neighbor_states[y]];
					openQ.insert(make_pair(f_score[neighbor_states[y]], neighbor_states[y]));
				}
			}
		}
		std::vector<State> answer;
		//cout<<"failure"<<endl;
		//MessageBox::Show("FAILURE","Ooops");
		return answer;
	}

	//main ai program bidirectional
	std::vector<State> bidirectional_Astar(State start,State goal, int hno){
		//(1)  
		std::set<State> closedset;   // closed list
		std::set<State> openset;     // open list
		//(2)
		std::set<State> closedset_2;   // closed list 2
		std::set<State> openset_2;     // open list 2

		//(1)
		openset.insert(start);
		//(2)
		openset_2.insert(goal);

		//(1)
		std::map<State,State> came_from;    // The map of navigated nodes.
		std::map<State, int> g_score,f_score,h_score;
		//(2)
		std::map<State,State> came_from_2;    // The map of navigated nodes.
		std::map<State, int> g_score_2,f_score_2,h_score_2;

		g_score[start] = 0;    // Cost from start along best known path.
		h_score[start] = heuristic_cost_estimate(start, goal, hno); //heuristic
		f_score[start] = g_score[start] + h_score[start];    // Estimated total 
		g_score_2[goal] = 0;    // Cost from start along best known path.
		h_score_2[goal] = heuristic_cost_estimate(goal, start, hno); //heuristic
		f_score_2[goal] = g_score_2[goal] + h_score_2[goal];    // Estimated total 

		std::set< std::pair<int,State> > openQ;
		openQ.insert(make_pair(f_score[start],start));
		std::set< std::pair<int,State> > openQ_2;
		openQ_2.insert(make_pair(f_score_2[goal],goal));

		while ((!openset.empty())&&(!openset_2.empty())){

			// (1)
			if (!openset.empty()){
				std::set < std::pair<int,State> >::iterator p = openQ.begin();
				State x = p->second;
				int v = p->first;

				openQ.erase(p);
				openset.erase(x);
				closedset.insert(x);

				//if x == goal return path or x in open or closedset of backward branch
				if ((isequal(x, goal))||(openset_2.find(x)!=openset_2.end())||(closedset_2.find(x)!=closedset_2.end())){ 
					nodes_expanded = closedset.size()+closedset_2.size();
					nodes_reached = closedset.size() + openset.size() + closedset_2.size() + openset_2.size();
					std::vector<State> forward_path = reconstruct_path(came_from, x);
					std::vector<State> backward_path = reconstruct_path(came_from_2, x);

					std::reverse(backward_path.begin(),backward_path.end());
					//backward_path.erase(backward_path.begin());
					
					for (int i=1; i<backward_path.size(); i++)
						forward_path.push_back(backward_path[i]);
					
					return forward_path;
				}

				std::vector<State> neighbor_states = neighbors(x);

				bool tentative_is_better;

				for(int y=0;y<neighbor_states.size();y++){
					int tentative_g_score = g_score[x] + dist_between(x,neighbor_states[y]);

					if (closedset.find(neighbor_states[y])!=closedset.end()){
						if (tentative_g_score < g_score[neighbor_states[y]]){ // update needed
							g_score[neighbor_states[y]]=tentative_g_score; // update g-value of node in CL
							update_children(neighbor_states[y],came_from,g_score,h_score,f_score); // recursively update g- and f-value of children
							came_from[neighbor_states[y]] = x; // update parent-pointers of n
						}
						continue;
					}

					if (openset.find(neighbor_states[y])==openset.end()){
						openset.insert(neighbor_states[y]);
						h_score[neighbor_states[y]] = heuristic_cost_estimate(neighbor_states[y], goal, hno);
						tentative_is_better = true;
					} else if (tentative_g_score < g_score[neighbor_states[y]]){
						tentative_is_better = true;
						openQ.erase(openQ.find(make_pair(f_score[neighbor_states[y]],neighbor_states[y])));
					} else {
						tentative_is_better = false;
					}

					if (tentative_is_better){
						came_from[neighbor_states[y]] = x;
						g_score[neighbor_states[y]] = tentative_g_score;
						f_score[neighbor_states[y]] = g_score[neighbor_states[y]] + h_score[neighbor_states[y]];
						openQ.insert(make_pair(f_score[neighbor_states[y]], neighbor_states[y]));
					}
				}
			

			}
			// (2)
			if (!openset_2.empty()){
				std::set < std::pair<int,State> >::iterator p = openQ_2.begin();
				State x = p->second;
				int v = p->first;

				openQ_2.erase(p);
				openset_2.erase(x);
				closedset_2.insert(x);

				//if x == start return path or x found in open or closed set of forward path
				if ((isequal(x, start))||(openset.find(x)!=openset.end())||(closedset.find(x)!=closedset.end())){
					nodes_expanded = closedset.size()+closedset_2.size();
					nodes_reached = closedset.size() + openset.size() + closedset_2.size() + openset_2.size();
					std::vector<State> forward_path = reconstruct_path(came_from, x);
					std::vector<State> backward_path = reconstruct_path(came_from_2, x);

					std::reverse(backward_path.begin(),backward_path.end());
					//backward_path.erase(backward_path.begin());
					
					for (int i=1; i<backward_path.size(); i++)
						forward_path.push_back(backward_path[i]);
					
					return forward_path;
				}



				std::vector<State> neighbor_states = neighbors(x);

				bool tentative_is_better;

				for(int y=0;y<neighbor_states.size();y++){
					int tentative_g_score = g_score_2[x] + dist_between(x,neighbor_states[y]);

					if (closedset_2.find(neighbor_states[y])!=closedset_2.end()){
						if (tentative_g_score < g_score_2[neighbor_states[y]]){ // update needed
							g_score_2[neighbor_states[y]]=tentative_g_score; // update g-value of node in CL
							update_children(neighbor_states[y],came_from_2,g_score_2,h_score_2,f_score_2); // recursively update g- and f-value of children
							came_from_2[neighbor_states[y]] = x; // update parent-pointers of n
						}
						continue;
					}

					if (openset_2.find(neighbor_states[y])==openset_2.end()){
						openset_2.insert(neighbor_states[y]);
						h_score_2[neighbor_states[y]] = heuristic_cost_estimate(neighbor_states[y], start, hno);
						tentative_is_better = true;
					} else if (tentative_g_score < g_score_2[neighbor_states[y]]){
						tentative_is_better = true;
						openQ_2.erase(openQ_2.find(make_pair(f_score_2[neighbor_states[y]],neighbor_states[y])));
					} else {
						tentative_is_better = false;
					}

					if (tentative_is_better){
						came_from_2[neighbor_states[y]] = x;
						g_score_2[neighbor_states[y]] = tentative_g_score;
						f_score_2[neighbor_states[y]] = g_score_2[neighbor_states[y]] + h_score_2[neighbor_states[y]];
						openQ_2.insert(make_pair(f_score_2[neighbor_states[y]], neighbor_states[y]));
					}
				}
			}
	}


			std::vector<State> answer;
			//cout<<"failure"<<endl;
			//MessageBox::Show("FAILURE","Ooops");
			return answer;
		}
#endif
}