/*Primality Testing*/
#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{

	bool isPrime(int num) {
		int countDivs;
		countDivs = 0;
		for (int i = 1; i <= num; i++)
		{
			if (num % i == 0)
			{
				countDivs++;

			}

		}
		if (countDivs ==2)
		{
			return true;

		}
		else
		{
			return false;
		}
	}
    return 0;
}

