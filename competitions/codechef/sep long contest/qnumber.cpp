//==============================================================================
// Copyright (C) 2012 Rishabh Singhal <rinkusinghal05@gmail.com>

// qnumber.cpp is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// qnumber.cpp is distributed in the hope that it will be useful,
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
typedef pair<ll, int> pli;
#define FOR(i, a, b) for(int i = a; i < b; i++)

ll gcd(ll a, ll b);
ll numFactors(ll a);
int factorize(ll a);
vector<pli> factors;
int main()
{
  int Q, T;
  ll N, K;
  scanf("%lld %d", &N, &Q);
  ll factor = factorize(N);
  // for(int i = 0; i < factors.size(); i++)
  //   cout << factors[i].first << " " << factors[i].second << endl;
  
  while(Q--)
    {
      scanf("%d %lld", &T, &K);
      if(T == 1)
  	{
  	  printf("%lld\n", numFactors(gcd(N, K)));
  	}
      else if(T == 2)
  	{
  	  if(N % K != 0) 
  	    printf("0\n");
  	  else
  	    printf("%lld\n", numFactors(N / K));
  	}
      else 
  	{
  	  if(N % K != 0)
  	    printf("%lld\n", factor);
  	  else
  	    printf("%lld\n", factor - numFactors(N / K));
  	}
    }
  return 0;
}

ll gcd(ll a, ll b)
{
  ll r;
  if(a < b) swap(a, b);
  r = a % b;
  if(r == 0) return b;
  else return gcd(b, r);
}

int factorize(ll N)
{
  if(!(N % 2))
    {
      N = N / 2;
      factors.push_back(make_pair(2, 1));
      while(!(N % 2))
	{
	  (factors[0].second)++;
	  N /= 2;
	}
    }
  if(!(N % 3))
    {
      N = N / 3;
      factors.push_back(make_pair(3, 1));
      while(!(N % 3))
	{
	  (factors[1].second)++;
	  N /= 3;
	}
    }
  int r1, r2;
  for(int i = 6; i - 1 < sqrt(N) && N > 1; i+=6)
    {
      r1 = i - 1;
      r2 = i + 1;
      if(!(N % r1))
	{
	  N = N / r1;
	  factors.push_back(make_pair(r1, 1));
	  while(!(N % r1))
	    {
	      (factors.back().second)++;
	      N /= r1;
	    }
	}
      if(!(N % r2))
	{
	  N = N / r2;
	  factors.push_back(make_pair(r2, 1));
	  while(!(N % r2))
	    {
	      (factors.back().second)++;
	      N /= r2;
	    }
	}
    }
  if(N != 1)
    factors.push_back(make_pair(N, 1));
  int factor = 1;
  for(int i = 0; i < factors.size(); i++)
    factor *= (factors[i].second + 1);
  return factor;
}

ll numFactors(ll a)
{
  int f[factors.size()];
  ll div;
  for(int i = 0; i < factors.size(); i++)
    {
      div = factors[i].first;
      f[i] = 1;
      while(!(a % div))
	{
	  f[i]++;
	  a /= div;
	}
    }
  ll ans = 1;
  for(int i = 0; i < factors.size(); i++)
    ans *= f[i];
  return ans;
}
