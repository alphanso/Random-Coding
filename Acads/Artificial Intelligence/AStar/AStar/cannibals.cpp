#pragma once
#include "stdafx.h"
#include "global_var.h"

namespace AStar{
#ifndef _CANNIBALS_
#define _CANNIBALS_

//int flag = 0;

State c_make_state(int x, int y, int z, int M, int C){
	std::vector<int> a(5);
	a[0]=x;
	a[1]=y;
	a[2]=z;
	a[3]=M;
	a[4]=C;
	return a;
}

//returns x==y if its a container.
bool c_isequal(State x, State y){
	return(x[0]==y[0] && x[1]==y[1] && x[2]==y[2]);  
}

//Is cannibal > missionary?? if yes return false 
//checks on boat and ground
bool c_check(State a){
	if ((a[0] >= 0 && a[0] <=a[3]) && (a[1] >= 0 && a[1] <=a[4]) && (a[2] >= 0 && a[2] <=1) && (a[0] >= a[1] || a[0] == 0) && (a[3] - a[0] >= a[4] - a[1] || a[3] - a[0] == 0))
		return true;
	else
		return false;
}

//print state if its vector or array
//void print_state(State a){
	//cout<<"Missionary : "<<a[0]<<" "<<"Cannibal : "<<a[1]<<" "<<"Boat : "<<a[2]<<endl;//<<" " << a[3] << " " << a[4] << endl;
//}
//Missionary > 4 => C != M
//M <= 4 all is  correct
//TO DO: check for boat size
bool c_is_solvable(State start, State goal){
	if (start[0] >= 4) return (start[0] != start[1]);
	if (start[1] >= 4) return (start[0] != start[1]);
	return true;
}

int c_dist_between(State a, State b){
	return 1;
}

void c_transitions(){
	trans.clear();
	for(int i=0 ; i <= BOAT_SIZE/2 ; i++){
		for (int j = BOAT_SIZE-i ; j >=i ; j--){
			State x = c_make_state(j , i , 1, 0, 0);
			if( j > 0)trans.push_back(x);	
			}
		}
	for(int i= 1; i <= BOAT_SIZE; i++){
		State x = c_make_state(0, i, 1, 0, 0);
		trans.push_back(x); 
	}		
}
	
//give the neighbors of current state
std::vector<State> c_neighbors(State current_state){
	//cout<<"flag: "<<flag<<endl;
	if (flag == 0) c_transitions();
	flag = 1;
	
	std::vector<State> neighbours;
	
	State a;
	
	for (int i=0; i<trans.size(); i++){
		a = c_make_state((current_state[0]-trans[i][0]),(current_state[1]-trans[i][1]),(current_state[2]-trans[i][2]), current_state[3], current_state[4]);
		// print_state(a);
		if (c_check(a)) neighbours.push_back(a);
		//cout<<"state print: ";print_state(a);
		a = c_make_state((current_state[0]+trans[i][0]),(current_state[1]+trans[i][1]),(current_state[2]+trans[i][2]), current_state[3], current_state[4]);
		// print_state(a);
		if (c_check(a)) neighbours.push_back(a);
		//cout<<"\nstate print: ";print_state(a);
		//cout<<"\n";
	}
	//cout<<"size: "<<neighbours.size()<<endl;
	//for (int i=0; i<neighbours.size(); i++){
		//print_state(neighbours[i]);
		//cout<<"flag: "<<flag<<endl;
		
	//}
	//cout<<endl;
	return neighbours;
}

int c_heuristic_cost_estimate(State x, State goal, int hno){

	if (hno == 0){
		int h=0;
		h = (2*((x[0] + x[1])/2) + 1);
		return h;
	}
	else
		return 0;
}



void c_update_children(State p, std::map<State,State> came_from, std::map<State, int> g_score,std::map<State, int> h_score, std::map<State, int> f_score){       
  std::vector<State> neighbor_states = c_neighbors(p);
  for(int i=0;i<neighbor_states.size();i++){
    State n = neighbor_states[i];
    int tentative_g_score = g_score[p]+c_dist_between(n,p);
    if(g_score.find(n)!=g_score.end() && g_score[n] > tentative_g_score){
      g_score[n] = tentative_g_score;
      f_score[n] = g_score[n] + h_score[n]; // update f-score of child
      c_update_children(n,came_from,g_score,h_score,f_score); // repeat recursively for children
    }
  }
}


/*
int main(){
	State a = make_state(3,3,1);
	
	
	for(int k=0 ; k < trans.size() ; k++){
		cout<<"<"<<trans[k][0]<<","<<trans[k][1]<<","<<trans[k][2]<<">"<<endl;
	}
	
	std::vector<State> x = c_neighbors(a);
	cout<<c_heuristic_cost_estimate(a,make_state(0,0,0),2)<<endl;
	return 0;
}
*/
#endif
}