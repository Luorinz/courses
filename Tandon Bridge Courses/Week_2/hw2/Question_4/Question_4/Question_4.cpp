/*Enter 2 positive integers and prints the result of when we add, subtract, multiply, divide, div and mod them*/

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int	num1, num2;
	cout << "Please enter two positive integers, separated by a space:\n";
	cin >> num1 >> num2;
	cout << endl << num1 << " + " << num2 << " = " << num1 + num2 << endl;
	cout << endl << num1 << " - " << num2 << " = " << num1 - num2 << endl;
	cout << endl << num1 << " * " << num2 << " = " << num1 * num2 << endl;
	cout << endl << num1 << " / " << num2 << " = " << (float)num1 / num2 << endl;
	cout << endl << num1 << " div " << num2 << " = " << num1 / num2 << endl;
	cout << endl << num1 << " mod " << num2 << " = " << num1 % num2 << endl;

    return 0;
}

