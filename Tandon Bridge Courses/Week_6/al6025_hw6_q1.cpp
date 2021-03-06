/*read from user a sequence of 20 integers and outputs the minimum value, and all the indices it appears in the array*/

#include "stdafx.h"
#include <iostream>
using namespace std;

const int LENGTH = 20;

int minInArray(int arr[], int arrSize);
void findIndexs(int arr[], int arrSize, int num);

int main()
{
	//input
	int ind, num;
	int arr[LENGTH];
	int min;
	cout << "Please enter 20 integers separated by a space:\n";
	for (ind  = 0;  ind < LENGTH ; ind ++)
	{
		cin >> num;
		arr[ind] = num;
	}
	
	//output
	min = minInArray(arr, LENGTH);
	cout <<"The minimun value is "<< min <<", and it is located in the following indices:";
	findIndexs(arr, LENGTH, min);
    return 0;
}

int minInArray(int arr[], int arrSize) {
	int ind;
	int min = arr[0];
	for (ind = 0; ind  < arrSize; ind ++)
	{
		if (arr[ind] < min)
			min = arr[ind];
	}
	return min;
}

void findIndexs(int arr[], int arrSize, int num) {
	for (int ind = 0; ind < arrSize; ind++)
	{
		if (arr[ind] == num)
			cout << ind << " ";
	}
}
