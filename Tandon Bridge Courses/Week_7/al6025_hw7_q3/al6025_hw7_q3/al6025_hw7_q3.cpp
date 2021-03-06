#include "stdafx.h"
#include <iostream>
using namespace std;

const int MAX_ELEMENTS = 100;

void oddsKeepEvensFlip(int arr[], int arrSize);
void printArr(int *arr, int arrSize);
void inputArr( int *arr, int &arrSize);

int main()
{
	int* arr = new int[MAX_ELEMENTS];
	int arrSize = MAX_ELEMENTS;

	inputArr(arr, arrSize);
	cout << "The old arr = ";
	printArr(arr, arrSize);
	oddsKeepEvensFlip(arr, arrSize);

	cout << "\nThe ner arr = ";
	printArr(arr, arrSize);

	delete[] arr;
    return 0;
}

void oddsKeepEvensFlip(int arr[], int arrSize) {
	int oddCount = 0, evenCount = 0;
	int *arr1 = new int[arrSize];
	for (int i = 0; i < arrSize; i++)
	{
		if (arr[i] % 2 != 0)
		{
			arr1[oddCount] = arr[i];
			oddCount++;
		}
		else
		{
			arr1[arrSize - 1 - evenCount] = arr[i];
			evenCount++;
		}
	}
	for (int i = 0; i < arrSize; i++)
	{
		arr[i] = arr1[i];
	}
	delete[] arr1;
}
void printArr(int *arr, int arrSize) {
	cout << "[";
	for (int i = 0; i < arrSize; i++)
	{
		cout << arr[i];
		if (i != arrSize -1)
			cout << ", ";
	}
	cout << "]" << endl;
}
void inputArr(int *arr, int &arrSize) {
	int count = 0;
	int input;
	cout << "Please enter the array(no more than 100 numbers), and end by -1" << endl;
	while (true) {
		cin >> input;
		if (input == -1)
		{
			break;
		}
		arr[count] = input;
		count++;
	}
	arrSize = count;
}