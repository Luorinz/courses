#include "stdafx.h"
#include <iostream>	
using namespace std;

void merge(int arr[], int lowLeft, int highLeft, int highRight) {
	int lowRight,size;
	int *mergedArr;
	int iRight, iLeft, iRes;

	lowRight = highLeft + 1;
	size = highRight - lowLeft + 1;
	mergedArr = new int[size];

	iLeft = lowLeft;
	iRight = lowRight;
	iRes = 0;
	while (iLeft <= highLeft && iRight <= highRight) {
		if (arr[iLeft] < arr[iRight])
		{
			mergedArr[iRes] = arr[iLeft];
			iLeft++;
			iRes++;
		}
		else
		{
			mergedArr[iRes] = arr[iRight];
			iRight++;
			iRes++;
		}
	}
	while (iLeft <= highLeft) {
		mergedArr[iRes] = arr[iLeft];
		iLeft++;
		iRes++;
	}
	while (iRight <= highRight) {
		mergedArr[iRes] = arr[iRight];
		iRight++;
		iRes++;
	}
	for (int i = 0,iArr = lowLeft; i < size; i++,iArr++)
	{
		arr[iArr] = mergedArr[i];
	}
	delete[]mergedArr;

}

void mergeSort(int arr[],  int low, int high) {
	int mid;
	if (low == high)
	{
		return;
	}
	else
	{
		mid = (low + high) / 2;
		mergeSort(arr,low,mid);
		mergeSort(arr, mid+1, high);
		merge(arr, low, mid, high);
	}
}



int main()
{
	int arr[8]	 = { 14,5,8,10,13,1,18,3 };
	for (int i = 0; i < 8; i++)
	{
		cout << arr[i] << " ";
	}
	mergeSort(arr, 0, 7);
	cout << endl;
	for (int i = 0; i < 8; i++)
	{
		cout << arr[i] << " ";
	}
    return 0;
}

