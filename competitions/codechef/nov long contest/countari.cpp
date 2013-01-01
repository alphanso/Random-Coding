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
  int T;
  scanf("%d", &T);
  int A[T];
  FOR(i, 0, T)
    scanf("%d", A+i);
  
  ll ans = 0;
  int PDiff[30000] = {0}, NDiff[30000]={0};
  FOR(i, 0, T)
    {
      FOR(j, i+1, T)
	{
	  int diff = A[j] - A[i];
	  if(diff > 0)
	    {
	      if(!(diff & 1)) ans += PDiff[diff/2];
	      PDiff[diff]++;
	    }
	  else
	    {
	      if(!(diff & 1)) ans += NDiff[diff/2];
	      NDiff[diff]++;
	    }
	}
      memset(PDiff, 0, sizeof(PDiff));
      memset(NDiff, 0, sizeof(NDiff));
    }
  cout << ans << endl;
  return 0;
}
