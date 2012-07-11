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

class typePair
{
public:
  int B;
  float P;
};

typePair create_pair(int B, float P)
{
  typePair ret;
  ret.B = B;
  ret.P = P;
  return ret;
}

bool operator < (typePair a, typePair b)
{
  return a.B < b.B;
}

void print(multiset<typePair> s)
{
  for(multiset<typePair>::iterator it = s.begin(); it != s.end(); it++)
    cout << "(" << it->B << ", " << it->P << ") ";
  cout << endl;
}

int B[50000];

int main()
{
  int T, n, d;
  float P;
  multiset<typePair> s;
  multiset<typePair>::reverse_iterator rit;
  double ans = 0.0000;

  scanf("%d", &T);
  while(T--)
    {
      scanf("%d %d", &n, &d);

      for(int i = 0; i < n; i++)
	scanf("%d", B + i);
      
      scanf("%f", &P);
      
      s.insert(create_pair(B[0], P / 100.00));
      for(int i = 1; i < n; i++)
	{
	  scanf("%f", &P);
	  P = P / 100.00;
      	  rit = s.rbegin();
	  
	  while(rit->B > B[i] + d && rit != s.rend()) {ans++; ++rit;}
	  while(rit->B > B[i] && rit != s.rend()) {ans += 1 - (P * (1 - rit->P)); ++rit;}
	  s.insert(rit.base(), create_pair(B[i], P));
	  rit++;
	  while(rit->B > B[i] - d && rit != s.rend()) {ans += ((1 - P) * (rit->P)); ++rit;}

	}
      
      printf("%0.4f\n", ans);
      s.clear();
      ans = 0.0000;
    }
  return 0;
}
