/**/

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	//input
	string name;
	int currentYear, gradYear;
	cout << "Please enter your name: ";
	cin >> name;
	cout << "Please enter your graduation year: ";
	cin >> gradYear;
	cout << "Please enter current year: ";
	cin >> currentYear;

	//process
	if (gradYear - currentYear>4)
	{
		cout << name << ", you are not in college yet\n";

	}
	else if (gradYear - currentYear == 4)
	{
		cout << name << ", you are a Freshman\n";

	}
	else if (gradYear - currentYear == 3 )
	{
		cout << name << ", you are a Sophomore\n";

	}
	else if (gradYear - currentYear == 2)
	{
		cout << name << ", you are a Junior\n";

	}
	else if (gradYear - currentYear == 1)
	{
		cout << name << ", you are a Senior\n";

	}
	else
	{
		cout << name << ", you are graduated\n";

	}


    return 0;
}

