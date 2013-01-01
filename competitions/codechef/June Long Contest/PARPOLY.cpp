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

using namespace std;

typedef long long ll;

ll modPow(ll base, ll exp, ll mod)
{
  ll res = 1;
  while(exp > 0)
    {
      if(exp % 2) res = (res * base) % mod;
      base = (base * base) % mod;
      exp /= 2;
    }
  return res;
}

ll calc(const int k, const int D, ll C[], const int mod)
{
  int res = 0;
  for(int i = 0; i <= D; i++)
    res += ((C[i] * modPow(k, i, mod)) % mod);
  return res % mod;
}

void partInt(ll P[], int N, int M)
{
  ll res = 0;
  int X = min(M, N);
  int a[X], i, k, y, x, l;
  int q = N / M, r = N % M;
  
  for(i = 0; i < X - r; i++)
    a[i] = q;
  
  for(i; i < X; i++)
    a[i] = q + 1;
  k = X - 1;
  
  for(i = 0; i < X; i++)
    cerr << a[i] << " ";
  cerr << endl;
  y = a[k] - 1;
  while(k != 0)
    {
      x = a[k - 1] + 1;
      k -= 1;
      while(2 * x <= y)
	{
	  a[k] = x;
	  y -= x;
	  k += 1;
	}
      l = k + 1;
      while(x <= y)
	{
	  a[k] = x;
	  a[l] = y;
	  for(i = 0; i < k + 2; i++)
	    cerr << a[i] << " ";
	  for(i; i < X; i++)
	    cerr << 0 << " ";
	  cerr << endl;
	  x += 1;
	  y -= 1;
	}
      a[k] = x + y;
      y = x + y - 1;
      for(i = 0; i < k + 1; i++)
	cerr << a[i] << " ";
      for(i; i < X; i++)
	cerr << 0 << " ";
      cerr << endl;
    }

}

int main()
{
  int T, M, N, D;
  ll* C, X;
  ll* P;
  const int mod = 1000000007;

  scanf("%d", &T);
  while(T--)
    {
      scanf("%d %d %lld", &M, &N, &X);
      scanf("%d", &D);
    
      C = new ll[D + 1];
      
      for(int i = 0; i <= D; i++)
	scanf("%lld", C + i);

      for(int i = 0; i <= D; i++)
	C[i] = (C[i] * modPow(X, i, mod)) % mod;

      if(M == 1)
	{
	  cout << calc(N, D, C, mod) << endl;
	}
      else 
	{
	  P = new ll[N + 1];
	  
	  for(int i = 0; i <= N; i++)
	    P[i] = calc(i, D, C, mod);
	  
	  partInt(P, N, M);
	}
    }
  
  return 0;
}
