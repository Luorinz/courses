// Weeks_and_days.cpp: 定义控制台应用程序的入口点。
/*Return weeks and days given the total quantity of days*/

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int days_in;
	int weeks_out,days_out;

	cout << "How many days have you traveled?" << endl;
	cin >> days_in;
	weeks_out = days_in / 7;
	days_out = days_in % 7;
	cout << "You have traveled " << weeks_out << " weeks and " << days_out << " days.";
	
    return 0;
}

