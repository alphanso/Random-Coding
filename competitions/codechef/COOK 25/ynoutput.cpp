//==============================================================================
// Copyright (C) 2012 Rishabh Singhal <rinkusinghal05@gmail.com>

// ynoutput.cpp is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// ynoutput.cpp is distributed in the hope that it will be useful,
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
  int T;
  string sol[100];
  string s;
  scanf("%d", &T);

  FOR(i, 0, T)
    {
      sol[i] = "";
      FOR(j, 0, T)
	{
	  cin >> s;
	  if(s == "YES") sol[i] = sol[i] + "1";
	  else sol[i] = sol[i] + "0";
	}
      // cout << sol[i] << endl;
    }
  int j, i;
  for(i = 0; i < T; i++)
    {
      // cout << i << endl;
      // cout << sol[i][i] << endl;
      if(sol[i][i] != '1') continue;
      for(j = 0; j < T; j++)
	if(sol[i][j] == '1' && sol[j] != sol[i]) break;
	else if(sol[i][j] == '0' && sol[j] == sol[i]) break;
      // cout << j << endl;
      if(j == T) break;
    }
  // cerr << i << " " << j << endl;
  if(i != T) 
    {
      FOR(k, 0, T)
	{
	  if(sol[i][k] == '1') printf("YES\n");
	  else printf("NO\n");
	}
    }
  else 
    {
      FOR(k, 0, T)
	{
	  printf("NO\n");
	}
    }
  return 0;
}
