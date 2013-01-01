//==============================================================================
// Copyright (C) 2012 Rishabh Singhal <rinkusinghal05@gmail.com>

// macgun.cpp is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// macgun.cpp is distributed in the hope that it will be useful,
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

char grid[702][702];
int N, M;
void block(int x, int y)
{
  if(x >= 2 && y >= 2 && grid[x-1][y-1] != 'P' && grid[x-2][y-2] == 'F') grid[x-2][y-2] = 'B';
  if(x >= 2 && y+2 < N && grid[x-1][y+1] != 'P' && grid[x-2][y+2] == 'F') grid[x-2][y+2] = 'B';
  if(x+2 < M && y >= 2 && grid[x+1][y-1] != 'P' && grid[x+2][y-2] == 'F') grid[x+2][y-2] = 'B';
  if(x+2 < M && y+2 < N && grid[x+1][y+1] != 'P' && grid[x+2][y+2] == 'F') grid[x+2][y+2] = 'B';
}      

void print()
{
  FOR(i, 0, M)
    cout << grid[i] << endl; 
  printf("\n");
}

int main()
{
  int ans;
  queue<pii> q1, q2;
  int f1, f2, x, y;
  pii t;
  scanf("%d %d", &M, &N);
  while(M && N)
    {
      FOR(i, 0, M)
	scanf("%s", grid[i]);

      // FOR(i, 0, M)
      // 	{
      // 	  FOR(j, 0, N)
      // 	    cout << grid[i][j] << " ";
      // 	  cout << endl;
      // 	}
      
      FOR(i, 0, M)
	FOR(j, 0, N)
	if(grid[i][j] == 'G')
	  block(i, j);
 
      // print();
      ans = 0;
      FOR(i, 0, M)
	{
	  FOR(j, 0, N)
	    {
	      if(grid[i][j] == 'F')
		{
		  // cerr << i << " " << j << endl;
		  assert(q1.empty());
		  assert(q2.empty());
		  f1 = f2 = 0;
		  q1.push(make_pair(i, j));
		  while(!q1.empty())
		    {
		      // cerr << q1.size() << " " << q2.size() << endl;
		      while(!q1.empty())
			{
			  t = q1.front();
			  q1.pop();
			  x = t.first;
			  y = t.second;
			  if(grid[x][y] != 'V')
			    {
			      // cout << "1 " << x << " " << y << " " << grid[x][y] << endl;
			      assert(grid[x][y] == 'F');
			      f1++;
			      grid[x][y] = 'V';
			      if(x >= 2 && y >= 2 && grid[x-1][y-1] != 'P' && grid[x-2][y-2] == 'F') q2.push(make_pair(x-2, y-2));
			      if(x >= 2 && y+2 < N && grid[x-1][y+1] != 'P' && grid[x-2][y+2] == 'F') q2.push(make_pair(x-2, y+2));
			      if(x+2 < M && y >= 2 && grid[x+1][y-1] != 'P' && grid[x+2][y-2] == 'F') q2.push(make_pair(x+2, y-2));
			      if(x+2 < M && y+2 < N && grid[x+1][y+1] != 'P' && grid[x+2][y+2] == 'F') q2.push(make_pair(x+2, y+2));
			    }
			}
		      assert(q1.empty());
		      while(!q2.empty())
			{
			  t = q2.front();
			  q2.pop();
			  x = t.first;
			  y = t.second;
			  if(grid[x][y] != 'V')
			    {
			      assert(grid[x][y] == 'F');
			      // cout << "2 " << x << " " << y << " " << grid[x][y] << endl;
			      f2++;
			      grid[x][y] = 'V';
			      if(x >= 2 && y >= 2 && grid[x-1][y-1] != 'P' && grid[x-2][y-2] == 'F') q1.push(make_pair(x-2, y-2));
			      if(x >= 2 && y+2 < N && grid[x-1][y+1] != 'P' && grid[x-2][y+2] == 'F') q1.push(make_pair(x-2, y+2));
			      if(x+2 < M && y >= 2 && grid[x+1][y-1] != 'P' && grid[x+2][y-2] == 'F') q1.push(make_pair(x+2, y-2));
			      if(x+2 < M && y+2 < N && grid[x+1][y+1] != 'P' && grid[x+2][y+2] == 'F') q1.push(make_pair(x+2, y+2));
			    }
			}
		      assert(q2.empty());
		    }
		  // cout << f1 << " " << b1 << endl;
		  // cout << f2 << " " << b2 << endl;
		  // print();
		  ans += max(f1, f2);
		}
	    }
	}
      printf("%d\n", ans);
      scanf("%d %d", &M, &N);
    }
  return 0;
}
