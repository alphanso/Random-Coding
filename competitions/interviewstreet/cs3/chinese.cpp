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
#define FOR(i, a, b) for(int i = a; i < b; i++)

pair<int, int> divide(int a, int b)
{
  int q = a / b;
  int r = a - b * q;
  return make_pair(q, r);
}

pair<int, int> extendedGCD(int a, int b)
{
  if(a < b) swap(a, b);
  if(b == 0)
    return make_pair(1, 0);
  else
    {
      pair<int, int> qr = divide(a, b);
      pair<int, int> st = extendedGCD(b, qr.second);
      return make_pair(st.second, st.first - qr.first * st.second);
    }
}

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

ll modInverse(ll a, ll p)
{
 return modPow(a, p-2, p);
}

int factmod (int n, int p) {
  long long res = 1;
  while (n > 1) {
    long long cur = 1;
    for (int i=2; i<p; ++i)
      cur = (cur * i) % p;
    res = (res * modPow (cur, n/p, p)) % p;
    for (int i=2; i<=n%p; ++i)
      res = (res * i) % p;
    n /= p;
  }
  return int (res % p);
}

int powP(int n, int p)
{
  int ans = 0;
  int q = n , d = p;
  while(q != 0)
    {
      ans += (n / d);
      q = n / d;
      d *= p;
    }
  return ans;
}

int factmod3(int n)
{
  long long res = 1, j;
  while (n > 1) {
    long long cur = 1;
    for (int i=2; i<27; ++i)
      {
	if(!(i%9)) j = i / 9;
	else if(!(i % 3)) j = i / 3;
	else j = i;
	cur = (cur * j) % 27;
      }
    //cout << "Here " << n << endl;
    res = (res * modPow (cur, n/27, 27)) % 27;
    for (int i=2; i<=n%27; ++i)
      {
	if(!(i%9)) j = i / 9;
	else if(!(i % 3))  j = i / 3;
	else j = i;
	res = (res * j) % 27;
      }
    n /= 27;
  }
  return int ((res) % 27);
} 

int ch(int n, int k, int p, int r)
{
  int numPow = powP(n, p);
  int denPow = powP(k,p) + powP(n - k, p);
  cout << numPow << " " << denPow << endl;
  if(numPow > denPow && (numPow - denPow) > r-1) return 0;
  else
    {
      ll numerator = factmod3(n);
      cout << numerator << endl;
      ll denominator = factmod3(k);
      cout << denominator << endl;
      denominator = (factmod3(n-k) * denominator) % 27;
      cout << denominator << endl;
      int pow = numPow - denPow;
      if ( pow == 0) pow = 1;
      else if(pow == 1) pow = 3;
      else pow = 9;
      cout << pow << endl;
      denominator = modPow(denominator, 17, 27);
      cout << denominator << endl;
      numerator = (pow * numerator) % 27;
      return ((numerator * denominator) % 27);
    }
  
}

int choose(int n, int k, ll p)
{
  int numPow = powP(n, p);
  int denPow = powP(k, p) + powP(n - k, p);
  //cout << numPow << " " << denPow << endl;
  assert(numPow >= denPow);
  if(numPow > denPow) return 0;
  else
    {
      ll numerator = factmod(n, p);
      ll denominator = factmod(k, p);
      denominator = (factmod(n-k, p) * denominator) % p;
      denominator = modInverse(denominator, p);
      
      return ((numerator * denominator) % p);
    }
}

int main()
{
  int M = 142857;
  int P1 = 13, P2 = 11, P3 = 37, P4 = 27;
  int M1 = M/P1, M2 = M/P2, M3 = M/P3, M4 = M/P4;
  int e1 = extendedGCD(M1, P1).first*M1;
  int e2 = extendedGCD(M2, P2).first*M2;
  int e3 = extendedGCD(M3, P3).first*M3;
  int e4 = extendedGCD(M4, P4).first*M4;
  int power = 77760;
  int n, r, t;
  cin >> t;
  FOR(i, 0, t)
    {
      cin >> n >> r;
      //cout << e1 << " " << e2 << " " << e3 << " " << e4 << endl;
      int x1, x2, x3, x4;
      x1 = choose(n, r, P1);
      x2 = choose(n, r, P2);
      x3 = choose(n, r, P3);
      cout << x1 << " " << x2 << " " << x3 << endl;
      x4 = ch(n, r, 3, 3);
      cout << x4 << endl;
      ll ans = x1 * e1 + x2 * e2 + x3 * e3 + x4 * e4;
      cout << ans << endl;
      while(ans < 0)
	ans += M;
      if(ans > M) ans %= M;
      cout << ans << endl;
    }
  return 0;
}
