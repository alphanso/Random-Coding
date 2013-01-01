#include <iostream>

using namespace std;
typedef long long ll;
long long memFactorial[41];
long long memInvFactorial[41];
const int mod = 1e9 + 7;

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

void init()
{
  memFactorial[0] = 1;
  memFactorial[1] = 1;
  for(int i = 2; i <= 40; i++)
    {
      memFactorial[i] = memFactorial[i - 1] * i;
      if(memFactorial[i] > mod) memFactorial[i] %= mod;
    }

  memInvFactorial[0] = memInvFactorial[1] = 1;
  for(int i = 2; i < 40; i++)
    memInvFactorial[i] = modInverse(memFactorial[i], mod);
}

int choose(int n, int k)
{
  ll numerator = memFactorial[n];
  ll invDenominator = (memInvFactorial[k] * memInvFactorial[n - k]) % mod;
  return ((numerator * invDenominator) % mod);
}

int main()
{
  init();
  int T, N, total, r, a;
  cin >> T;
  
  while(T--)
    {
      cin >> N;
      total = (N * (N-1)) / 2; 
      r = 0;
      for(int i = 0; i < N; i++)
	{
	  cin >> a;
	  if(a == -1) r++;
	  else total -= a;
	}
      
      cout << choose(total + r - 1, r - 1) << endl;
    }
  return 0;
}
      
      
