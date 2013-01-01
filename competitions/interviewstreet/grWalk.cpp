#include <iostream>

using namespace std;

const int mod = 1e9 + 7;



void solve(int D, int M)
{
  mem[1][1] = 1;
  mem[D][1] = 1;
  for(int i = 2; i < D; i++)
    mem[i][1] = 2;
  
  for(int m = 2; m <= M; m++)
    {
      mem[1][m] = mem[2][m - 1];
      mem[D][m] = mem[D - 1][m - 1];
      for(int i = 2; i < D; i++)
	{
	  mem[i][m] = mem[i+1][m-1] + mem[i-1][m-1];
	  if(mem[i][m] > mod) mem[i][m] %= mod;
	  //cout << i << " " << m << " " << mem[i][m] << endl;
	}
    }
}

int main()
{
  int T;
  int N, M, i;
  int x[11], D[11];
  long long ans = 1;
  cin >> T;
  
  while(T--)
    {
      cin >> N >> M;
      
      for(i = 0; i < N; i++)
	cin >> x[i];
      
      for(i = 0; i < N; i++)
	cin >> D[i];
      ans = 1;
      for(i = 0; i < N; i++)
	{
	  solve(D[i], M);
	  ans *= mem[x[i]][M];
	  if(ans > mod) ans %= mod;
	}
      cout << ans << endl;
    }
  return 0;
}
      
