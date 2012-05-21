//Problem Link : http://www.codechef.com/MAY12/problems/TWSTR
#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <cstdio>

using namespace std;

int main()
{
	int N, Vi, x;
	string Si;
	set< pair<string, int> > recipes;
	char s[1000];
	cin >> N;
	// cout << N << endl;
	for(int i = 0; i < N; i++)
		{
			scanf("%s %d", s, &Vi);
			Si = s;
			recipes.insert(make_pair(Si, Vi));
			// printf("%s %d\n", s, Vi);
		}
	
	int Q, pr;
	string Qi, Oi;
	
	cin >> Q;
	set< pair<string, int> >::iterator start, end, it;
	// for(start = recipes.begin(); start != recipes.end(); start++)
	// 	cout << start->first << " " << start->second << endl;
	// cout << Q << endl;
	for(int i = 0; i < Q; i++)
		{
			scanf("%s", s);
			Qi = s;
			// printf("%s\n", s);
			start = lower_bound(recipes.begin(), recipes.end(), make_pair(Qi+"!",0));
			end = upper_bound(recipes.begin(), recipes.end(), make_pair(Qi+"{",0));
			if(end == start)
				{
					printf("NO\n");
					continue;
				}
			
			Oi = start->first;
			pr = start->second;
			start++;
			
			for(it = start; it != end; it++)
				{
					if(it->second > pr)
						{
							pr = it->second;
							Oi = it->first;
						}
				}
			cout << Oi << endl;
		}
	
	return 0;
}
