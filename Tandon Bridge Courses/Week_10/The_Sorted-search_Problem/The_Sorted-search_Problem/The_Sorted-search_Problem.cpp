#include "stdafx.h"
#include	<iostream>
using namespace std;

int sortedSearch(int strArr[], int srtArrSize, int val) {
	int low, high,mid;
	int ind;
	bool found;

	low = 0;	
	high = srtArrSize - 1;
	found = false;
	while ((found == false) && (low <= high))
	{
		mid = (low + high) / 2;
		if (strArr[mid] == val)
		{
			ind = mid;
			found = true;
		}
		else if (val < strArr[mid])
		{
			high = mid - 1;
		}
		else
			low = mid + 1;

	}
	if (found == true)
	{
		return ind;
	}
	else
	{
		return -1;
	}
}

int main()
{
	int strArr[10] = { 1,3,5,7,9,11,13,15,17,19 };
	cout << sortedSearch(strArr, 10, 13) << endl;
    return 0;
}

