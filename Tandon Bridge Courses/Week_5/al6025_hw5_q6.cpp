/*calculate the e*/

#include "stdafx.h"
#include <iostream>
using namespace std;

double eApprox(int n);

int main()
{
	cout.precision(30);

	for (int n = 1; n <= 15; n++)
	{
		cout << "n = " << n << '\t' << eApprox(n) << endl;

	}
    return 0;
}

double eApprox(int n) {
	double sum = 0;
	int denominator = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int k = 1; k <= i; k++)
		{
			denominator *= k;
		}
		sum += 1 / (double)denominator;
		denominator = 1;
	}
	return sum + 1;
}