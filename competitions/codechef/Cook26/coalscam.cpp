//==============================================================================
// Copyright (C) 2012 Rishabh Singhal <rinkusinghal05@gmail.com>

// coalscam.cpp is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// coalscam.cpp is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//==============================================================================

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <string.h>
#include <cassert>
 
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define FOR(i, a, b) for(int i = a; i < b; i++)
const int mod = 1e9 + 7;
class pp {
public:
  int c;
  int s;
  int e;
};

bool operator <(pp a, pp b)
{
  return a.c < b.c;
}

pp mins[20000];
pp oth[20000];
bitset<5001> temp; 
vector< bitset<5001> > conn(5001, temp);

int add(int start, int end, int cost)
{
  if(conn[start].test(end))
    {
      conn[start].set(end);
      return cost;
    }
  else
    {
      

int main()
{
  int T;
  scanf("%d", &T);
  
  int N, M1, M2;
  int minscut, cost;
  while(T--)
    {
      scanf("%d %d %d", &N, &M1, &M2);
      
      FOR(i, 0, M1)
	scanf("%d %d %d", &(oth[i].s), &(oth[i].e), &(oth[i].c));
      FOR(i, 0, M2)
	scanf("%d %d %d", &(mins[i].s), &(mins[i].e), &(mins[i].c));
      minscut = 0; cost = 0;
      for(int i = 0; i < conn.size(); i++)
	conn[i].reset();
      FOR(i, 0, M2)
      	{
      	  int start, end;
      	  start = mins[i].s + 1;
      	  end = mins[i].e + 1;
	  minscut += add(start, end, mins[i].c);
      	}
      cost += minscut;
      FOR(i, 0, M1)
	{
	  int start, end;
	  start = oth[i].s + 1;
	  end = oth[i].e + 1;
	  cost += oadd(start, end, oth[i].c);
	}
      printf("%d %d\n", minscut, cost); 
    }
  return 0;
}
	
