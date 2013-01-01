//==============================================================================
// Copyright (C) 2012 Rishabh Singhal <rinkusinghal05@gmail.com>

// mp.cpp is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// mp.cpp is distributed in the hope that it will be useful,
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

int main()
{
  int N;
  scanf("%d\n", &N);
  
  ll x[N], y[N], index, dist;
  FOR(i, 0, N)
    scanf("%lld %lld", x+i, y+i);
  
  if(N % 2)
    {
      ll xavg, yavg;
      vector<int> vx(x, x+N);
      vector<int> vy(y, y+N);
      nth_element(vx.begin(), vx.begin() + (N / 2), vx.end());
      nth_element(vy.begin(), vy.begin() + (N / 2), vy.end());
      xavg = vx[N/2];
      yavg = vy[N/2];
      cout << xavg << " " << yavg << endl;
      dist = max(abs(x[0] - xavg), abs(y[0] - yavg));
      index = 0;
      FOR(i, 1, N)
	{
	  ll t = max(abs(x[i] - xavg), abs(y[i] - yavg));
	  if(t < dist) dist = t, index = i;
	}
    }
  else
    {
      ll x1, x2, y1, y2;
      vector<int> vx(x, x+N);
      vector<int> vy(y, y+N);
      nth_element(vx.begin(), vx.begin() + (N / 2), vx.end());
      nth_element(vy.begin(), vy.begin() + (N / 2), vy.end());
      nth_element(vx.begin(), vx.begin() -1 + (N / 2), vx.end());
      nth_element(vy.begin(), vy.begin() -1 + (N / 2), vy.end());
      x1 = vx[N/2];
      y1 = vy[N/2];
      x2 = vx[N/2 - 1];
      y2 = vy[N/2 - 1];
      cout << x1 << " " << x2 << endl;
      cout << y1 << " " << y2 << endl;
      dist = max(min(abs(x[0] - x1), abs(x[0] - x2)), min(abs(y[0] - y1), abs(y[0] - y2)));
      index = 0;
      FOR(i, 1, N)
	{
	  ll t = max(min(abs(x[i] - x1), abs(x[i] - x2)), min(abs(y[i] - y1), abs(y[i] - y2)));
	  if(t < dist) dist = t, index = i;
	}
    }
  cout << x[index] << " " << y[index] << endl;
  ll ans = 0;
  FOR(i, 0, N)
    ans += max(abs(x[i]-x[index]), abs(y[i]-y[index]));
  printf("%lld\n", ans);
  return 0;
}
