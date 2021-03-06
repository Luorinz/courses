/* Read from the user a positive integer(decimal) and prints its binary representation*/
#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;

const int DIVISOR = 2;

int main()
{
	int input,output;
	int dividend,remainder;
	int count;
	//input
	cout << "Enter decimal number: \n";
	cin >> input;
	
	//Processing
	dividend = input;
	count = 0;
	remainder = 0;
	output = 0;
	while (dividend > 0)
	{
		remainder = dividend % DIVISOR;
		output += remainder * pow(10, count);
		dividend = dividend / DIVISOR;
		count++;
	}


	//output
	cout << "The binary representation of "<< input <<" is "<< output <<endl;
    return 0;
}

