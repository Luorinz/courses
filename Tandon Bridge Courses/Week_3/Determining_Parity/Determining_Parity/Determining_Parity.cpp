// Determining_Parity.cpp: 定义控制台应用程序的入口点。
/*Enter an integer and return whether it is an odd or even number*/

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int	input;
	cout << "Please enter a positive integer: \n";
	cin >> input;
	if (input%2 ==0)
	{
		cout << "This is an even number\n";

	}
	else
	{
		cout << "This is an odd number\n";
	}
    return 0;
}

