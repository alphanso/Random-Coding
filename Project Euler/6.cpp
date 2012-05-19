#include <iostream>

using namespace std;

int main(){
	int ss=0;
	int s=0;
	for(int i=1; i<101;i++)
		ss+=(i*i);
	for(int i=1; i<101; i++)
		s+=i;
	cout<<(s*s)-ss<<endl;
	return 0;
}
