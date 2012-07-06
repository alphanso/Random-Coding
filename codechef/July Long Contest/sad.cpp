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
   
typedef long long Int;  

int main()
{
  int R, C;
  scanf("%d %d", &R, &C);
  int M[R][C];
  int ColL[100] = {0}, RowS[100];
  fill(RowS, RowS + R, INF);
  FOR(r, 0, R)
    {
      FOR(c, 0, C)
	{
	  scanf("%d", &M[r][c]);
	  if(M[r][c] > ColL[c]) ColL[c] = M[r][c];
	  if(M[r][c] < RowS[r]) RowS[r] = M[r][c];
	}
    }
  sort(ColL, ColL + C);
  sort(RowS, RowS + R);
  vector<int> v(100, 0);
  set_intersection(ColL, ColL + C, RowS, RowS + R, v.begin());
  if(v[0]) printf("%d\n", v[0]);
  else printf("GUESS\n");
  
  return 0;
}

