// Sum_integers.cpp: 定义控制台应用程序的入口点。
/*This program reads two integers from the user and prints their sum*/

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int num1;	//will hold the first input
	int num2;	//will hold the second input
	int sum;		//will hold the sum

	cout << "Please enter two numbers separated by a space" << endl;
	cin >> num1 >> num2;
	sum = num1 + num2;

	cout << num1 << " + " << num2 << " = " << sum << endl;

    return 0;
}

