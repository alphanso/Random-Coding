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

int gcd(int m, int n)
{
   int r;
   if (m < n) return gcd(n,m);
   r = m%n;
   if (r == 0) return(n);
   else return(gcd(n,r));
}

void out(int a, int b)
{
  int G = gcd(a, b);
  printf("%d/%d\n", a/G, b/G);
}

int main()
{
  int N, A, B, C;
  scanf("%d", &N);
 
  FOR(i, 0, N)
    {
      scanf("%d %d %d", &A, &B, &C);
      if(C >= A+B)
	printf("1/1\n");
      else if(C <= A && C <= B)
	out(C*C, 2*A*B);
      else if(C > A && C <= B)
	out(A*(C+C-A), 2*A*B);
      else if(C <= A && C > B)
	out(B*(C+C-B), 2*A*B);
      else
	out((2*A*B)-((A+B-C)*(A+B-C)), 2*A*B);
    }
  return 0;
}
