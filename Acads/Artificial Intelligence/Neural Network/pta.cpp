#include <iostream>
#include <vector>
#include <set>

using namespace std;
//dot product of vector W and V
int dot(vector<int> W, vector<int> V)
{
	int ans=0;
	for(int i = 0; i < W.size(); i++)
		ans += W[i] * V[i]; 
	return ans;
}

//given an augmented matrix it will return weight vector for single perceptron system
vector<int> pta( vector< vector<int> > au_matrix)
{
	int N = au_matrix[0].size();   // inputs in a row
	int M = au_matrix.size();      // input patterns
	vector<int> W(N, 0);
	vector< vector<int> > archive; // to save the already seen weight vectors 
	set< vector<int> > present;    // used for checking whether weight vector has already occured
	int count;                     // no of trained rows in any iterations
	
	while(true)
		{
			count = 0;
			
			for(int i = 0; i < M; i++)   // loop over all rows of matrix
				{
					if(dot(W, au_matrix[i]) <= 0)   // update current row if dot product <= 0 
						{
							for(int j = 0; j < N; j++)   //updating the current row
								W[j] = W[j] + au_matrix[i][j];
							break;
						}
					else count++;                   //increasing the count of no of good rows in this iteration
				}
			
			if(count == M) break;               // all rows are trained so break
			
			if(present.find(W) != present.end()) //if weight vector is present in set "present" then it can't be trained
				{
					cout << "Infinite loop" <<endl;   
					for(int i = 0; i < archive.size(); i++)
						{
							for(int j=0;j<N; j++)
								cout << archive[i][j] << " ";
							cout << endl;
						}
					return W;
				}
			else    //if vector is not present then insert it
				{
					present.insert(W);  
					archive.push_back(W);
				}
		}
	return W;
}
