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

int B[50000];

int main()
{
  int T, n, d;
  float P;
  scanf("%d", &T);
  multiset<typePair> s;
  double ans = 0.0000;

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
	  // multiset<typePair>::iterator p = 
	  s.insert(create_pair(B[i], P / 100.00));
	  // multiset<typePair>::iterator lb = s.upper_bound(create_pair(B[i] - d, 0));
	  // multiset<typePair>::iterator ub = s.lower_bound(create_pair(B[i] + d, 0));
      	  multiset<typePair>::reverse_iterator rit = s.rbegin();
	  bool once = true;

	  // cerr << p->B << " " << p->P << endl;
	  // cerr << lb->B << " " << lb->P << endl;
	  // if(ub == s.end()) cerr << "END" << endl; 
	  // else cerr << ub->B << " " << ub->P << endl;

	  // for(it = lb; it != p; it++)
	  //   ans += (it->P * (100 - p->P)) / 10000.0000; 
	  
	  // for(it++; it != s.end() && it != ub; it++)
	  //   ans += 1 - (((100 - it->P) * p->P) / 10000.0000);
	 
	  // for(it; it != s.end(); it++)
	  //   ans += 1;
	  // cerr << ans << endl;
	  P = P / 100.00;
	  for(rit; rit != s.rend(); ++rit)
	    {
	      if(rit->B == B[i] && rit->P == P && once) {once = false; continue;}
	      if(rit->B > B[i] + d) ans += 1;
	      else if(rit->B <= B[i] + d && rit->B > B[i]) ans += (1 - P * (1 - rit->P));
	      else if(rit->B <= B[i] && rit->B > B[i] - d) ans += ((1 - P) * (rit->P));
	      else break;
	      // cerr << rit ->P << " " << P << endl;
	    }
	  // cerr << ans << endl;
	}

      printf("%0.4f\n", ans);
      s.clear();
      ans = 0.0000;
    }
  return 0;
}
