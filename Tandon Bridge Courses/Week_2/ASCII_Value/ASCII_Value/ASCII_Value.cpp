// ASCII_Value.cpp: 定义控制台应用程序的入口点。
/*Enter a character and return the ASCII value of it*/

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	char input;
	int	output;
	cout << "Please enter the character:" << endl;
	cin >> input;
	output = input;
	cout << "The ASCII value is " << output << "." << endl;
    return 0;
}

