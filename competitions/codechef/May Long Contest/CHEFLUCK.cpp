//Problem Link : http://www.codechef.com/MAY12/problems/CHEFLUCK
#include <iostream>

using namespace std;

void count(int N)
{
	int rem = N % 7;
	int i = N - rem;
	for(; i >= 0; i -= 7)
		{
			if((N - i) % 4) continue;
			else
				{
					cout << i << endl;
					break;
				}
		}
	if(i == -7) cout << "-1" << endl;
}

int main()
{
	int T, N;
	cin >> T;
	
	for(int i = 0; i < T; i++)
		{
			cin >> N;
			count(N);
		}
	return 0;
}
