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

void print(multiset<int> m)
{
  while(!m.empty())
    {
      cout << *(m.begin()) << " ";
      m.erase(m.begin());
    }
  cout << endl;
}

int main()
{
  multiset<int> m;
  multiset<int>::reverse_iterator rit;
  int N, x, s, i = 0;
  scanf("%d", &N);
  while(N--)
    {
      scanf("%d", &s);
      if(s == 1)
	{
	  scanf("%d", &x);
	  i++;
	  m.insert(x);
	  if(i == 3) rit = m.rbegin();
	  else if(!(i % 3) ) rit++;
	  if(i > 3 && x > *rit) rit--;
	  print(m);
	}
      else
	{
	  if(i < 3) printf("No reviews yet\n");
	  else printf("%d\n", *(rit));
	}
    }
  return 0;
}
	  
  
