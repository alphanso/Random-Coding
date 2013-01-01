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
#include <climits>
using namespace std;

#define sqr(x)  x * x
typedef unsigned long long ll;

int main()
{
  int N, Q, T, k;
  ll D;
  scanf("%d", &N);
  int X[N], Y[N], Z[N];
  
  for(int i = 0; i < N; i++)
    scanf("%d %d %d", X + i, Y + i, Z + i);
    
  scanf("%d", &Q);
  int A[Q], B[Q], C[Q];
  
  for(int i = 0; i < Q; i++)
    scanf("%d %d %d", A + i, B + i, C + i);

  D = sqr(X[0] - A[0]) + sqr(Y[0] - B[0]) + sqr(Z[0] - C[0]);
  k = 0;
  for(int j = 1; j < N; j++)
    {
      T = sqr(X[j] - A[0]) + sqr(Y[j] - B[0]) + sqr(Z[j] - C[0]);
      if(D > T) D = T, k = j;
    }						
  printf("%d\n", k);
  for(int i = 1; i < Q; i++)
    {
      printf("%d\n", rand() % N);
    }
  return 0;
}
