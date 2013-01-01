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
  int T, K, N;
  string S;
  scanf("%d", &T);

  while(T--)
    {
      scanf("%d", &K);
      cin >> S;
      N = S.size();
      
      if(N == 1)
	{
	  if(S[0] == '?')
	    cout << "0" << endl;
	  else
	    cout << S << endl;
	  continue;
	}
      else
	{
	  int i;
	  for(i = 0; i < N; i++)
	    if(S[i] != '?' && S[i] == S[(i + 1) % N]) 
	      {
		cout << "NO" << endl;
		break;
	      }
	  if(i != N) 
	    continue;
	  //cerr << "String " << S << " is valid\n";
	  
	  if(K == 1) 
	    cout << "NO" << endl;
	  else if(K == 2)
	    if(N % 2) 
	      cout << "NO" << endl;
	    else 
	      {
		bool o1 = false, o0 = false, e1 = false, e0 = false;
		for(i = 0; i < N; i++)
		  if(S[i] == '?') 
		    continue;
		  else if(S[i] == '1')
		    if(i % 2) 
		      o1 = true;
		    else 
		      e1 = true;
		  else
		    if(i % 2) 
		      o0 = true;
		    else
		      e0 = true;
		
		if((o0 && e0) || (o1 && e1) || (o1 && o0) || (e0 && e1)) 
		  {
		    cout << "NO" << endl;
		    continue;
		  }
		else if(o0 || e1)
		  for(i = 0; i < N; i++)
		    if(i % 2) S[i] = '0';
		    else S[i] = '1';
		else
		  for(i = 0; i < N; i++)
		    if(i % 2) S[i] = '1';
		    else S[i] = '0';
		cout << S << endl;
	      }
   
	  else 
	    {
	      if(S[0] == '?')
		if(S[N - 1] != '0' && S[1] != '0') 
		  S[0] = '0';
		else if(S[N - 1] != '1' && S[1] != '1')
		  S[0] = '1';
		else
		  S[0] = '2';

	      for(int j = 1; j < N; j++)
		if(S[j] != '?') 
		  continue;
		else if(S[j - 1] != '0' && S[(j + 1) % N] != '0') 
		  S[j] = '0';
		else if(S[j - 1] != '1' && S[(j + 1) % N] != '1') 
		  S[j] = '1';
		else
		  S[j] = '2';
	      
	      cout << S << endl;
	    }
	}
    }
  
  return 0;
}
	  
