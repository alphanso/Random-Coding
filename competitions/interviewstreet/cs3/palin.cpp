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

#define FOR(i, a, b) for(int i = a; i < b; i++)

string str[100];
map<pair<int, int>, int> mSuff, mPref;
map<pair<int, int>, int>::iterator it;

int pPali(int r, int s, int e)
{
  pair<int, int> p(r, s);
  it = mPref.find(p);
  if(it != mPref.end())
    {
      return it->second;
    }
  else
    {
      while(str[r][s] != str[r][e] && s < e) e--;
      if(s == e) return 1;
      int x = s, y = e;
      while(str[r][x] == str[r][y] && x <= y) {x++; y--;}
      if(y > x) return pPali(r, s, e-1);
      mPref[p] = e - s + 1;
      return e - s + 1;
    }
}

int sPali(int r, int s, int e)
{
  pair<int, int> p(r, e);
  it = mSuff.find(p);
  if(it != mSuff.end())
    {
      return it->second;
    }
  else
    {
      while(str[r][s] != str[r][e] && s < e) s++;
      if(s == e) return 1;
      int x = s, y = e;
      while(str[r][x] == str[r][y] && x <= y) {x++; y--;}
      if(y > x) return sPali(r, s+1, e);
      mSuff[p] = e - s + 1;
      return e - s + 1;
    }
}

int main()
{
  int N, M;
  cin >> N >> M;
  int max = 0, suff, pref;
  for(int i = 0; i < N; i++)
    {
      cin >> str[i];
      suff = sPali(i, 0, M-1);
      pref = pPali(i, 0, M-1);
      if(max < suff) max = suff;
      if(max < pref) max = pref;
    }
  
  FOR(i, 0, N)
    {
      FOR(j, 0, N)
	{
	  if(i == j || str[i][0] != str[j][M-1]) continue;
      
	  int s = 0, e = M-1, c = 0;
	  while(str[i][s] == str[j][e] && s < M) {s++; e--;}
	  if(s == M && e == 0) 
	    {
	      cout << 2*M << endl;
	      return 0;
	    }
	  c = 2 * s;
	  suff = sPali(j, 0, e);
	  pref = pPali(i, s, M-1);
	  if(suff > pref) c += suff;
	  else c += pref;
      
	  if(c > max) max = c;
	}
    }
  cout << max << endl;
}
