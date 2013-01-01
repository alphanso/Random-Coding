#include<cstdio>
#include<iostream>
#include<set>
#include<queue>
#include<map>
#include<string>
#include<vector>
#include<cassert>
#include<cstdlib>

using namespace std;

int poor_valet(int N, int P[10000]);

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N, i, P[10000];
        scanf("%d", &N);
        for (i = 0; i < N; i++) {
            scanf("%d", &P[i]);
        }

        printf("%d\n", poor_valet(N, P));
    }
}

int poor_valet(int N, int P[10000]) {
  int ans = 0;
  int A[N];
  for(int i = 0; i < N; i++)
    A[P[i]] = i;
  for(int i = 0; i < N; i++)
    {
      if(P[i] == i) continue;
      else
	{
	  int count = 0;
	  int extra = P[i];
	  int j = i;
	  do{count++; j = A[j]; P[j] = j;}while(A[j] != extra);
	  count++;
	  // printf("%d %d\n", i, count);
	  ans+= count;
	}
    }
  return ans;
}
