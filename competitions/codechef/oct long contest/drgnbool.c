//==============================================================================
// Copyright (C) 2012 Rishabh Singhal <rinkusinghal05@gmail.com>

// drgnbool.c is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// drgnbool.c is distributed in the hope that it will be useful,
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

int IL[101], FL[101];
int main()
{
  int T, N, M, C, L, ans, i;
  scanf("%d", &T);

  while(T--)
    {
      memset(IL, 0, sizeof(IL));
      memset(FL, 0, sizeof(FL));
      ans = 0;
      scanf("%d %d", &N, &M);
      for(i = 0; i < N; i++)
	{
	  scanf("%d %d", &C, &L);
	  IL[L] += C;
	}
      for(i = 0; i < M; i++)
	{
	  scanf("%d %d", &C, &L);
	  FL[L] += C;
	}
      for(i = 1; i < 101; i++)
	if(IL[i] < FL[i]) ans += FL[i] - IL[i];
      printf("%d\n", ans);
    }
  return 0;
}
