//==============================================================================
// Copyright (C) 2012 Rishabh Singhal <rinkusinghal05@gmail.com>

// crowd.cpp is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// crowd.cpp is distributed in the hope that it will be useful,
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
 
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define FOR(i, a, b) for(int i = a; i < b; i++)
const int mod = 1e9+7;

void solve(ll p)
{
  ull a[] = {1,1,1,1,1,0,0,0,0,1,0,0,0,0,0,2};
  ull b[] = {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1};
  ull c[4*4] = {}, *res, *m1, *m2; 
  res = c;
  m1 = b, m2 = a;
  while(p > 0)
    {
      if(p % 2)
	{
	  FOR(k, 0, 4) FOR(i, 0, 4) FOR(j, 0, 4)
	    res[i*4+j] += m1[i*4+k] * m2[k*4+j];
	  FOR(i, 0, 4) FOR(j, 0, 4)
	    if(res[i*4+j] >= mod) res[i*4+j] %= mod;
	  swap(res, m1);
	  memset(res, 0, sizeof(ull)*16); 
	}
      FOR(k, 0, 4) FOR(i, 0, 4) FOR(j, 0, 4)
	res[i*4+j] += m2[i*4+k] * m2[k*4+j];
      FOR(i, 0, 4) FOR(j, 0, 4)
	if(res[i*4+j] >= mod) res[i*4+j] %= mod;
      swap(res, m2);
      memset(res, 0, sizeof(ll)*16); 
      p /= 2;
    }
  ull ans = 3*m1[0] + 1*m1[1] + 4*m1[3];
  if(ans >= mod) ans %= mod;
  printf("%lld\n", ans);
}

int main()
{
  int T;
  ll N;
  scanf("%d", &T);
  
  while(T--)
    {
      scanf("%lld", &N);
      if(N == 1) cout << "0" << endl;
      else if(N == 2) cout << "0" << endl;
      else if(N == 3) cout << "1" << endl;
      else if(N == 4) cout << "3" << endl;
      else solve(N - 4);
    }
  return 0;
}
