#include "stdafx.h"
#include <iostream>
using namespace std;
int sumOfSquare(int arr[], int arrSize);
bool isSorted(int arr[], int arrSize);

int main()
{
	cout << "section a\n";
	int arr[4] = {2,-1,3,10};
	int sum;
	sum = sumOfSquare(arr,4);
	cout << sum <<endl;

	cout << "\n\nsection b\n";
	int arr2[4] = { 7,4,1,6 };
	bool Sorted = isSorted(arr2, 4);
	if (Sorted == true)
	{
		cout << "The array is sorted" << endl;
	}
	else
		cout << "The array is not sorted" << endl;

    return 0;
}

int sumOfSquare(int arr[], int arrSize) {
	int res= 0;
	if (arrSize == 1)
	{
		return (arr[0] * arr[0]);
	}
	else
	{
		
		res = sumOfSquare(arr, arrSize - 1);
		res += arr[arrSize - 1] * arr[arrSize - 1];
		return res;
	}
}
bool isSorted(int arr[], int arrSize) {
	bool res;
	if (arrSize == 1)
	{
		return true;
	}
	else
	{
		res = isSorted(arr, arrSize - 1);
		if (res == true )
		{
			return(arr[arrSize - 1] >= arr[arrSize - 2]);
		}
		else
			return false;
	}

}