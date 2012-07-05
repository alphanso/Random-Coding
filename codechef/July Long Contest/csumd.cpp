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
#define MOD 1000000007

ll mem[1000001] = {0};
map<int, ll> mem2;
const ll inv2 = 500000004;

ll calc(int N)
{
  if(N > 1000000)
    {
      ll ans;
      if(mem2.find(N) == mem2.end())
	{
	  int Y = N - 2;
	  ans = calc(N / 2) * calc(N - N / 2) + 2 * calc(Y / 2) * calc(Y - Y / 2);
	  if(ans > MOD) 
	    ans %= MOD;
	  mem2[N] = ans;
	}
      // cerr << N << " " << ans << endl;
      return mem2[N];
    }
  else return mem[N];
}

int main()
{
  int T, N, Y;
  scanf("%d", &T);
  mem[1] = 2;
  mem[2] = 6;
  mem[3]= 16;
  for(int i = 4; i < 1000001; i++)
    {
      Y = i - 2;
      mem[i] = mem[i/2] * mem[i - i / 2] + 2 * mem[Y / 2] * mem[Y - Y / 2];
      if(mem[i] > MOD) mem[i] %= MOD;
    }
  while(T--)
    {
      scanf("%d", &N);
      printf("%lld\n", (calc(N) * inv2) % MOD);
    }
  return 0;
}
