#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int N, K;
  cin >> N >> K;
  vector<int> C(N);
  for(int i = 0; i < N; i++)
    cin >> C[i];
  
  int result = 0;
  sort(C.begin(), C.end());
  reverse(C.begin(), C.end());
  for(int i = 1; i <= N; i++)
    {
      result += ((i % K) + 1) * C[i - 1];
    }
  cout << result << endl;
  return 0;
}
