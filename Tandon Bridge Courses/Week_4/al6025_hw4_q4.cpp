/*Read a sequence of positive integers from the user, calculate their geometric mean and print it.*/

#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;


int main()
{
	//section a
	cout << "section a \n";
	int length;
	int	sequence;
	int	product;
	int count;
	double mean;
	//input
	cout << "Please enter the length of the sequence: ";
	cin >> length;
	cout << "Please enter your sequence: \n";
	count = 1;
	product = 1;
	while (count <= length)
	{
		cin >> sequence;
		product *= sequence;
		count++;
	}

	//process
	mean = pow(product,1/(double)length );
	//output
	cout << "The geometric mean is: " << mean << endl;


	//section b
	cout << "section a \n";
	//input
	cout << "Please enter a non-empty sequence of positive integers, each one in a separate line. End your sequence by typing -1: \n";
	int input;
	int count_b;
	int product_b;
	double mean_b;
	bool isEnded;
	count_b = 0;
	product_b = 1;
	isEnded = true;
	while (isEnded)
	{
		cin >> input;
		if (input != -1)
		{
			product_b *= input;
			count_b++;
		}
		else
		{
			isEnded = false;
		}

	}
	//process
	mean_b = pow(product_b, 1 / (double)count_b );

	//output
	cout << "The geometric mean is: " << mean_b << endl;
    return 0;
}

