// Computing_the_Absolute_Value.cpp: 定义控制台应用程序的入口点。
/*Enter a number and return its absolute value*/

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int input,output;
	cout << "Please enter a number:\n";
	cin >> input;
	output = input;
	if (input < 0)
		output = -1 * input;
	cout << "the output is " << output << endl;
	
	return 0;
}

