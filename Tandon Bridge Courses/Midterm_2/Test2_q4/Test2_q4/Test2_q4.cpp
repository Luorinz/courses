#include "stdafx.h"
#include <iostream>
using namespace std;

int* firstPosIntsArr(int n, int* arr, int &arrSize);
void printArray(int arr[], int arrSize);

int main() {
	int n;
	int* arr;
	int arrSize;

	cout << "Please enter a positive integer:" << endl;
	cin >> n;

	arrSize = n;
	arr = new int[arrSize];
	arr = firstPosIntsArr(n, arr, arrSize);  // calling your function

	cout << "The first " << arrSize << " positive integers are: ";
	printArray(arr, arrSize);
	cout << endl;

	delete[]arr;
	return 0;
}

void printArray(int arr[], int arrSize) {
	int i;
	for (i = 0; i < arrSize; i++)
		cout << arr[i] << " ";
}

int* firstPosIntsArr(int n, int* arr, int &arrSize) {
	
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		arr[i] = i+ 1;
		count++;
	}
	arrSize = count;

	
	return arr;
}