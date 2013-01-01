//==============================================================================
// Copyright (C) 2012 Rishabh Singhal <rinkusinghal05@gmail.com>

// xorq.cpp is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// xorq.cpp is distributed in the hope that it will be useful,
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

typedef unsigned short us;
#define FOR(i, a, b) for(int i = a; i < b; i++)

us x[100000] = {};
int main()
{
  int T;
  int N, Q;
  us a, p, q ;
  scanf("%d", &T);

  while(T--)
    {
      scanf("%d %d", &N, &Q);
      FOR(i, 0, N)
	scanf("%hu", x+i);
      
      FOR(i, 0, Q)
	{
	  scanf("%hu %hu %hu", &a, &p, &q);
	  p--; q--;
	  vector<bool> b(q - p + 1, 0);
	  us min = x[p], max = x[p], nmin, nmax;
	  for(int k = 1; k < b.size(); k++)
	    {
	      if(x[p+k] < min) min = x[p+k];
	      if(x[p+k] > max) max = x[p+k];
	    }
	  for(int j = 14; j > -1; j--)
	    {
	      if((min>>j) ^ (max>>j))
		{
		  nmin = max;
		  nmax = min;
		  if(a>>j & 1) 
		    {
		      for(int k = 0; k < b.size(); k++)
			{
			  if(b[k]) continue;
			  if(x[p+k]>>j & 1) b[k].flip();
			  else 
			    {
			      if(x[p+k] < nmin) nmin = x[p+k];
			      if(x[p+k] > nmax) nmax = x[p+k];
			    }
			}
		    }
		  else
		    {
		      for(int k = 0; k < b.size(); k++)
			{
			  if(b[k]) continue;
			  if(x[p+k]>>j & 1)
			    {
			      if(x[p+k] < nmin) nmin = x[p+k];
			      if(x[p+k] > nmax) nmax = x[p+k];
			    }
			  else b[k].flip();
			}
		    }
		  if(nmin == nmax) break;
		  max = nmax;
		  min = nmin;
		}
	    }
	  assert(nmax == nmin);
	  a ^= nmin;
	  printf("%hu\n", a);
	}
    }
  return 0;
}
