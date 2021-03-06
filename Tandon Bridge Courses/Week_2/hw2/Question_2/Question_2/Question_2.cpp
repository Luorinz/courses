/*Enter the number of dollars and cents and return the value of quarters, dimes,
nickels and pennies.*/

#include "stdafx.h"
#include <iostream>
using namespace std;
const int QUARTER_VALUE = 25, DIME_VALUE = 10, NICKEL_VALUE = 5, PENNY_VALUE = 1, DOLLAR_VALUE = 100;


int main()
{
	int dollar, cent;
	int quarter, dime, nickel, penny;
	int current_cent;
	cout << "Please enter your amount in the format of dollars and cents seperated by a space:\n";
	cin >> dollar >> cent;
	current_cent = dollar * DOLLAR_VALUE + cent;
	quarter = current_cent / QUARTER_VALUE;
	current_cent = current_cent % QUARTER_VALUE;
	dime = current_cent / DIME_VALUE;
	current_cent = current_cent % DIME_VALUE;
	nickel = current_cent / NICKEL_VALUE;
	current_cent = current_cent % NICKEL_VALUE;
	penny = current_cent / PENNY_VALUE;
	current_cent = current_cent % PENNY_VALUE;
	cout << dollar << " dollars and " << cent << " cents are:\n";
	cout << quarter << " quarters, " << dime << " dimes, " << nickel << " nickels and " << penny << " pennies\n";

    return 0;
}

