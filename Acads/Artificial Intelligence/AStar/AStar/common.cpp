#pragma once
#include "stdafx.h"


namespace AStar{

#ifndef _COMMON_
#define _COMMON_


//returns x==y if its a container.
bool isequal(State x, State y){
  if(x.size() != y.size()){
    return false;
  }
  for(int i=0;i<x.size();i++)
    if(x[i]!=y[i]) return false;
  return true;
}


bool is_solvable(State start, State goal){
  // test for odd or even number of inversions
  int start_inversions = 0;
  int goal_inversions = 0;

  for (int i=0; i<9; i++)
    for (int j=0; j<9; j++){
      if (i<j && start[i]>start[j] && start[j]>0)
	start_inversions++;
      if (i<j && goal[i]>goal[j] && goal[j]>0)
	goal_inversions++;
    }

  // if both odd or both even, then reachable
  if (((start_inversions % 2 == 0) && (goal_inversions % 2 == 0))||((start_inversions % 2 == 1) && (goal_inversions % 2 == 1)))
    return true;
  else
    return false;
}

int c2p(int x, int y){ 
  // converts coordinates (x,y) to the position of a 1D-Array {1,2,3,...}
  int pos = x * 3 + y; 
  return pos;
}

//give the neighbors of current state
std::vector<State> neighbors(State current_state){
  int x,y; // x = horizontal, y = vertical - both starting at 0
  int c=0; // current blank position
  std::vector<State> neighbors;
    
  // find blank
  for (int i=0; i<9; i++){
    if (current_state[i]==0){ // found blank tile
      c=i; // save location
      break; // stop searching
    }
  }
  State temp_state(9);	
  // calculate coordinates
  x = c / 3;
  y = c % 3;
 
  // try all 4 directions

  // up
  if (y-1 >= 0){
    copy(current_state.begin(), current_state.end(), temp_state.begin()); // create temp_array
    temp_state[c2p(x,y)] = current_state[c2p(x,y-1)]; // swop 2 tiles
    temp_state[c2p(x,y-1)] = current_state[c2p(x,y)];
    neighbors.push_back(temp_state); // save temp_array
  }
   
  // right
  if (x+1 < 3){
    copy(current_state.begin(), current_state.end(), temp_state.begin()); // create temp_array
    temp_state[c2p(x,y)] = current_state[c2p(x+1,y)]; // swop 2 tiles
    temp_state[c2p(x+1,y)] = current_state[c2p(x,y)];
    neighbors.push_back(temp_state); // save temp_array  neighbors.add(temp_state); // save temp_array
  }
  // down
  if (y+1 < 3){
    copy(current_state.begin(), current_state.end(), temp_state.begin()); // create temp_array
    temp_state[c2p(x,y)] = current_state[c2p(x,y+1)]; // swop 2 tiles
    temp_state[c2p(x,y+1)] = current_state[c2p(x,y)];
    neighbors.push_back(temp_state); // save temp_array   
  }
  // left
  if (x-1 >= 0){
    copy(current_state.begin(), current_state.end(), temp_state.begin()); // create temp_array
    temp_state[c2p(x,y)] = current_state[c2p(x-1,y)]; // swop 2 tiles
    temp_state[c2p(x-1,y)] = current_state[c2p(x,y)];
    neighbors.push_back(temp_state); // save temp_array
  }
  
  return neighbors;
}

//distance between neighbor
int dist_between (State a, State b){
  return 1;
}


void update_children(State p, std::map<State,State> came_from, std::map<State, int> g_score,std::map<State, int> h_score, std::map<State, int> f_score){       
  std::vector<State> neighbor_states = neighbors(p);
  for(int i=0;i<neighbor_states.size();i++){
    State n = neighbor_states[i];
    int tentative_g_score = g_score[p]+dist_between(n,p); 
    if(g_score.find(n)!=g_score.end() && g_score[n] > tentative_g_score){ // compares new g_score with stored one
      g_score[n] = tentative_g_score;
      f_score[n] = g_score[n] + h_score[n]; // update f-score of child
      update_children(n,came_from,g_score,h_score,f_score); // repeat recursively for children and neighbors
    }
  }
}
#endif
}

