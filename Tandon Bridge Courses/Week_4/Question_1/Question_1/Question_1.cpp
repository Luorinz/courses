/*Write two versions of a program that reads a positive integer n,and prints the first n even numbers  */

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int input_1,input_2;
	int count_1 =1;
	int count_2 ;
	cout << "section a \n";
	cout << "Please enter a positive integer: ";
	cin >> input_1;

	
	while (count_1 <= 2 * input_1)
	{
		if ( count_1 % 2 == 0 )
		{
			cout<< count_1 <<endl;
		}
		count_1++;

		}
	cout << "section b \n";
	cout << "Please enter a positive integer: ";
	cin >> input_2;
	for (count_2 = 1; count_2 <= 2 * input_2; count_2++)
	{
		if (count_2 % 2 == 0)
		{
			cout << count_2 << endl;
		}
	}
    return 0;
}

