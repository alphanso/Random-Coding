//==============================================================================
// Copyright (C) 2012 Rishabh Singhal <rinkusinghal05@gmail.com>

// candies.cpp is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// candies.cpp is distributed in the hope that it will be useful,
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
  cin >> N;
  
  int a[N];
  for(int i = 0; i < N; i++)
    cin >> a[i];

  int c[N], ans = 0;
  c[0] = 1;
  for(int i = 1; i < N; i++)
    {
      if(a[i] > a[i - 1])
	{
	  c[i] = c[i - 1] + 1;
	}
      else c[i] = 1;
    }

  for(int i = N - 2; i >= 0; i--)
    {
      if(a[i] > a[i + 1])
	{
	  c[i] = max(c[i + 1] + 1, c[i]);
	}
    }

  for(int i = 0; i < N; i++)
    ans += c[i];
  return 0;
}
