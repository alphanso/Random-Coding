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

int memminD[32] = {0};
int calcminD(int N)
{
  //cerr << N << endl;
  if(memminD[N] != 0) return memminD[N];
  else
    {
      int ans = N;
      if(N == 1) return 0;
      ans += (calcminD(N / 2) + calcminD(N - (N / 2)));
      memminD[N] = ans;
      // cerr << N << " " << ans << endl;
      return ans;
    }
}

int main()
{
  int T, N, M;
  scanf("%d", &T);
  int maxD, minD;
  while(T--)
    {
      scanf("%d %d", &N, &M);
      maxD = N + (N * (N + 1)) / 2;
      minD = calcminD(N + 1);
      cerr << maxD << " " << minD << endl;
      if(M > maxD) printf("%d\n", M - maxD);
      else if(M >= minD) printf("%d\n", 0);
      else printf("%d\n", -1);
    }
  return 0;
}
