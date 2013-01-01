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

typedef long long ll;
typedef unsigned long long ull;
#define FOR(i, a, b) for(int i = a; i < b; i++)

map<string, int> mem;
 
int solve(string s)
{
  int ans = s.size(), N = s.size();
  if(ans == 1) return 1;
  string t;
  
  if((s[0] == 'a' && s[1] == 'b') ||
     (s[0] == 'b' && s[1] == 'a'))
    {
      t = s;
      t[i] = 'c';
      t.erase(i+1, 1);
      //cerr << t << endl;
      if(mem.find(t) != mem.end()) ans = min(ans, solve(t));
      else ans = min(ans, solve(t));
    }
  else if((s[i] == 'a' && s[i+1] == 'c') ||
	  (s[i] == 'c' && s[i+1] == 'a'))
    {
      t = s;
      t[i] = 'b';
      t.erase(i+1, 1);
      if(mem.find(t) != mem.end()) ans = min(ans, solve(t));
      else ans = min(ans, solve(t));
    }
  else if((s[i] == 'b' && s[i+1] == 'c') ||
	  (s[i] == 'c' && s[i+1] == 'b'))
    {
      t = s;
      t[i] = 'a';
      t.erase(i+1, 1);
      if(mem.find(t) != mem.end()) ans = min(ans, solve(t));
      else ans = min(ans, solve(t));
    }
  if(ans == 1) break;

  mem[s] = ans;
//cout << s << " " << ans << endl;
return ans;
}

int main()
{
  int T;
  scanf("%d", &T);
  string s;

  while(T--)
    {
      cin >> s;
      mem.clear();
      printf("%d\n", solve(s)); 
    }
  return 0;
}
