/*using iterative statement to count and sum each digit of a giving integer*/

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int number,num,currDigit,countDigits,sumDigits;
	cout << "Please enter an integer: ";
	cin >> num;
	sumDigits = 0;
	countDigits = 0;
	number = num;
	while (num >0)
	{
		currDigit = num % 10;
		countDigits++;
		sumDigits += currDigit;
		num = num / 10;
	}

	cout << number<<" has "<<countDigits<<" Digits";
	cout << " and their sum is " << sumDigits << endl;
    return 0;
}

