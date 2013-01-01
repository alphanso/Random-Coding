//==============================================================================
// Copyright (C) 2012 Rishabh Singhal <rinkusinghal05@gmail.com>

// nocoding.cpp is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// nocoding.cpp is distributed in the hope that it will be useful,
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
  int T, in;
  string s;
  char c;
  cin >> T;

  while(T--)
    {
      cin >> s;
      in = 2;
      c = s[0];
      FOR(i, 1, s.size())
	{
	  if((s[i] - c) < 0) in += (26 + (s[i] - c));
	  else in += (s[i] - c);
	  c = s[i];
	  in++;
	}
      // cerr << in << " " << s.size() * 11 << endl;
      if(in > 11 * s.size()) cout << "NO" << endl;
      else cout << "YES" << endl;
    }
  return 0;
}
