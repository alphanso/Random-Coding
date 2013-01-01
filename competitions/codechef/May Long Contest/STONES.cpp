//Problem Link : http://www.codechef.com/MAY12/problems/STONES
#include <iostream>
#include <set>

using namespace std;

int main()
{
	int T, ans;
	cin >> T;
	set<char> jewels;
	string jewel, stone;

	for(int i = 0; i < T; i++)
		{
			cin >> jewel >> stone;
			
			for(int j = 0; j < jewel.size(); j++)
				jewels.insert(jewel[j]);
			
			ans = 0;
			for(int j = 0; j < stone.size(); j++)
				if(jewels.find(stone[j]) != jewels.end()) ans++;
			
			cout << ans << endl;
			jewels.clear();
		}
	
	return 0;
}
