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
typedef pair<int, int> pii;
#define FOR(i, a, b) for(int i = a; i < b; i++)
const int mod = 1e9 + 7;

int main()
{
  int K;
  cin >> K;
  int P[K];
  FOR(i, 0, K)
    cin >> P[i];
  
  int mat[K][K];
  char c;
  FOR(i, 0, K)
    FOR(j, 0, K)
    {
      cin >>c;
      if(c == 'N') mat[i][j] = 0;
      else mat[i][j] = 1;
    }

  FOR(k, 0, K)
    FOR(i, 0, K)
    FOR(j, 0, K)
    mat[i][j] = (mat[i][j] || (mat[i][k] && mat[k][j]));
  
  // FOR(i, 0, K)
  //   {
  //     FOR(j, 0, K)
  // 	cout << mat[i][j] << " ";
  //     cout << endl;
  //   }
  int ans[K];
  
  vector<int> v, s;
  vector<bool> visited(K, false);
  FOR(i, 0, K)
    {
      if(visited[i]) continue;
      v.push_back(i);
      s.push_back(P[i]);
      FOR(j, i+1, K)
	if(mat[i][j]) {v.push_back(j); s.push_back(P[j]); visited[j]=true;}
      sort(s.begin(), s.end());
      FOR(j, 0, v.size())
	ans[v[j]] = s[j];
      v.clear();
      s.clear();
    }
  FOR(i, 0, K)
    cout << ans[i] << " ";
  cout << endl;
  return 0;
}
