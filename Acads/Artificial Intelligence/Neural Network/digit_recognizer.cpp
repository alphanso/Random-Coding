#include <iostream>
#include <vector>
#include <algorithm>
#include "pta.cpp"

using namespace std;

void print(vector<int> v)
{
	for(int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
}

vector<int> bit_to_v(int x, int sign)
{
	vector<int> v;
	for(int i = 0; i < 7; i++)
		v.push_back(sign * (x >> i & 1));
	reverse(v.begin(), v.end());
	v.push_back(-1 * sign);
	return v;
}

vector< vector<int> > generate_matrix(int j)
{
	vector< vector<int> > matrix;
	for(int i = 0; i < 1<<7; i++) 
		matrix.push_back(bit_to_v(i, -1));
 
	switch (j)
		{
		case 1:
			matrix[48] = bit_to_v(48, 1);
			break;
    case 2:
			matrix[109] = bit_to_v(109, 1);
			break;
		case 3:
			matrix[121] = bit_to_v(121, 1);
			break;
    case 4:
			matrix[51] = bit_to_v(51, 1);
			break;
		case 5:
			matrix[91] = bit_to_v(91, 1);
			break;
    case 6:
			matrix[95] = bit_to_v(95, 1);
			break;
		case 7:
			matrix[112] = bit_to_v(112, 1);
			break;
    case 8:
			matrix[127] = bit_to_v(127, 1);
			break;
		case 9:
			matrix[123] = bit_to_v(123, 1);
			break;
    case 0:
			matrix[126] = bit_to_v(126, 1);
			break;
    }
	
 return matrix;
}


vector< vector<int> > init()
{
	vector< vector<int> > WV(10);
	for(int i = 0; i < 10; i++)
		WV[i] = pta(generate_matrix(i));
	return WV;
}

int main()
{
	
	vector< vector<int> > WV = init();
	vector<int> input(7, -1);
	char c;
	bool flag = true;

	cout << "Returns the no if pattern corresponds to that number ";
	cout << "else nothing is returned" << endl; 

	//for(int i = 0; i < 10; i++)
	//	print(WV[i]);
	
	while(flag)
		{
			cout << "Enter the input pattern" << endl; 

			for(int i = 0; i < 7; i++)
				cin>>input[i];
	
			//print(input);
 
			for(int i=0; i<10; i++)
				if(dot(input, WV[i]) > WV[i][7]) 
					{
						//print(WV[i]);
						//print(input);
						//cout << dot(WV[i], input) << endl;
						cout<< i <<endl;
						break;
					}

			cout << "Type \'y\' to continue\n";
			cin >> c;
			if(c == 'y') flag = true;
			else flag = false;
		}

	return 0;
}
