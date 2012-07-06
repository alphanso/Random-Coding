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
#define INF 1000000001
#define PB push_back  
#define ALL(c) (c).begin(), (c).end()  
#define pi 2*acos(0.0)  
#define SQR(a) (a)*(a)  
#define MP make_pair  
   
typedef long long Int;  

int main()
{
  int N, K;
  scanf("%d %d", &N, &K);
  set<int> sN;
  int num[N], count = 0;
  bool flag = false;
  FOR(i, 0, N)
    {
      if(i - K >= 0) flag = true;
      if(flag && num[i - K]) sN.erase(num[i - K]);
      scanf("%d", num + i);
      if(sN.find(num[i]) == sN.end()) 
	{
	  count++;
	  // cerr << num[i] << endl;
	  sN.insert(num[i]);
	}
      else num[i] = 0;
    }
  
  printf("%d\n", count);
  return 0;
}
