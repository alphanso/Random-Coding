// http://www.codechef.com/COOK22/problems/LUCKYSTR/
/*
 * File: main.cpp
 * Author: Rishabh
 *
 * Created on May 20, 2012, 11:27 PM
 */
     
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;
     
/*
 *
 */
int main()
{
	int K, N, j;
	cin >> K >> N;
	string A[K], S;
	for(int i = 0; i < K; i++)
		cin >> A[i];
	for(int i = 0; i < N; i++)
		{
			cin >> S;
			if(S.size() >= 47) cout << "Good" << endl;
			else
				{
					for(j = 0; j < K; j++)
						{
							if(S.find(A[j]) != string::npos)
								{
									cout << "Good" << endl;
									break;
								}
						}
					if(j == K) cout << "Bad" << endl;
				}
		}
	return 0;
} 
