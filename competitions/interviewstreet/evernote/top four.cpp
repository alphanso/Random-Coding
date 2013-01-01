//==============================================================================
// Copyright (C) 2012 Rishabh Singhal <rinkusinghal05@gmail.com>

// top four.cpp is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// top four.cpp is distributed in the hope that it will be useful,
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

int main()
{
  int N;
  scanf("%d", &N);
  int l[N];
  FOR(i, 0, N)
    scanf("%d", l + i);
  
  if(N <= 4)
    {
      FOR(i, 0, N)
	printf("%d\n", l[i]);
    }
  else 
    {
      multiset<int> s;
      s.insert(l[0]);
      s.insert(l[1]);
      s.insert(l[2]);
      s.insert(l[3]);
      int min_among_4 = *(s.begin()); 
      for(int i = 4; i < N; i++)
	{
	  if(min_among_4 < l[i]) 
	    {
	      s.erase(s.begin());
	      s.insert(l[i]);
	      min_among_4 = *(s.begin());
	    }
	}
      set<int>::reverse_iterator rit = s.rbegin();
      for(;rit != s.rend() ; ++rit)
	printf("%d\n", *rit);
    }
  return 0;
}
