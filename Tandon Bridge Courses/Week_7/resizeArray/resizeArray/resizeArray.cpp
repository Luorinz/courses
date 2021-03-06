/*this program is to show:
1. how to make a dynamic array
2. how to resize it
*/
#include "stdafx.h"
#include <iostream>
using namespace std;

void resizeArray(int*& arr, int size, int newSize) {
	int *temp = new int[newSize];
	for (int i = 0; i < size; i++)
	{
		temp[i] = arr[i];
	}
	delete[] arr;
	arr = temp;
}


int main()
{
	int size = 10;
	int *arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = i * 10;
		cout << arr[i]<<endl;
	}
	int oneMore = 110;
	int newSize = size * 2;
	resizeArray( arr, size, newSize);
	
	arr[size++] = oneMore;
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << endl;
	}
    return 0;
}

