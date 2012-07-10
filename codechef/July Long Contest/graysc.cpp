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
   
typedef unsigned long long ull;  

string solve(int N)
{
  string y = "Yes";
  string n = "No";
  if(N > 67) 
    {
      ull A;
      while(N--)
	scanf("%llu", &A);
      return y;
    }
  else 
    {
      ull A[N];
      FOR(i, 0, N)
	scanf("%llu", A + i);
      
      for(int i = 0; i < N; i++)
	for(int j = i+1; j < N; j++)
	  for(int k = j+1; k < N; k++)
	    for(int l = k+1; l < N; l++){
	      if((A[i]^A[j]^A[k]^A[l]) <= 0){ 
		return y;
	      }
	    }
      return n;
    }
}

int main()
{
  int N;
  scanf("%d", &N);
  cout << solve(N) << endl;
  return 0;
}
