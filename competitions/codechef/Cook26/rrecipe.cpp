//==============================================================================
// Copyright (C) 2012 Rishabh Singhal <rinkusinghal05@gmail.com>

// rrecipe.cpp is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// rrecipe.cpp is distributed in the hope that it will be useful,
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
const int mod = 1e7 + 9;

char l[1000009];
int main()
{
  int T, N;
  ll ans;
  bool nvalid;
  scanf("%d", &T);
  
  while(T--)
    {
      scanf("%s", l);
      N = strlen(l);
      ans = 1;
      nvalid = false;	
      FOR(i, 0, N / 2)
	{
	  if(l[i] != '?' && l[N - i - 1] != '?' && l[i] != l[N - i - 1])
	    {
	      nvalid = true;
	      break;
	    }
	  else if(l[i] == '?' && l[N - i - 1] == '?') ans *= 26;
	  else continue;
	  if(ans >= mod) ans %= mod;
	}
      if(N % 2 && l[N / 2] == '?') ans *= 26;
      if(ans >= mod) ans %= mod;
      if(nvalid) printf("0\n");
      else printf("%lld\n", ans);
    }
  return 0;
}
