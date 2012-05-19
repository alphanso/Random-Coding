#pragma once
#include "stdafx.h"
#include "global_var.h"

std::vector<State> p_optimal_path;
int p_current_state;

std::vector<State> c_optimal_path;
int c_current_state;

int nodes_reached;
int nodes_expanded;

int BOAT_SIZE;
std::vector<State> trans;
int flag;