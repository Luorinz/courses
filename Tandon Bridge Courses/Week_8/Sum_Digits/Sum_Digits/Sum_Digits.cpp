#include "stdafx.h"
#include <iostream>	
using namespace std;

int sumDigits(int num) {
	int resSum;
	if (num<10)//base case
	{
		return num;
	}
	else
	{
		resSum = sumDigits(num / 10);
		resSum += num % 10;
		return resSum;
	}
}
/*
When calling the function on a smaller input it would do its job
↓
When calling sumDigits on a number with less digits, it would return
the sum of that number's digits
*/

int main()
{
	cout << sumDigits(111241421) << endl;
    return 0;
}

