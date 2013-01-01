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

int main()
{
  int T, N, c;
  ll count[10], count2[19], count3[28], ans;
  const int mod = 1e9 + 7;
  char str[10001];
  scanf("%d", &T);
  // cout << mod << endl;
  while(T--)
    {
      memset(count, 0, sizeof(count));
      memset(count2, 0, sizeof(count2));
      memset(count3, 0, sizeof(count3));
      scanf("%s", str);
      ans = 0;
      N = strlen(str);
      
      for(int i = 0; i < N; i++)
	{
	  c = str[i] - '0';
	  if(c == 9)
	    {
	      ans++;
	      ans += count[9];
	      ans += count2[18];
	      ans += count3[27];
	    }
	  ans += count[9 - c];
	  ans += count2[9 - c];
	  ans += count2[18 - c];
	  ans += count3[9 - c];
	  ans += count3[18 - c];
	  ans += count3[27 - c];
	  
	  if(ans > 1e18) ans %= mod;
	  
	  for(int i = 0; i < 19; i++)
	    {
	      count3[i + c] += count2[i];
	      // if(count3[i + c] > 1e18) count3[i + c] %= mod;
	    }

	  for(int i = 0; i < 10; i++)
	    {
	      count2[i + c] += count[i];
	      //if(count2[i + c] > 1e18) count2[i + c] %= mod;
	    }

	  count[c]++;
	  // cout << c << " " << ans << endl;
	}
      printf("%lld\n", ans % mod);
    }
  return 0;
}
