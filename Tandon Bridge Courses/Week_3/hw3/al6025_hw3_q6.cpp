/*Compute the cost of a long-distance call*/

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

const double WEEKEND_PRICE = 0.15, DAY_PRICE = 0.25, NIGHT_PRICE = 0.40;

int main()
{
	string day;
	int length, hour,minute;
	double cost;
	//input
	cout << "Please enter the day of the week: ";
	cin >> day;
	cout << "Please enter the time the call started: ";
	cin >> hour>>minute;
	cout << "Please enter the length of the call in minutes: ";
	cin >> length;

	//process
	if (day == "Sa" | day == "Su")
	{
		cost = WEEKEND_PRICE * length;
	}
	else if (hour < 8 | hour >18)
	{
		cost = NIGHT_PRICE * length;


	}
	else
	{
		cost = DAY_PRICE * length;


	}
	cout << "The cost is " << cost << "$.";
    return 0;
}

