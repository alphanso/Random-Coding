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
#include <cassert>
#include <string.h>
 
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; i++)

char board[51][51] = {};
int mem[51][51] = {};
void init();
void calc(int i, int j);
int main()
{
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  
  FOR(i, 0, n)
    scanf("%s", board[i]);

  // FOR(i, 0, n)
  //   {
  //     FOR(j, 0, m)
  // 	printf("%c", board[i][j]);
  //     printf("\n");
  //   }
  
  return 0;
}
  
