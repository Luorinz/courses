/*read the user a formated name and return another formated name*/
#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string first, mid, last, init;
	string output = "";
	cout << "Pleaser enter your name:\n";
	cin >> first >> mid >> last;
	init = mid[0] ;
	init += ".";
	output = last + ", " + first + " " + init;
	cout << output<<endl;
    return 0;
}

