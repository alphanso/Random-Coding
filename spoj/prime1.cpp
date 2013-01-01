//==============================================================================
// Copyright (C) 2012 Rishabh Singhal <rinkusinghal05@gmail.com>

// prime1.cpp is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// prime1.cpp is distributed in the hope that it will be useful,
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

#define FOR(i, a, b) for(int i = a; i < b; i++)

bitset<1000000009> bs;

void init()
{
  bs.set(0);
  bs.set(1);
  int S = sqrt(1000000009);
  S++;
  for(int i = 4; i < bs.size(); i+=2)
    bs.set(i);
  for(int i = 3; i < S; i++)
    {
      if(bs[i]) continue;
      else
	{
	  for(int j = i*i; j < bs.size(); j+=i)
	    bs.set(j);
	}
    }
}

int main() 
{
  int T;
  scanf("%d", &T);
  int m,n;
  init();
  while(T--)
    {
      scanf("%d %d", &m, &n);
      for(int i = m; i < n+1; i++)
	if(!bs[i]) printf("%d\n", i);
    }
  return 0;
}
