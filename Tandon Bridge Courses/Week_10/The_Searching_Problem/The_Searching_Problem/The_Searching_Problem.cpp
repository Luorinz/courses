#include "stdafx.h"
#include	<iostream>
using namespace std;

int search(int arr[], int arrSize, int val) {
	int i = 0;

	while (i < arrSize) {
		if (arr[i] == val)
		{
			return i;
		}
		i++;
	}
	return -1;
}

int main()
{
    return 0;
}

