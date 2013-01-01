#include <cstdio>

using namespace std;

int main()
{
  int T;
  int N, C;
  scanf("%d", &T);

  for(int i = 0; i < T; i++)
    {
      scanf("%d %d", &N, &C);
      int sum = 0, A;
      for(int j = 0; j < N; j++)
	{
	  scanf("%d", &A);
	  sum += A;
	}
      if(sum <= C) printf("Yes\n");
      else printf("No\n");
    }
  return 0;
}
