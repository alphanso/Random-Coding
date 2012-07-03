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
  int N, i;
  set<ll> pos;
  ll A, prev, cpos, ppos = 66;
  bool flag1 = false, flag2 = false;
  string output = "No";

  scanf("%d", &N);  
  if(N > 66) 
    {
      while(N--)
	scanf("%lld", &A);
      printf("YES\n");
      return 0;
    }
  scanf("%lld", &prev);
  
  for(i = 1; i < N; i++)
    {
      scanf("%lld", &A);
      if(flag1 && flag2) break;
      cpos = A^prev;
      // cerr << cpos << endl;
      if(ppos == cpos)
	{
	  if(!flag1) flag1 = true;
	  else {flag2 = true; output = "Yes";}
	  ppos = 66;
	  prev = A;
	  continue;
	}
      if(pos.find(cpos) != pos.end())
	{
	  output = "Yes";
	  break;
	}
      pos.insert(cpos);
      prev = A;
      ppos = cpos;
    }
  
  for(int j = i  + 1; j < N; j++)
    scanf("%lld", &A);
  if(output == "Yes") printf("Yes\n");
  else printf("No\n");
  return 0;
}
      
