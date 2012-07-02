#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <bitset>
#include <set>
#include <iostream>

using namespace std;

// set<int> primes;

// void eratosthenes()
// {
//   bitset<10001> b;
//   primes.insert(2);
  
//   for(int i = 3; i < 10001; i += 2)
//     {
//       if(!b[i])
// 	{
// 	  primes.insert(i);
// 	  for(int j = i * i; j < 10001; j += i)
// 	    b[j] = 1;
// 	}
//     }
// }
      
int main()
{
  int T, N;
  scanf("%d", &T);
  // eratosthenes();
  // for(int i = 0; i < primes.size(); i++)
  //   cerr << primes[i] << " ";
  // cerr << endl;
  for(int i = 0; i < T; i++)
    {
      scanf("%d", &N);
      int U = sqrt(N);
      for(int j = U; j >= 1; j--)
	if(!(N % j)) 
	  {
	    printf("%d\n", (N / j) - j);
	    break;
	  }
    }
  return 0;
}
