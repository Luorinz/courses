// Area_of_a_circle.cpp: 定义控制台应用程序的入口点。
/*Print the area of a circle based on the given radius*/

#include "stdafx.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
using namespace std;


int main()
{
	double radius,area;
	cout << "Enter the radius of a circle:" << endl;
	cin >> radius;
	area = radius * radius * M_PI ;
	cout << "The area of the circle is " << area << "." << endl;

    return 0;
}

