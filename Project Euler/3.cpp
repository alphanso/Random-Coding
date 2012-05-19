#include <iostream>

using namespace std;

int main(){
	
	long long n;
	cin >> n;
	long long i = 5;
	while( !(n % 2) )
		cout << (n /= 2) << " 2" << endl;
	
	if (n == 1)
		{
			cout << "2" << endl;
			return 0;
		}
	
	while( !(n % 3) )
		cout << (n /= 3) << " 3" << endl;
	
	if (n == 1) 
		{
			cout << "3" << endl;
			return 0;
		}
	
	while (true)
		{
			while( !(n % i) ){
				cout << (n /= i) << " " << i << endl;
			}
			if (n == 1) break;
			else i+=2;
			
			while( !(n % i) ){
				cout	<< (n /= i) << " " << i << endl;
			}
			if (n == 1) break;
			else i += 4;
		}

	cout << i << endl;
	return 0;
}
