//==============================================================================
// Copyright (C) 2012 Rishabh Singhal <rinkusinghal05@gmail.com>

// newsch.c is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// newsch.c is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//==============================================================================

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <assert.h>
typedef long long ull;
const int mod = 1e9+7;
#define FOR(i, a, b) for(i = a; i < b; i++)

int solve(int N)
{
  ull a[] = {2,3,1,0};
  ull b[] = {1,0,0,1};
  ull c[2*2] = {}, *res, *m1, *m2, *temp; 
  res = c;
  m1 = b, m2 = a;
  int p = N - 3, i, j, k;
  while(p > 0)
    {
      if(p % 2)
	{
	  FOR(k, 0, 2) FOR(i, 0, 2) FOR(j, 0, 2)
	    res[i*2+j] += m1[i*2+k] * m2[k*2+j];
	  FOR(i, 0, 2) FOR(j, 0, 2)
	    if(res[i*2+j] >= mod) res[i*2+j] %= mod;
	  temp = res; res = m1; m1 = temp;
	  memset(res, 0, sizeof(ull)*4); 
	}
      FOR(k, 0, 2) FOR(i, 0, 2) FOR(j, 0, 2)
	res[i*2+j] += m2[i*2+k] * m2[k*2+j];
      FOR(i, 0, 2) FOR(j, 0, 2)
	if(res[i*2+j] >= mod) res[i*2+j] %= mod;
      temp = res; res = m2; m2 = temp;
      memset(res, 0, sizeof(ull)*4); 
      p /= 2;
    }
  ull ansl = 24*m1[0] + 12*m1[1];
  if(ansl >= mod) ansl %= mod;
  int ans = ansl;
  return ans;
}

int main()
{
  int T, N;
  scanf("%d", &T);

  while(T--)
    {
      scanf("%d", &N);
      if(N == 2) printf("12\n"); 
      else printf("%d\n", solve(N));
    }
  return 0;
}
