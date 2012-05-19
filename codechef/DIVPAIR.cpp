//Problem Link : http://www.codechef.com/MAY12/problems/DIVPAIR
#include <stdio.h>

inline long long sumQ(int N, int M)
{
	int y;
	long long x;
	x = N / M;
	y = N % M;
	
	long long ans = (M * ((x * (x - 1)) / 2L)) + x * (y + 1);
	return ans;
}

int main()
{
	int T;
	scanf("%d", &T);
	
	int N, M;
	long long count, count1, count2;

	for(int i = 0; i < T; i++)
		{
			scanf("%d %d", &N, &M);
			
			count1 = sumQ(((2 * N) - 1), M) - sumQ(N, M);
			
			long long x1 = ((2 * N) - 2) / M;
			int y1 = ((2 * N) - 2) % M;
			
			count2 = (((M / 2) * (x1 * (x1 - 1))) / 2) + (x1 * ((y1 / 2) + 1));
			if(M % 2)
				{
					if(x1 % 2)
						{
							count2 += (((x1 * x1) -1) / 4);
						}
					else
						{
							count2 += (((x1 + 2) * x1) / 4);
							count2 -= x1;
						}
				}
			
			count = count1 - count2;

			// cout << count << " ";
			// cout << count1 << " ";
			// cout << count1 << " ";			
			// cout << count2 << " ";
			printf("%lld\n", count); 
		}
	
	return 0;
}
