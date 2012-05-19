#include <iostream>
#include <sstream>

using namespace std;

bool checkpal(int ans){
	stringstream ss;
	ss<<ans;
	string s;
	ss>>s;
	for(int i=0; i<s.size(); i++)
		if(s[i]!=s[s.size()-1-i]) return false;
	return true;
}

int main(){
	int ans;
	for(int i=999; i>99; i--){
		for(int j=999; j>99; j--){
			ans=i*j;
			if(checkpal(ans)){
				cout<<i<<" "<<j<<" "<<ans<<endl;
				break;
			}
		}
	}
	return 0;
}
