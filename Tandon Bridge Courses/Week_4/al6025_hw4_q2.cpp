/*Input a decimal number and print its representation in Roman numerals system*/

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int input,decimal;
	int counter;
	int i;
	string roman;
	cout << "Enter decimal number: \n";
	cin >> input;
	decimal = input;

	if (input /1000 >0)
	{
		counter = input / 1000;
		for (i = 1; i <= counter; i++)
		{
			roman += 'M';
		}
		input = input % 1000;
	}	
	if (input / 500 >0)
	{
		counter = input / 500;
		for (i = 1; i <= counter; i++)
		{
			roman += 'D';
		}
		input = input % 500;
	}
	if (input / 100 >0)
	{
		counter = input / 100;
		for (i = 1; i <= counter; i++)
		{
			roman += 'C';
		}
		input = input % 100;
	}
	if (input / 50 >0)
	{
		counter = input / 50;
		for (i = 1; i <= counter; i++)
		{
			roman += 'L';
		}
		input = input % 50;
	}
	if (input / 10 >0)
	{
		counter = input / 10;
		for (i = 1; i <= counter; i++)
		{
			roman += 'X';
		}
		input = input % 10;
	}
	if (input / 5 >0)
	{
		counter = input / 5;
		for (i = 1; i <= counter; i++)
		{
			roman += 'V';
		}
		input = input % 5;
	}
	if (input / 1 >0)
	{
		counter = input / 1;
		for (i = 1; i <= counter; i++)
		{
			roman += 'I';
		}
		input = input % 1;
	}
	
	cout <<decimal<< " is "<<roman << endl;
    return 0;
}

