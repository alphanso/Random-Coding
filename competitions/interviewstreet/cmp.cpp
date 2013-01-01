//==============================================================================
// Copyright (C) 2012 Rishabh Singhal <rinkusinghal05@gmail.com>

// cmp.cpp is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// cmp.cpp is distributed in the hope that it will be useful,
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

int main()
{
  int N;
  cin >> N;
  pair<ll, ll> p[N];
  
  FOR(i, 0, N)
    cin >> p[i].first >> p[i].second;
  sort(p, p+N);
  ll ans, index;
  FOR(i, 0, N)
    {
      ll M = 0;
      FOR(j, 0, N)
	M += max(abs(p[j].first - p[i].first), abs(p[j].second - p[i].second));
      if(i == 0) ans = M, index = 0;
      else if(M < ans) ans = M, index = i;
      cout << p[i].first << " " << p[i].second << " " << M << endl;
    }
  cout << endl;
  cout << p[index].first << " " << p[index].second << endl;
  cout << ans << endl;
  return 0;
}
