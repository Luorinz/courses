/* print the calender*/

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
const int WEEKDAY = 7;
const int MONTH = 12;


int printMonthCalender(int numofDays, int startingDay);
bool isLeapYear(int year);
void printYearCalender(int year, int startingDay);
string whatMonth(int month);

int main()
{
	//test of function printMonthCalender
	cout << "section a" << endl;
	int numofDays, startingDay;
	int lastDay;
	cout << "Please enter numofDays and startingDay:\n";
	cin >> numofDays >> startingDay;
	lastDay = printMonthCalender(numofDays, startingDay);
	cout << endl<< lastDay << endl;

	//test of function ifLeapYear
	cout << endl << "section b" << endl;
	int year;
	cout << "Please enter a year:\n";
	cin >> year;
	if (isLeapYear(year))
		cout << year << " is a leap year" << endl;
	else
		cout << year << " is not a leap year"<< endl;

	//test of function printYearCalender
	cout << endl << "section c and d" << endl;
	int year1;
	int startingDay1;
	cout << "Please enter a year and starting day" << endl;
	cin >> year1>> startingDay1;
	printYearCalender(year1, startingDay1);

    return 0;
}

int printMonthCalender(int numofDays, int startingDay) {
	int week = 1;
	int lastDay = 0;
	if (startingDay > 7)
		startingDay = 1;
	int Sunday = WEEKDAY - startingDay + 1;
	//print the header
	cout << "Mon\tTue\tWed\tThr\tFri\tSat\tSun\n";
	//print the blank
	for (int i = 1; i <= startingDay - 1; i++)
	{
		cout << "   \t";
	}
	//print the first line
	for (int j = 1; j <= Sunday ; j++)
	{
		cout << j << "  \t";
	}
	cout << endl;
	//print the following lines
	while ((week - 1) * 7 + Sunday <= numofDays)
	{
		for (int k = (week - 1) * 7 + Sunday +1; k <= week * 7 + Sunday and k<= numofDays; k++)
		{
			if (k < 10)
				cout << k << "  \t";
			else
				cout << k << " \t";
		}
		cout << endl;
		week++;
	}
	cout << endl;
	lastDay = numofDays - (week - 2) * 7 - Sunday;
	if (lastDay != 0)
		return  lastDay;
	else
		return 7;
}

bool isLeapYear(int year) {
	if (year % 4 == 0)
	{
		if (year % 100 == 0)
		{
			if (year % 400 == 0)
			{
				return true;
			}
			else
				return false;
		}
		else
			return true;
	}
	else
		return false;
}

void printYearCalender(int year, int startingDay) {
	int feb = 28;
	int dayofMonth = 30;
	int lastDay = 0;
	int count = 0;
	// print the calender of January
	cout << whatMonth(1) <<" "<< year << endl;
	lastDay = printMonthCalender(dayofMonth + 1, startingDay);
	//print the calender of February
	if (isLeapYear(year))
		feb = 29;
	else
		feb = 28;
	cout << whatMonth(2) << " " << year << endl;
	lastDay = printMonthCalender(feb, lastDay + 1);
	//print the rest calender
	for (int i = 3; i <= MONTH; i++)
	{
		if (i == 8)
		{
			cout << whatMonth(i) << " " << year << endl;
			lastDay = printMonthCalender(dayofMonth + 1, lastDay + 1);
			
		}
		else{
			cout << whatMonth(i) << " " << year << endl;
			if (count == 0)
			{
				lastDay = printMonthCalender(dayofMonth + 1, lastDay + 1);
			}
			else
				lastDay = printMonthCalender(dayofMonth, lastDay + 1);
			count = 1 - count;
		}
	}



}

string whatMonth(int month) {
	string result;
	switch (month)
	{
	case 1:
		result = "January";
		break;
	case 2:
		result = "February";
		break;
	case 3:
		result = "March";
		break;
	case 4:
		result = "April";
		break;
	case 5:
		result = "May";
		break;
	case 6:
		result = "June";
		break;
	case 7:
		result = "July";
		break;
	case 8:
		result = "August";
		break;
	case 9:
		result = "September";
		break;
	case 10:
		result = "October";
		break;
	case 11:
		result = "November";
		break;
	case 12:
		result = "December";
		break;
	default:
		break;
	}
	return result;
}
