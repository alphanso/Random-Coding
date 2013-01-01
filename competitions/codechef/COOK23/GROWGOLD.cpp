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
 
typedef long long int64;
typedef unsigned long long uint64;
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
const uint64 LIM = 100 * sqr(1e8 + 7);
 
class matrix {
private:
  int r, c;
  uint64** data;
public:
  //constructors
  
  //1. void
  matrix(){}
  
  //2. for linear dependence on k previous values
  matrix(int r, int c)
  {
    this->c = c;
    this->r = r;
    data = new uint64*[r];
    for(int i = 0; i < r; i++)
      data[i] = new uint64[c];

    for(int i = 0; i < c; i++)
      data[0][i] = 1;

    for(int i = 1; i < r; i++)
      	data[i][i-1] = 1;
  }
  
  //3. Identity matrix
  matrix(int K)
  {
    this->c = K;
    this->r = K;
    this->data = new uint64*[K];
    for(int i = 0; i < K; i++)
      this->data[i] = new uint64[K];
    
    for(int i = 0; i < K; i++)
      for(int j = 0; j < K; j++)
	if(i == j) data[i][j] = 1;
	else data[i][j] = 0;
  }

  int getRow()
  {
    return this->r;
  }
  
  int getColumn()
  {
    return this->c;
  }

  int getValue(int r, int c)
  {
    return data[r][c];
  }
 
  void setEqual(matrix a)
  {
    for(int i = 0; i < r; i++)
      for(int j = 0; j < c; j++)
	data[i][j] = a.getValue(i, j);
  }
    
  void mult(matrix m1, matrix m2)
  {
    memset(data, 0, sizeof(r * c * sizeof(uint64)));
    
    for(int i = 0; i < r; i++)
      for(int j = 0; j < c; j++)
	for(int k = 0; k < r; k++)
	  data[i][j] += m1.getValue(r, k) * m2.getValue(k, c);
  }

  void mult(matrix m1, matrix m2, uint64 mod)
  {
    for(int i = 0; i < r; i++)
      for(int j = 0; j < c; j++)
	data[i][j] = 0;

    for(int i = 0; i < r; i++)
      for(int j = 0; j < c; j++)
	for(int k = 0; k < r; k++)
	  {
	    data[i][j] +=(m1.getValue(i, k) * m2.getValue(k, j));
	    if(data[i][j] > LIM) data[i][j] %= mod;
	  }
  }
};

void print(matrix a)
{
  for(int i = 0; i < a.getRow(); i++)
    {
      for(int j = 0; j < a.getColumn(); j++)
	cout << a.getValue(i, j) << " ";
      cout << endl;
    }
}

matrix mmodPow(matrix a, int pow, int MOD)
{
  matrix res(a.getRow());
  matrix t(a.getRow());
  while(pow > 0)
    {
      if(pow % 2) 
	{
	  t.mult(res, a, MOD);
	  res.setEqual(t);
	  pow--;
	}
      if(!pow) break;
      t.mult(a, a, MOD);
      a.setEqual(t);
      pow /= 2;
    }
  //print(res);
  return res;
}

uint64 modPow(uint64 a, uint64 x, uint64 p)
{
  uint64 res = 1;
  while(x > 0)
    {
      if(x % 2) res = (res * a) % p;
      a = (a * a) % p;
      x /= 2;
    }
  return res;
}

int solve(int initT, int s1, int s2, int K, int N)
{
  const int MOD = 100000007;
  int j = 0;
  int64 recent[1+s1+s2];
  
  recent[j++] = initT;
  
  for(j; j < s1 + 1 && j != N; j++)
    recent[j] = recent[j - 1] + 1;
  
  for(j; j < s1 + s2 + 1 && j != N; j++)
    recent[j] = (recent[j - 1] << 1);
      
  // cerr << j << " " << N << endl;
  if(j == N) return recent[j - 1] % MOD;
  else 
    {
      int matpow = N - (1 + s1 + s2);
      int ans = 1;
      matrix a(K, K);
      a = mmodPow(a, matpow, MOD - 1);
      for(int i = 0; i < K; i++)
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
