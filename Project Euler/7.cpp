#include <iostream>

using namespace std;

long long memPrime[10001];

long long nthPrime(int n)
{
	memPrime[0] = 2;
	memPrime[1] = 3;
	
	int i = 2, k;
	long long x = 5;
	if (n == 1) return 2;
	else if (n == 2) return 3; 
	while (i <= n)
		{
			for(k = 0; k < i; k++)
				if(x % memPrime[k] == 0) break;
			
			if(i == k)
				{
					memPrime[i] = x;
					i++;
				}
			
			x += 2;
			
			for(k = 0; k < i; k++)
				if(x % memPrime[k] == 0) break;
			
			if(i == k)
				{
					memPrime[i] = x;
					i++;
				}
			
			x += 4;
		}

	return memPrime[n-1];
}

int main()
{
	int n;
	cin >> n;
	cout << nthPrime(n) << endl;
	return 0;
}
