// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
#pragma once

// TODO: reference additional headers your program requires here
#include <vector>
#include <utility>
#include <map>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <set>
#include <queue>
#include <algorithm>

typedef std::vector<int> State;

namespace AStar{
// 8Puzzle + A*
bool is_solvable(State start, State goal);
int c2p(int x, int y);
int heuristic_cost_estimate(State current_state, State goal, int heu_type);
bool isequal(State x, State y);
std::vector<State> neighbors(State current_state);
int dist_between (State a, State b);
void update_children(State p, std::map<State,State> came_from, std::map<State, int> g_score,std::map<State, int> h_score, std::map<State, int> f_score);
std::vector<State> Astar(State start,State goal, int hno);

// Cannibals
State c_make_state(int x, int y, int z, int M, int C);
bool c_check(State a);
bool c_is_solvable(State start, State goal);
int c_dist_between(State a, State b);
void c_transitions();
std::vector<State> c_neighbors(State current_state);
int c_heuristic_cost_estimate(State x, State goal, int hno);
void c_update_children(State p, std::map<State,State> came_from, std::map<State, int> g_score,std::map<State, int> h_score, std::map<State, int> f_score);
bool c_isequal(State x, State y);
std::vector<State> c_Astar(State start,State goal, int hno);

std::vector<State> bidirectional_Astar(State start,State goal, int hno);
}
