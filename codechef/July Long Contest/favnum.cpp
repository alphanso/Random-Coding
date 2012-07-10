#include <iostream>   
#include <sstream>   
#include <cstdio>   
#include <cstdlib>   
#include <cmath>   
#include <memory.h>   
#include <cctype>   
#include <string>   
#include <vector>   
#include <list>   
#include <queue>   
#include <deque>   
#include <stack>   
#include <map>   
#include <set>   
#include <algorithm>
   
using namespace std;  
   
#define FOR(i,a,b) for(int (i) = (a); (i) < (b); ++(i))  
#define RFOR(i,a,b) for(int (i) = (a)-1; (i) >= (b); --(i))  
#define CLEAR(a) memset((a),0,sizeof(a))  
#define INF 1000000000
#define PB push_back  
#define ALL(c) (c).begin(), (c).end()  
#define pi 2*acos(0.0)  
#define SQR(a) (a)*(a)  
#define MP make_pair  
   
typedef long long ll;

int main()
{
  ll K;
  int N, j;
  string l, r;
  cin >> l >> r >> K >> N;
  string s[N];
  FOR(i, 0, N)
    cin >> s[i];
  
  if(l.size() != r.size())
    {
      int diff = r.size() - l.size();
      for(int k = 0; k < diff; k++)
	l = "0" + l;
    }

  int sz = l.size();
  RFOR(k, sz, 0)
    {
      char c = l[k];
      l[k] = '9';
      j = k;
      if(l >= r)
	{
	  l[k] = c;
	  break;
	}
      cerr << l << endl;
    }
  
  for(int k = (l[j] - '0') + 1; k < (r[j] - '0'); k++)
    {
      l[j] = (char)(k + '0');
      cerr << l << endl;
    }
  l[j] = r[j];
  FOR(k, j + 1, sz)
    l[k] = '0';
  cerr << l << endl;
  FOR(k, j + 1, sz)
    {
      l[k] = r[k];
      cerr << l << endl;
    }
  return 0;
}
