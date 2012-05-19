#include <iostream>

using namespace std;

int main(){
	int ans = 0;
	int fib1 = 0;
	int fib2 = 1;
	int fibn = 1;
	while(fibn < 4000000){
		fibn = fib1 + fib2;
		if(fibn%2==0) ans+=fibn;
		fib1 = fib2;
		fib2 = fibn;
	}
	cout<<ans<<endl;
	return 0;
}

	
