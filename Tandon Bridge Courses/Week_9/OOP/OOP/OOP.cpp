#include "stdafx.h"
#include <iostream>
using namespace std;

void func(int x) {
	if (x>0)
	{
		func(x - 1);
		//cout << x << endl;
		cout << "THe address of x is: " << &x << " the value is : " << x << endl;
		x = 100;

	}
}

void func2(int* x) {
	if (*x>0)
	{
		//int *temp = new int((*x) - 1);
		//x = temp;
		*x -= 1;
		func2(x);
		cout << "THe address of x is: " << x << " the value is : " << *x << endl;
		//delete temp;

	}
}

int main()
{
	func(10);
	cout << "now calling func2" << endl;
	
	int *x = new int(10);
	func2(x);
	delete x;
    return 0;
}

