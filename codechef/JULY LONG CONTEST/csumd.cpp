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
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
#define contain(S,X) (((S)&two(X))!=0)
#define containL(S,X) (((S)&twoL(X))!=0)
const double pi=acos(-1.0);
const double eps=1e-11;
template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}
template<class T> inline T sqr(T x){return x*x;}
typedef pair<int,int> ipair;
#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)
#define MOD 1000000007

ll modPow(ll a, ll x, ll p)
{
  ll res = 1;
  while(x > 0)
    {
      if(x % 2) res = (res * a) % p;
      a = (a * a) % p;
      x /= 2;
    }
  return res;
}

int main()
{
  int T, N;
  scanf("%d", &T);
  while(T--)
    {
      scanf("%d", &N);
      int c1 = N, c2 = 0, c = 1;
      ll ans = 0, inv2 = modPow(2, MOD - 2, MOD);
      c = modPow(2, c1 + c2 - 1, MOD);
      for(; c1 != -2 && c1 != -1; c1 -= 2)
	{
	  ans += c;
	  if(ans > MOD) ans %= MOD;
	  c2++;
	  c = (c * inv2) % MOD;
	  c = (c * (N - c2)) % MOD;
	  c = (c * modPow(c2, MOD - 2, MOD)) % MOD;
	  cerr << c << endl;
	}
      printf("%lld\n", ans);
    }
  return 0;
}
