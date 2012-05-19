#pragma once
#include "common.cpp"
#include "stdafx.h"

//using namespace std;

namespace AStar{
#ifndef _HEURISTICS_
#define _HEURISTICS_

int getx(int x){
  return (x%3);
}

int gety(int x){
  return (x/3);
}

int search(State a, int x){
  for (int i=0;i<9;i++){
    if (a[i]==x) {return i;}
  }
  return -1;
}

int absolute(int a){
  if(a > 0) return a;
  else return -a;
}

int heuristic_cost_estimate(State current_state, State goal, int heu_type){
  if (heu_type == 0){ // MANHATTAN
    int h=0, s, e;
    for (int i=1; i<9; i++){
      s =search(current_state,i);
      e=search(goal,i);
      if(s != -1 && e != -1)
	h += (absolute(getx(s)-getx(e)) + absolute(gety(s)-gety(e)));
    }
    return h;
  }

  if (heu_type == 1){ // COMMON DISPLACEMENT
    int h=0;
    for (int i=0; i<9; i++)
      if ( (current_state[i] != 0) && (current_state[i] != goal[i]) ){
	h++;
      }
    return h;
  }

  if (heu_type == 2){ // BASELINE
    return 0;
  }
}
#endif
}
