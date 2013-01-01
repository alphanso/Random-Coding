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
#include <cassert>

using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
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

class cbuffer {
  vector<string> v;
  int N;
  
public:
  cbuffer(int n)
  {
    N = n;
  }

  int insert(string s)
  {
    if(v.size() == N)
      v.erase(v.begin());
    v.push_back(s);
    return v.size();
  }
  
  void remove(int n)
  {
    v.erase(v.begin(), v.begin() + n);
  }

  void list()
  {
    for(int i = 0; i < v.size(); i++)
      cout << v[i] << endl;
  }
};

int main()
{
  int N, c;
  string s;
  cin >> N;
  cbuffer cb(N);
  cin >> s;

  while(s != "Q")
  {
    if(s == "A")
      {
	cin >> c;
	for(int i = 0; i < c; i++)
	  {
	    cin >> s;
	    cb.insert(s);
	  }
      }
    else if(s == "L")
      {
	cb.list();
      }
    else if(s == "R")
      {
	cin >> c;
	cb.remove(c);
      }
    else assert(1 != 1);
    cin >> s;
  }
  return 0;
}
