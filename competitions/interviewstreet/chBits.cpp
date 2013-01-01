//==============================================================================
// Copyright (C) 2012 Rishabh Singhal <rinkusinghal05@gmail.com>

// chBits.cpp is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// chBits.cpp is distributed in the hope that it will be useful,
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
  int N, Q, idx, x;
  cin >> N >> Q;
  string s;
  cin >> s;
  bitset<100005> A;
  for(int i = 0; i < N; i++)
    if(s[i] == '1') A.flip(i);
  cin >> s;
  bitset<100005> B;
  for(int i = 0; i < N; i++)
    if(s[i] == '1') B.flip(i);
  
  while(Q--)
    {
      cin >> s;
      if(s == "set_a")
	{
	  cin >> idx >> x;
	  A[idx] = x;
	}
      else if(s == "set_b")
	{
	  cin >> idx >> x;
	  B[idx] = x;
	}
      else 
	{
	  cin >> idx;
	  if(idx > N) cout << "0";
	  else 
	    {
	      int ans = A[0] ^ B[0], c = A[0] & B[0];
	      for(int i = 1; i <= idx; i++)
		{
		  ans = (c + A[i] + B[i]) % 2;
		  c = (c + A[i] + B[i]) / 2;
		}
	      cout << ans;
	    }
	}
    }
  return 0;
}
