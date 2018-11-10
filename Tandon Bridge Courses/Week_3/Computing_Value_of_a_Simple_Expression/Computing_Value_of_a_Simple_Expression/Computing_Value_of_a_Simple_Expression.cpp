// Computing_Value_of_a_Simple_Expression.cpp: 定义控制台应用程序的入口点。
/*Reads from the user a simple mathematical expression and prints it's value*/

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	double arg1, arg2;
	double res;
	char op;

	cout << "Please enter an expression of the form arg1 op arg2:\n";
	cin >> arg1 >> op >> arg2;

	switch (op)
	{
	case '+':
		res = arg1 + arg2;
		cout << res << endl;
		break;
	case '-':
		res = arg1 - arg2;
		cout << res << endl;
		break;
	case '*':
		res = arg1 * arg2;
		cout << res << endl;
		break;
	case '/':
		if (arg2 != 0)
		{
			res = arg1 / arg2; 
			cout << res << endl;
		}
		else
		{
			cout << "Ileagal expression" << endl;
		}
		
		break;
	default:
		cout << "Ileagal expression" << endl;
		break;
	}
    return 0;
}

