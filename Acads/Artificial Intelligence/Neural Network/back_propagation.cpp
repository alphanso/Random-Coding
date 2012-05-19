#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;;

double** input;                // all input patterns
double* ideal_output;          // ideal output
double** wl1;                  // wl1[i][j] -> weight between ith hidden layer perceptron and jth input         
int in,hi,pa;                  // in -> input, hi - hidden, pa - pattern
double th2;                    // th2 - threshold of ouput
double* wl2;                   // wl2[i] -> weight between output and ith hidden layer perceptron
double* intm;                  // intm[i] -> intermediate output of ith hidden layer perceptron 
double* th1;                   // th1[i] -> threshold of ith hidden layer perceptron
double lr = 0.6;               // learning rate
const double ERROR = 0.1;      // error tolerance
//transfer function -> f(x) = 1 / (1 + e^(-x))
double sigmoid(double x)
{
	double retval;
	retval = 1 / (1 + exp(-x));
	return retval;
}

//intializes variable and takes input from user
void init()
{
	pa = pow(2, in);
	input = new double*[pa];
	ideal_output = new double[pa];
	for(int i=0; i<pa; i++)
		input[i] = new double[in];
	cout << "Enter truth table" << endl;
	for(int i=0; i<pa; i++)
		{
			for(int j=0; j<in; j++)
				cin >> input[i][j];
			cin >> ideal_output[i];
		}
	intm = new double[hi];
}

//weight initialization method
void init_w()
{
	srand(time(NULL));
	th2 = (rand()%5);

	wl2 = new double[hi];
	th1 = new double[hi];
	for(int i=0; i<hi; i++)
		{
			wl2[i] = (rand()%5);
			th1[i] = (rand()%5);	
		}

	wl1 = new double*[hi];
	for(int i=0; i<hi; i++)
		{
			wl1[i] = new double[in];
			for(int j=0; j<in; j++)
				{
					wl1[i][j] = (rand()%5);
				}
		}
}

//calculates input for transfer function
double calcSum(double in[], double wl[], double theta, int size)
{
	double retval = -theta;
	for(int i=0; i<size; i++)
		retval += (wl[i]*in[i]);
	return retval;
}

//prints the value of weights and threshold at any given point
void print()
{
	cout << th2 << " ";
	for(int i=0; i<hi; i++)
		{
			cout << wl2[i] << " ";
		}
	cout << endl;
	for(int j=0; j<hi; j++)
		{
			cout << th1[j] << " " ;
			for(int i=0; i<in; i++)
				{
					cout << wl1[j][i] << " ";
				}
			cout << endl;
		} 
}

//updates the weight vector after every method
void update(int index, double interm[], double o2)
{
	double d2,d1;
	
	//update th2
	d2 = (ideal_output[index] - o2)*o2*(1-o2);
	th2 += lr*d2*(-1);

	//update wl2
	for(int i=0; i<hi; i++)
		wl2[i] += lr*d2*interm[i];

	//update th1 && wl1s
	for(int i=0; i<hi; i++)
		{
			d1 = (wl2[i]*d2)*interm[i]*(1-interm[i]);
			th1[i] += lr*d1*(-1);
			for(int j=0; j<in; j++)
				wl1[i][j] += lr*d1*input[index][j];
		}
}

//training algorithm for neural network
void train()
{
	bool flag = true;
	int index;
	double max_error, interm[hi], o;
	double output, error;

	while(flag)
		{
			max_error = 0;
			for(int i=0; i<pa; i++)
				{
					for(int j=0; j<hi; j++)
						intm[j] = sigmoid(calcSum(input[i], wl1[j], th1[j], in));
					output = sigmoid(calcSum(intm, wl2, th2, hi));
					error = abs(ideal_output[i] - output);
					if(max_error < error)
						{
							max_error = error;
							index = i;
							for(int j=0; j<hi; j++)
								interm[j] = intm[j];
							o=output;
						}
				}
			if(max_error < ERROR)
				{
					flag = false;
				}
			else 
				{
					//cout << max_error << " " << index << endl;
					update(index, interm, o);
					//print();
				}
		}
	cout << "Weight training Complete\n";
	print();
}

//used for calculatin the outout once training completes
void calc()
{
	double output;
	cout << "in1 in2 in3.. output ideal_output" << endl;
	for(int i=0; i<pa; i++)
		{
			for(int j=0; j<hi; j++)
				intm[j] = sigmoid(calcSum(input[i], wl1[j], th1[j], in));
			output = sigmoid(calcSum(intm, wl2, th2, hi));
			for(int j=0; j<in; j++)
				cout << input[i][j] << " ";
			cout << output << " ";
			cout << " " << ideal_output[i] << endl;
		}
}


int main()
{
	cout << "Enter no of Inputs" << endl;
	cin >> in;
	cout << "Enter no of hidden layer perceptron" << endl;
	cin >> hi;
	init();
	init_w();
	cout << "Threshold w1 w2 ..." << endl;
	cout << "Initial value of weights and threshold\n";
	print();
	train();
	calc();
	return 0;
}
