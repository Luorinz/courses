/*Enter a number of quarters, dimes, nickels and pennies, 
and return the value of dollars and cents*/

#include "stdafx.h"
#include <iostream>
using namespace std;

const int QUARTER_VALUE = 25, DIME_VALUE = 10, NICKEL_VALUE = 5,PENNY_VALUE = 1, DOLLAR_VALUE = 100;


int main()
{
	int quarter, dime, nickel, penny;
	int total_cent;
	int dollar, cent;
	cout << "Please enter number of coins:" << endl;

	cout << "# of quarters: ";
	cin >> quarter;
	cout << "# of dimes: ";
	cin >> dime;
	cout << "# of nickels: ";
	cin >> nickel;
	cout << "# of pennies: ";
	cin >> penny;
	total_cent = QUARTER_VALUE * quarter + DIME_VALUE * dime + NICKEL_VALUE * nickel + PENNY_VALUE * penny;
	dollar = total_cent / DOLLAR_VALUE;
	cent = total_cent % DOLLAR_VALUE;
	cout << "The total is " << dollar << " dollars and " << cent << " cents\n";

    return 0;
}

