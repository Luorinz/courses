/*input 3 real numbers and decide whether a quadratic equation has real solutions*/

#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;


int main()
{
	//input
	double val_a, val_b, val_c,solution_1,solution_2;
	cout << "Please enter value of a: ";
	cin >> val_a;
	cout << "Please enter value of b: ";
	cin >> val_b;	
	cout << "Please enter value of c: ";
	cin >> val_c;

	//control flow
	if (val_a ==0 && val_b ==0 && val_c ==0)
	{
		cout << "This equation has infinite number of solutions\n";
	}
	else if (val_a==0 && val_b==0 && val_c!=0)
	{
		cout << "This equation has no solution\n";
	}
	else if (val_a == 0 && val_b !=0)
	{
		if (val_c == 0)
		{
			solution_1 = 0;
		}
		else { solution_1 = -1 * val_c / val_b; }
		cout << "This equation has a single real solution x = " << solution_1 << endl;
	}
	else 
	{
		if (val_b * val_b - 4 * val_a * val_c < 0 )
		{
			cout << "This equation has no real solution\n";
		}
		else if (val_b * val_b - 4 * val_a * val_c == 0)
		{
			if (val_b == 0)
			{
				solution_1 = 0;
			}
			else { solution_1 = -1 * val_b / 2 * val_a; }
			cout << "This equation has a single real solution x = " << solution_1 << endl;
		}
		else
		{
			solution_1 = (-1 * val_b + sqrt(val_b * val_b - 4 * val_a * val_c))/ (2*val_a);
			solution_2 = (-1 * val_b - sqrt(val_b * val_b - 4 * val_a * val_c))/ (2 * val_a);
			cout << "This equation has two real solution x1 = " << solution_1 << " and x2 = " << solution_2 << endl;
		}
	}



    return 0;
}

