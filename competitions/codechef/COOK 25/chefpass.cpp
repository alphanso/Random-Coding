//==============================================================================
// Copyright (C) 2012 Rishabh Singhal <rinkusinghal05@gmail.com>

// chefpass.cpp is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// chefpass.cpp is distributed in the hope that it will be useful,
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

int N, M;

string com[1000], p;
string noncom[1000];
bool usedcom[1000];
bool usednoncom[1000];

int main()
{
  int T;
  cin >> T;

  while(T--)
    {
      cin >> N >> M;
      FOR(i, 0, N)
	{
	  cin >> com[i];
	  usedcom[i] = false;
	}

      FOR(i, 0, M)
	{
	  cin >> M;
	  usednoncom[i] = false;
	}

      FOR(i, 0, N)
	{
	  if(usedcom[i]) p = com[i];
	  else continue;
	}
    }
  return 0;
}
