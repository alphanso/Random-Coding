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

class unionFind {
public:
  int K;
  int parent[2001];
  int rank[2001];
  unionFind(int K)
  {
    this->K = K; 
    FOR(i, 1, K+1)
      {
	parent[i] = i;
	rank[i] = 0;
      }
  }
  
  int find(int x)
  {
    if(parent[x] != x)
      parent[x] = find(parent[x]);
    return parent[x];
  }
  
  bool unionS(int x, int y)
  {
    int xroot = find(x);
    int yroot = find(y);
    if(xroot == yroot)
      return false;
    
    if(rank[xroot] < rank[yroot])
      parent[xroot] = yroot;
    else if(rank[xroot] > rank[yroot])
      parent[yroot] = xroot;
    else 
      {
	parent[yroot] = xroot;
	rank[xroot]++;
      }
    K--;
    return true;
  }
  
  int conn()
  {
    return K;
  }
};

int main()
{
  int T, N, M, K;
  scanf("%d", &T);
  vector< pair<int, pair<int, int> > > v; 
  multiset<int> ms;
  FOR(i,0,T)
    {
      int a, b, c;
      scanf("%d %d %d", &N, &M, &K);
      FOR(i, 0, M)
	{
	  scanf("%d %d %d", &a, &b, &c);
	  v.push_back(make_pair(c, make_pair(a, b)));
	}
      
      if(K >= N) 
	{
	  printf("0\n");
	}
      else
	{
	  unionFind UF(N);
	  sort(v.begin(), v.end());
	  int ans = 0;
	  FOR(i, 0, M)
	    {
	      if(UF.unionS(v[i].second.first, v[i].second.second)) 
		{
		  ans += v[i].first; 
		  ms.insert(v[i].first);
		}
	    }
	  int conn = UF.conn();
	  // cout << "reached here safely" << endl;
	  if(K < conn) printf("Impossible!\n");
	  else if(K == conn) printf("%d\n", ans);
	  else
	    {
	      int D = K - conn;
	      multiset<int>::reverse_iterator rit = ms.rbegin();
	      for(rit; rit != ms.rend() && D != 0; rit++, D--)
		ans -= *rit;
	      printf("%d\n", ans);
	    }
	}
    }
  return 0;
}
