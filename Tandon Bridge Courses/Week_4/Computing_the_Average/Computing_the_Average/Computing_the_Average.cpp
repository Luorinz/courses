/*Write a program that reads grades of students in a class, and prints the average*/

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int number;
	int grade,sum;
	int counter;
	double average;
	//input
	cout << "Please enter the number of students: ";
	cin >> number;
	cout << "Enter the students' grades(separate by a space) \n";
	sum = 0;
	for (counter =1;  counter <= number ; counter++)
	{
		cin >> grade;
		sum += grade;
	}

	average = (double)sum / (double)number;
	cout << "The average is "<<average<<endl;
    return 0;
}

