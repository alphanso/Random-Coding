//==============================================================================
// Copyright (C) 2012 Rishabh Singhal <rinkusinghal05@gmail.com>

// pperm.cpp is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// pperm.cpp is distributed in the hope that it will be useful,
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

int mem[5000009] = {};
int main()
{
  int T, N;
  ll count = 3;
  ll calc;
  scanf("%d", &T);
  bitset<5000009> bs;
  ll size = bs.size();
  for(int i = 4; i < size; i += 2)
    bs.set(i);

  for(int i = 9; i < size; i += 6)
    bs.set(i);
  
  mem[1] = 1; mem[2] = 2; mem[3] = 6;
  // cout << "all good\n";
  for(ll i = 4; i <= 5000000; i++)
    {
      if(bs[i])
	calc = mem[i - 1] * count;
      else 
	{
	  count++;
	  calc = mem[i - 1] * count;
	  // cout << i << endl;
	  for(ll j = i * i; j < size; j += i)
	    {
	      // cout<< j << endl;
	      bs.set(j);
	    }
	}
      if(calc >= mod) calc %= mod;
      mem[i] = calc;
    }
  
  while(T--)
    {
      scanf("%d", &N);
      printf("%d\n", mem[N]);
    }
  return 0;
}
