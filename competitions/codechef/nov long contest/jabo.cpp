//==============================================================================
// Copyright (C) 2012 Rishabh Singhal <rinkusinghal05@gmail.com>

// jabo.cpp is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// jabo.cpp is distributed in the hope that it will be useful,
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

inline int eval(char c)
{
  if('A' <= c && c <= 'Z') return (s[1] - 'A');
  else return ((s[1] - 'a') + 26);
}

int main()
{
  int N, R, C;
  scanf("%d %d %d", &N, &R, &C);
  char s[100];
  int board[R][C] = {0};
  int x1, y1, x2, y2;
  while(N--)
    {
      scanf("%s", s);
      switch(s[0])
	{
	case 'W':
	  {
	    x1 = eval(s[1])*52+eval(s[2]);
	    y1 = eval(s[3])*52+eval(s[4]);
	    x2 = eval(s[5])*52+eval(s[6]);
	    y2 = eval(s[7])*52+eval(s[8]);
	    cerr << x1 <<" " << y1 << " " x2 << " " y2 << endl;
	    break;
	  }
	case 'V':
	  {
	    x1 = eval(s[1])*52+eval(s[2]);
	    y1 = eval(s[3])*52+eval(s[4]);
	    cerr << x1 <<" " << y1 << endl;
	    break;
	  }
	case 'L':
	  {
	    x1 = eval(s[1])*52+eval(s[2]);
	    y1 = eval(s[3])*52+eval(s[4]);
	    x2 = eval(s[5])*52+eval(s[6]);
	    y2 = eval(s[7])*52+eval(s[8]);
	    cerr << x1 <<" " << y1 << " " x2 << " " y2 << endl;
	    break;
	  }
	case 'R':
	  {
	    x1 = eval(s[1])*52+eval(s[2]);
	    y1 = eval(s[3])*52+eval(s[4]);
	    cerr << x1 <<" " << y1 << endl;
	    break;
	  }
	}
    }
  return 0;
}
	
