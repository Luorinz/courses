/*Enter the weight and height and return the weight status*/

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

const double POUND_TO_KG = 0.453592, INCH_TO_METER = 0.0254;

int main()
{
	//input
	double weight, height,BMI;
	string status;
	cout << "Please enter weight(in pounds): ";
	cin >> weight;
	cout << "Please enter height(in inches): ";
	cin >> height;

	//process
	BMI = (weight * POUND_TO_KG) / (height * INCH_TO_METER * height* INCH_TO_METER);
	if (BMI < 18.5)
	{
		status = "Underweight";
	}
	else if (BMI < 25)
	{
		status = "Normal";
	}
	else if (BMI<30)
	{
		status = "Overweight";
	}
	else
	{
		status = "Obese";
	}
	cout << "The weight status is: " << status << endl;
    return 0;
}

