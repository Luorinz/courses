#include "stdafx.h"
#include <iostream>
using namespace std;

bool isMonoArray(int* arr, int arrSize) {
	bool rest;
	if (arrSize ==1)
	{
		return true;
	}
	else
	{
		rest = isMonoArray(arr, arrSize - 1);
		if (rest == false)
		{
			return false;
		}
		else
		{
			if (arr[arrSize - 1] == arr[arrSize - 2])
			{
				return true;
			}
			else
				return false;
		}
		//return (rest == true) && (arr[arrSize - 1] == arr[arrSize - 2]	)
	}
}

int main()
{
	int arr[5] = { 1,1,1,1,11 };
	if (isMonoArray(arr, 5))
	{
		cout << "true" << endl;
	}
	else
		cout << "false" << endl;
    return 0;
}

