//==============================================================================
// Copyright (C) 2012 Rishabh Singhal <rinkusinghal05@gmail.com>
// blocking.cpp is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// blocking.cpp is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
// You should have received a copy of the GNU General Public License
// along with this program. If not, see <http://www.gnu.org/licenses/>.
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
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define FOR(i, a, b) for(int i = a; i < b; i++)
int main()
{
  int n, t;
  scanf("%d", &n);
  vector<pii> s(n);
  vector< vector<pii> > v(n, s);
  FOR(i, 0, n)
    FOR(j, 0, n)
    {
      scanf("%d", &t);
      v[j][i] = make_pair(t, i + 1);
    }
  // FOR(i, 0, n)
  // FOR(j, 0, n)
  // {
  // cerr << v[i][j].first << " " << v[i][j].second << endl;
  // }
  int block[n], j, temp;
  int locked[100] = {0};
  bool flag;
  FOR(i, 0, n)
    sort(v[i].begin(), v[i].end());
  FOR(i, 0, n)
    {
      flag = true;
      j = i;
      while(flag)
	{
	  t = v[j].back().second - 1;
	  if(!locked[t])
	    {
	      block[j] = t + 1;
	      locked[t] = j + 1;
	      flag = false;
	    }
	  else
	    {
	      int t1 = v[j].back().first;
	      int t2 = v[locked[t] - 1].back().first;
	      if(t1 > t2)
		{
		  v[j].erase(v[j].begin() + v[j].size() - 1);
		}
	      else
		{
		  block[j] = t + 1;
		  temp = locked[t] - 1;
		  locked[t] = j + 1;
		  j = temp;
		  v[j].erase(v[j].begin() + v[j].size() - 1);
		}
	    }
	}
    }
  FOR(i, 0, n)
    printf("%d ", locked[i]);
  printf("\n");
  return 0;
} 
