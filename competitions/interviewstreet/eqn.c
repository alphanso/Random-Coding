#include <stdio.h>

long long int mem[100001];
const int mod = 1000007;

void init()
{
  mem[0] = 1;
  mem[1] = 2;
  mem[2] = 4;
  int i;
  for(i = 3; i <= 1e5; i++)
    {
      mem[i] = mem[i / 2] * mem[i - (i / 2)];
      if(mem[i] > mod) mem[i] %= mod;
    }
}

long long calc(int S)
{
  if(S > 1e5)
    {
      long long ans = calc(S / 2) * calc(S - (S / 2));
      if(ans > mod) ans %= mod;
      return ans;
    }
  else return mem[S];
}

int main()
{
  int N;
  scanf("%d", &N);
  init();
  long long ans = calc(N - 2) * (calc(N - 1) - 1) + 1;
  ans %= mod;
  printf("%lld\n", ans);
  return 0;
}
