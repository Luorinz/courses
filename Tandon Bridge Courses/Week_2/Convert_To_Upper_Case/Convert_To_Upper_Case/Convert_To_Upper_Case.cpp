// Convert_To_Upper_Case.cpp: 定义控制台应用程序的入口点。
/*Enter a lower case character and return its upper case character*/

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	char lower,upper;
	int offset;
	cout << "Please enter the lower case:\n";
	cin >> lower;
	/*
	upper = lower - 32;
	*/
	offset = (int)(lower - 'a');
	upper = (char)('A' + offset);
	cout << "The upper case is " << upper << ".\n";
    return 0;
}

