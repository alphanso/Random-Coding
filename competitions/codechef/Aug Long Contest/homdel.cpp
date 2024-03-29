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

int main()
{
  int N, M, S, G, D;
  int tt, ts;
  scanf("%d", &N);
  int T[N][N];
  for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++)
      scanf("%d", &T[i][j]);
  
  for(int k = 0; k < N; k++) 
    for(int i = 0; i < N; i++)
      for(int j = 0; j < N; j++)
	T[i][j] = min(T[i][k] + T[k][j], T[i][j]);

  // for(int i = 0; i < N; i++)
  //   {
  //     for(int j = 0; j < N; j++)
  // 	cerr << T[i][j] << " ";
  //     cerr << endl;
  //   }

  scanf("%d", &M);
  while(M--)
    {
      scanf("%d %d %d", &S, &G, &D);
      tt = T[S][G] + T[G][D];
      ts = tt - T[S][D];
      printf("%d %d\n", tt, ts);
    }
  return 0;
}
