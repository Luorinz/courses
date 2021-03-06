#include "stdafx.h"
#include <iostream>
using namespace std;	

const int MAX_INPUT = 100;

int* findMissing(int arr[], int n, int & resArrSize);
void createEmptyArr(int *&arr, int arrSize);
void inputNums(int &arrSize, int *& arr);
void printArr(int *arr, int arrSize);

int main()
{
	int arrSize = MAX_INPUT, resArrSize = MAX_INPUT;
	int* arr = new int[MAX_INPUT];
	int* missingArr = new int[MAX_INPUT];

	cout << "Please enter the array and end by -1(no more than 100)" << endl;
	cout << "The array should be in the range of size n+1" << endl;
	inputNums(arrSize, arr);
	missingArr = findMissing(arr, arrSize, resArrSize);
	cout << "For all elements less than " << arrSize << " ,the missing part is ";
	printArr(missingArr, resArrSize);
    return 0;
}

int* findMissing(int arr[], int n, int & resArrSize) {
	int* emptyArr = new int[n];
	int* missingArr = new int[resArrSize];
	int count = 0;
	createEmptyArr(emptyArr, n);

	for (int i = 0; i < n; i++)
	{
		emptyArr[arr[i] - 1]++;
	}
	for (int i = 0; i < n; i++)
	{
		if (emptyArr[i] == 0)
		{
			missingArr[count] = i + 1;
			count++;
		}
	}
	resArrSize = count;
	return missingArr;
}
void createEmptyArr(int *&arr, int arrSize) {
	for (int i = 0; i < arrSize; i++)
	{
		arr[i] = 0;
	}
}
void inputNums(int &arrSize, int *& arr) {
	int input;
	int count = 0;
	while (true)
	{
		cin >> input;
		if (input == -1)
			break;
		arr[count] = input;
		count++;
	}
	arrSize = count;
}
void printArr(int *arr, int arrSize) {
	cout << "[";
	for (int i = 0; i < arrSize; i++)
	{
		cout << arr[i];
		if (i != arrSize - 1)
			cout << ", ";
	}
	cout << "]" << endl;
}