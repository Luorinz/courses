/* given an integer and return its divisors*/

#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;

void printDivisors(int num);

int main()
{
	int num;
	cout << "Please enter a positive integer >=2: ";
	cin >> num;
	printDivisors(num);

    return 0;
}

void printDivisors(int num) {
	int count = 1;
	int smallDivisor = 0;
	int bigDivisor = 0;
	bool flag;

	if (sqrt(num) == round(sqrt(num)))
		flag = true;

	while (count <= sqrt(num))
	{
		if (num % count == 0)
		{
			smallDivisor = count;
			cout << smallDivisor << " ";
		}
		count++;
	}
	for (int i = count - 2; i >= 1; i--)
	{
		if (num % i ==0)
		{
			bigDivisor = num / i;
			cout << bigDivisor << " ";
		}
	}
		cout << endl;
}

