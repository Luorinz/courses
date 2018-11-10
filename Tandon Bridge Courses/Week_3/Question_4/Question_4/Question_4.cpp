/*Enter a Real number and ask the user to enter the method by which they want to round that number*/


#include "stdafx.h"
#include <iostream>
using namespace std;

const int FLOOR_ROUND = 1, CEILING_ROUND = 2, ROUND = 3;


int main()
{
	//input
	int method;
	double input, output;
	cout << "Please enter a Real number: \n";
	cin >> input;
	cout << "Choose your rounding method: \n";
	cout << "1. Flooring round \n";
	cout << "2. Ceiling round \n";
	cout << "3. Round to the nearest whole number \n";
	cin >> method;

	//process

	switch (method)
	{
	case 1:
		output = (int)input;
		cout << output<<endl;
		break;
	case 2:
		output = 1 + (int)input;		
		cout << output << endl;

		break;

	default:
		if (input < (int)input+0.5)
		{
			output = (int)input;
			cout << output << endl;



		}
		else
		{
			output = (int)input + 1;
			cout << output << endl;

		}
		break;

	}


    return 0;
}

