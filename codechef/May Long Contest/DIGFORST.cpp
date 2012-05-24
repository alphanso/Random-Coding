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

typedef long long ll;  

class vertex {
public:
  int v;
  int div;
  int rem;
};

int main()
{
  int N;
  while(true)
    {
      cin >> N;
      if(!N) break;
      
      int P[N];
      for(int i = 0; i < N; i++)
	cin >> P[i];
      
      int A[N][N];
      for(int i = 0; i < N; i++)
	for(int j = 0; j < N; j++)
	  cin >> A[i][j];
      
      vertex t;
      t.v = 0;
      if(c[0] > 1) t.div = 1 << (c[0] - 2);
      t.rem = (c[0] % 420);

      queue<vertex> q;
      q.push(t);
      
      while(!q.empty())
	{
	  vertex f = q.front();
	  q.pop();
	  
	  
