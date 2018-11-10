/*Ask the user to input a positive integern and print a textual image of an hourglass made of 2n lines with asterisks*/

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int n;
	int	i, j, k;
	//input
	cout << "Please enter the value of n:\n";
	cin >> n;

	//processing

	for ( i = 1; i <= n; i++)
	{
		for ( k = 1;  k  <= i-1;  k ++)
		{
			cout << " ";
		}
		for ( j = 1; j <= 1+2*(n-i); j++)
		{
			cout << "*";
		}
		cout << endl;
	}
	for (i = 1; i <= n; i++)
	{
		for (k = 1; k <= n - i; k++)
		{
			cout << " ";
		}
		for (j = 1; j <= 1 + 2 * (i-1); j++)
		{
			cout << "*";
		}
		cout << endl;
	}

	//output

    return 0;
}

