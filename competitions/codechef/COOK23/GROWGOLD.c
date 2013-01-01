#include <stdio.h>

typedef unsigned long long uint64;

#define rep(i, n) for(i = 0; i < n; i++)
const uint64 LIM = ((1 << 63) + ((1 << 63) - 1)) / (1e8+7);

typedef struct {
  int r;
  int c;
  uint64** data;
} matrix;

void matrixCreate(matrix* a, int r, int c)
{
  a->r = r;
  a->c = c;
  a->data = (uint64**) calloc(r, sizeof(uint64*));
  int i;
  for(i = 0; i < r; i++)
    a->data[i] = (uint64*) calloc(c, sizeof(uint64));
}

void setIdentityMatrix(matrix* a)
{
  int i, j;
  rep(i, a->r) rep(j, b->c)
    if(i == j) a->data[i][j] = 1;
    else a->data[i][j] = 0;
}

void matrixmult(matrix* res, matrix* a, matrix* b, int MOD)
{
  int i, j, k;
  rep(i, a->r) rep(j, b->c) rep(k, a->c)
    { 
      res->data[i][j] += (a->data[i][k] * b->data[k][j]);
      if(LIM < res->data[i][j]) res->data[i][j] %= MOD;
    }
}


void matrixModPow(matrix* res, matrix* a, int pow, int MOD)
{
  setIdentityMatrix(res);
  matrix t1, t2;
  matrixCreate(&t1, a->r, a->c);
  matrixCreate(&t2, a->r, a->c);
  while(pow > 0)
    {
      if(pow % 2)
	{
	  matrixmult(
}

int solve(int initT, int s1, int s2, int K, int N)
{
  const int MOD = 100000007;
  int j = 0;
  uint64 recent[1+s1+s2];
  
  recent[j++] = initT;
  
  for(j; j < s1 + 1 && j != N; j++)
    recent[j] = recent[j - 1] + 1;
  
  for(j; j < s1 + s2 + 1 && j != N; j++)
    recent[j] = (recent[j - 1] << 1);
      
  if(j == N) return recent[j - 1] % MOD;
  else 
    {
      int i, matpow = N - (1 + s1 + s2), ans = 1;
      matrix a;
      a = mmodPow(a, matpow, MOD - 1);
      for(i = 0; i < K; i++)
	ans = (ans * modPow(recent[s1 + s2 - i], a.getValue(0, i), MOD)) % MOD;
      return ans;
    }
}

int main()
{
  int T;
  int initT;
  int slot1, slot2;
  int K, N;
  scanf("%d", &T);
  
  while(T--)
    {
      scanf("%d %d %d %d %d", &initT, &slot1, &slot2, &K, &N);
      printf("%d\n", solve(initT, slot1, slot2, K, N));
    }
  return 0;
}

