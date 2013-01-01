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
  int T, N, j;
  string l, r;
  int c4, c7;
  scanf("%d", &T);
  
  for(int i = 0; i < T; i++)
    {
      cin >> l >> r;
           
      if(l.size() != r.size())
      	{
      	  int diff = r.size() - l.size();
      	  for(int k = 0; k < diff; k++)
      	    l = "0" + l;
      	}
     
      c4 = c7 = 0;
      N = l.size();
      
      for(j = 0; j < N; j++)
	{
	  if(l[j] == '7') c7++;
	  else if(l[j] == '4') c4++;
	  else continue;
	}
      
      int res = c4 * c7; 
      // cerr << l << " " << res << endl;
      RFOR(k, N, 0)
	{
	  int cd = N - 1 - k;
	  int c = l[k] - '0';
	  l[k] = '9';
	  j = k;
	  if(l >= r) 
	    {
	      l[k] = (char)(c + '0');
	      break;
	    }
	  switch(c)
	    {
	    case 0:
	    case 1:
	    case 2:
	    case 3:
	      {
		cd++;
		int t = c4 + c7 + cd;
		if(c4 > t / 2) res =  max(res, c4 * (c7 + cd));
		else if(c7 > t / 2) res = max(res, c7 * (c4 + cd));
		else res = max(res, (t / 2) * (t - (t / 2)));
		break;
	      }
	    case 4:
	      {
		c4--;
	      }
	    case 5:
	    case 6:
	      {
		int t = c4 + c7 + cd + 1;
		if(c4 > t / 2) res = max(res, c4 * (c7 + cd + 1));
		else if(c7 + 1 > t / 2) res = max(res, (c7 + 1) * (c4 + cd));
		else res = max(res, (t / 2) * (t - (t / 2)));
		break;
	      }
	    case 7:
	      {
		c7--;
	      }
	    case 8:
	      {
	 	int t = c4 + c7 + cd;
		if(c4 > t / 2) res = max(res, c4 * (c7 + cd));
		else if(c7 > t / 2) res = max(res, c7 * (c4 + cd));
		else res = max(res, (t / 2) * (t - (t / 2)));
		break;
	      }
	    case 9:
	      {
		break;		
	      }
	    }
	  // cerr << l << " " << res << endl;
	}
      if(l[j] == '4') c4--;
      else if(l[j] == '7') c7--;
      // cerr << res << " " << l << endl;
      // cerr << l[j] << endl;
      int cd = N - 1 - j;
      bool n4n7 = false;
      for(int k = (l[j] - '0') + 1; k < (r[j] - '0'); k++)
	{
	  l[j] = (char)('0' + k);
	  if(k == 4)
	    {
	      c4++;
	      int t = c4 + c7 + cd;
	      if(c4 > t / 2) res = max(res, c4 * (c7 + cd));
	      else if(c7 > t / 2) res = max(res, c7 * (c4 + cd));
	      else res = max(res, (t / 2) * (t - (t / 2)));
	      c4--;
	    }
	  else if(k == 7)
	    {
	      c7++;
	      int t = c4 + c7 + cd;
	      if(c4 > t / 2) res = max(res, c4 * (c7 + cd));
	      else if(c7 > t / 2) res = max(res, c7 * (c4 + cd));
	      else res = max(res, (t / 2) * (t - (t / 2)));
	      c7--;
	    }
	  else if(!n4n7)
	    {
	      n4n7 = true;
	      int t = c4 + c7 + cd;
	      if(c4 > t / 2) res =  max(res, c4 * (c7 + cd));
	      else if(c7 > t / 2) res = max(res, c7 * (c4 + cd));
	      else res = max(res, (t / 2) * (t - (t / 2)));
	    }
	  // cerr << l << " " << res << endl;
	}
      
      if(r[j] == '4') c4++;
      else if(r[j] == '7') c7++;
      l[j] = r[j];
      for(int k = j + 1; k < l.size(); k++)
	l[k] = '0';
      // cerr << l << " " << res << endl;
      for(int k = j + 1; k < l.size(); k++)
	{
	  int c = r[k] - '0';
	  l[k] = (char)(c + '0');
	  switch(c)
	    {
	    case 0:
	      {
		break;
	      }
	    case 1: 
	    case 2:
	    case 3:
	      {
		cd = N - 1 - k;
		int t = c4 + c7 + cd;
		if(c4 > t / 2) res =  max(res, c4 * (c7 + cd));
		else if(c7 > t / 2) res = max(res, c7 * (c4 + cd));
		else res = max(res, (t / 2) * (t - (t / 2)));
		break;
	      }
	    case 4:
	      {
		cd = N - 1 - k;
		int t = c4 + c7 + cd;
		if(c4 > t / 2) res =  max(res, c4 * (c7 + cd));
		else if(c7 > t / 2) res = max(res, c7 * (c4 + cd));
		else res = max(res, (t / 2) * (t - (t / 2)));
		c4++;
		break;
	      }
	    case 5:
	    case 6:
	      {
		c4++;
		cd = N - 1 - k;
		int t = c4 + c7 + cd;
		if(c4 > t / 2) res =  max(res, c4 * (c7 + cd));
		else if(c7 > t / 2) res = max(res, c7 * (c4 + cd));
		else res = max(res, (t / 2) * (t - (t / 2)));
		c4--;
		break;
	      }
	    case 7:
	      {
		c4++;
		cd = N - 1 - k;
		int t = c4 + c7 + cd;
		if(c4 > t / 2) res =  max(res, c4 * (c7 + cd));
		else if(c7 > t / 2) res = max(res, c7 * (c4 + cd));
		else res = max(res, (t / 2) * (t - (t / 2)));
		c4--;
		c7++;
		break;
	      }
	    case 8:
	    case 9:
	      {
		cd = N - 1 - k;
		cd++;
		int t = c4 + c7 + cd;
		if(c4 > t / 2) res =  max(res, c4 * (c7 + cd));
		else if(c7 > t / 2) res = max(res, c7 * (c4 + cd));
		else res = max(res, (t / 2) * (t - (t / 2)));
	      }
	    }
	  //  cerr << l << "  " << res << endl;
	}
      res = max(res, c4 * c7);
      cout << res << endl;
    }
  return 0;
}

