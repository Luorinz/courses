#include "stdafx.h"
#include <iostream>
using namespace std;

void printArray(int arr[], int arrSize);
void reverseArray(int arr[], int arrSize);
void removeOdd(int arr[], int& arrSize);
void splitParity(int arr[], int arrSize);

int main()
{
	int arr1[10] = { 9,2,14,12,-3};
	int arr1Size = 5;

	int arr2[10] = { 21,12,6,7,14 };
	int arr2Size = 5;

	int arr3[10] = { 3,6,4,1,12 };
	int arr3Size = 5;

	reverseArray(arr1, arr1Size);
	printArray(arr1, arr1Size);

	removeOdd(arr2, arr2Size);
	printArray(arr2, arr2Size);

	splitParity(arr3, arr3Size);
	printArray(arr3, arr3Size);

    return 0;
}

void printArray(int arr[], int arrSize) {
	int i;
	for ( i = 0; i < arrSize; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
}

void reverseArray(int arr[], int arrSize) {
	int temp;
	for (int ind = 0; ind < 0.5 * (arrSize - 1); ind++ )
	{
		temp = arr[ind];
		arr[ind] = arr[arrSize - 1 - ind];
		arr[arrSize - 1 - ind] = temp;
	}
}

void removeOdd(int arr[], int& arrSize) {
	int oddCount = 0;
	int newIndex = 0;
	for (int ind = 0; ind < arrSize; ind++)
	{
		if (arr[ind] % 2 != 0)
		{
			oddCount++;
		}
		else
		{
			arr[newIndex] = arr[ind];
			newIndex++;
		}
	}
	arrSize = arrSize - oddCount;
}

void splitParity(int arr[], int arrSize) {
	int oddCount = 0;
	int temp;
	for (int ind = 0; ind < arrSize; ind++)
	{
		if (arr[ind] % 2 != 0)
		{
			oddCount++;
			temp = arr[ind];
			arr[ind] = arr[oddCount - 1];
			arr[oddCount - 1] = temp;
		}
	}
}
