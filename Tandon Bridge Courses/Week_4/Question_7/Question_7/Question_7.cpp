/*read a positive integer n and print out a nxn multiplication table*/

#include "stdafx.h"
#include <iostream>
using namespace std;
int main()
{
	//input
	int n;
	int i, j;
	cout << "Please enter a positive integer: \n";
	cin >> n;

	//process
	for ( i = 1; i <= n; i++)
	{
		for ( j = 1; j <= n; j++)
		{
			cout << i * j << "\t";
		}
		cout << endl;
	}
	//output
    return 0;
}

