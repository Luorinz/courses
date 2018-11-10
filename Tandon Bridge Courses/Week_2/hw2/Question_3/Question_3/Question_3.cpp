/*Enter two set of numbers of days, hours and minutes, and return the total time */

#include "stdafx.h"
#include <iostream>
using namespace std;
const int H_TO_M = 60, D_TO_H = 24;


int main()
{
	int days_j, hours_j, minutes_j;
	int days_b, hours_b, minutes_b;
	int	total_days, total_hours, total_minutes;
	
	cout << "Please enter the number of days John has worked: ";
	cin>>days_j;
	cout << "Please enter the number of hours John has worked: ";
	cin>>hours_j;
	cout << "Please enter the number of minutes John has worked: ";
	cin>>minutes_j;

	cout << "\nPlease enter the number of days Bill has worked: ";
	cin >> days_b;
	cout << "Please enter the number of hours Bill has worked: ";
	cin >> hours_b;
	cout << "Please enter the number of minutes Bill has worked: ";
	cin >> minutes_b;

	total_minutes = (minutes_j + minutes_b) % H_TO_M;
	total_hours = (minutes_j + minutes_b) / H_TO_M + (hours_j + hours_b) % D_TO_H;
	total_days = (hours_j + hours_b) / D_TO_H + days_j + days_b;

	cout << "\nThe total time both of them worked together is: " << total_days << " days, " << total_hours << " hours and " << total_minutes << " minutes.\n";

    return 0;
}

