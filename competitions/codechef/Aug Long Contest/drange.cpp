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

int arr[1000002];
inline int read_int() {
  char c;
  while ((c=getchar_unlocked()) < 48 || c > 57);
  int p = c-48;
  while ((c=getchar_unlocked()) >= 48 && c <= 57) p=p*10+c-48;
  return p;
}

int main()
{
  int T, N, M;
  int w, x, y, z;
  T = read_int();
  // scanf("%d", &T);
  while(T--)
    {
      // scanf("%d %d", &N, &M);
      N = read_int();
      M = read_int();
      memset(arr, 0, sizeof(arr));
      while(M--)
	{
	  // scanf("%d %d %d %d", &w, &x, &y, &z);
	  w = read_int();
	  x = read_int();
	  y = read_int();
	  z = read_int();
	  if(w == 2) z *= -1;
	  arr[x] += z;
	  arr[y + 1] -= z;
	}
      long long min = arr[1] + 1, max = arr[1] + 1;
      z = arr[1];
      for(int i = 2; i <= N; i++)
	{
	  z += arr[i];
	  x = i + z;
	  if(x < min) min = x;
	  else if(x > max) max = x;
	}

      long long range = max;
      range -= min;
      printf("%lld\n", range);
    }
  return 0;
}
