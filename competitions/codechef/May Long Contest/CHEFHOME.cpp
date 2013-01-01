//Problem Link : http://www.codechef.com/MAY12/problems/CHEFHOME
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int T, N;
	cin >> T;
	
	for(int i = 0; i < T; i++)
		{
			cin >> N;
			long long x[N];
			long long y[N];		
			
			for(int j = 0; j < N; j++)
				scanf("%lld %lld", x + j, y + j);
				
			if(N % 2) cout << "1" << endl;
			else 
				{
					sort(x, x + N);
					sort(y, y + N);
					int index = N / 2;
					cout << (x[index] - x[index - 1] + 1) * (y[index] - y[index - 1] + 1) << endl;
				}
		}
	return 0;
}
