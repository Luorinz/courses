#include "stdafx.h"
#include	<iostream>

using	namespace std;		

void	reverseArray(int* arr, int arrSize) {
	int last;
	int temp;
	if (arrSize <= 1)
	{
		return;
	}
	else
	{
		/*
		reverseArray(arr, arrSize - 1);
		last = arr[arrSize - 1];
		for (int i = arrSize -2; i >= 0; i--)
		{
			arr[i + 1] = arr[i];
		}
		arr[0] = last;
		*/
		reverseArray(arr + 1, arrSize - 2);
		temp = arr[0];
		arr[0] = arr[arrSize - 1];
		arr[arrSize - 1] = temp;
	}
}

int main()
{
	int arr[8] = { 1,2,3,4,5,6,7,8 };
	reverseArray(arr, 8);
	for (int i = 0; i < 8; i++)
	{
		cout << arr[i] << endl;
	}
    return 0;
}

