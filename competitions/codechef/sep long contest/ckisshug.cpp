//==============================================================================
// Copyright (C) 2012 Rishabh Singhal <rinkusinghal05@gmail.com>

// ckisshug.cpp is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// ckisshug.cpp is distributed in the hope that it will be useful,
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
const int mod = 1e9 + 7;

long long powoftwo(int k)
{
  if(k == 1) return 2;
  long long temp = powoftwo(k / 2);
  if(temp > mod) temp %= mod;
  long long ans = temp * temp;
  if(k % 2)
    ans <<= 1;
  if(ans >= mod) ans %= mod;
  return ans;
}

int calc(int N)
{
  if(N == 1) return 2;
  if(N == 2) return 4;
  long long pow = powoftwo(N / 2);
  int ans;
  if(N % 2) 
    ans = (4 * pow - 2) % mod;
  else 
    ans = (3 * pow - 2) % mod;
  return ans;
}

int main()
{
  int T, N;
  cin >> T;

  while(T--)
    {
      cin >> N;
      cout << calc(N) << endl;
    }
  return 0;
}
