#include <vector>
#include <iostream>
#include "pta.cpp"

using namespace std;

int main()
{
	int M, N;
	cout << "Enter no of rows in augmented matrix and no of inputs respectively\n";
	cin >> M >> N;
	vector<int> temp(N, 0);
	vector< vector<int> > mat(M, temp);

	cout << "Enter the augmented matrix \n";
	for(int i = 0; i < M; i++)
		for(int j = 0; j < N; j++)
			cin >> mat[i][j];
	
	vector<int> ans = pta(mat);  //calling training algorithm
	
	// printing output
	for(int i = 0; i < N; i++)
		cout << ans[i] <<" ";
	cout<<endl;
	
	return 0;
}
