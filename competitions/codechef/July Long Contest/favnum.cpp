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

vector<string> s(N);
ll count(string S, int d, int ld)
{
  FOR(i, 0, N)
    if(S.size() && S.find(s[i]) != string::npos)
      return (9 - ld) * pow(10.0, d);
  int ans = 0;
  FOR(i, 0, N)
    {
      int sz = s[i].size();
      if(d > sz) ans += 
    }
}

void reduce()
{
  sort(ALL(s));
  FOR(i, 0, N)
    FOR(j, i+1, N)
    if(s[j].find(s[i]) != string::npos) s.erase(s.begin() + (j--));
}

int main()
{
  ll K;
  int N, j;
  string l, r;
  
  cin >> l >> r >> K >> N;
  FOR(i, 0, N)
    cin >> s[i];

  reduce();
  FOR(i, 0, N)
    if(l.find(s[i]) != string::npos) K--;
  if(!K) cout << l << endl;
  if(l.size() != r.size())
    {
      int diff = r.size() - l.size();
      for(int k = 0; k < diff; k++)
	l = "0" + l;
    }

  int sz = l.size();
  
  RFOR(k, sz, 0)
    {
      int c = l[k] - '0';
      l[k] = '9';
      j = k;
      if(l >= r)
	{
	  l[k] = (char)(c + '0');
	  break;
	}
      K -= count(l.substr(0, k - 1), sz-1-k , l[k]);
      if(k <= 0) call();

      cerr << l << " " << (9 - c) * pow(10.0, sz - 1 - k) << endl;
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
