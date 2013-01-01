#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<cmath>
#include<algorithm>
#include<cassert>
#include<iostream>
#include<queue>
#include <bitset>

using namespace std;

int lost_cake(int N, int E, int S, int F, int A[40001], int B[40001]);

int main () {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N, E, S, F, i;
        int A[40001], B[40001];
        scanf("%d %d %d %d", &N, &E, &S, &F);
        for (i = 0; i < E; i++) {
            scanf("%d %d", &A[i], &B[i]);
        }
        printf("%d\n", lost_cake(N, E, S, F, A, B));
    }
    return 0;
}

vector< vector<int> > room(10001);

bitset<10001> visited;
int lost_cake(int N, int E, int S, int F, int A[40001], int B[40001]) {
  // printf("function called\n");
  for(int i = 0; i < 10001; i++)
    room[i].clear();
  visited.reset();
  for(int i = 0; i < E; i++)
    {
      room[A[i]].push_back(B[i]);
      room[B[i]].push_back(A[i]);
    }
  // for(int i = 1; i <= N; i++)
  //   {
  //     for(int j = 0; j < room[i].size(); j++)
  // 	printf("%d ", room[i][j]);
  //     printf("\n");
  //   }
  vector<int> v;
  v.push_back(S);
  int travelled = 0;
  while(!v.empty())
    {
      // printf("Entered loop\n");
      vector<int> next;
      for(int i = 0; i < v.size(); i++)
	{
	  //printf("%d\n", v[i]);
	  if(v[i] == F) return travelled;
	  visited.set(v[i]);
	  for(int j = 0; j < room[v[i]].size(); j++)
	    if(!visited[room[v[i]][j]]) next.push_back(room[v[i]][j]);
	}
      v.clear();
      travelled++;
      v.assign(next.begin(), next.end());
    }
  return -1;
}
