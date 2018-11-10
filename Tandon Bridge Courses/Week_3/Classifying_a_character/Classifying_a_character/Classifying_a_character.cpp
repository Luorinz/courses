// Classifying_a_character.cpp: 定义控制台应用程序的入口点。
/*Reads from the user a character, and classifies it to one of the following:
lower case letter
upper case letter
digit
not alpha-numeric character*/

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	char input;
	cout << "Please enter a character:\n";
	cin >> input;
	if (input>='a' and input <= 'z')
	{
		cout << input << " is a lower case letter\n";

	}
	else if (input>='A' and input <= 'Z')
	{
		cout << input << " is an upper case letter\n";

	}
	else if (input>='0' and input<='9')
	{
		cout << input << " is a digit\n";
	}
	else
	{
		cout << input << " is not an alpha-numeric character\n";
	}
	
    return 0;
}

