#include "stdafx.h"
#include <iostream>
using namespace std;

const int arrSize = 6;

void printArr(int *arr, int size);
int* getPosNums1(int* arr, int arrSize, int& outPosArrSize);
void getPosNums2(int* arr, int arrSize, int *& outPosArr, int& outPosArrSize);
int* getPosNums3(int* arr, int arrSize, int * outPosArrSizePtr);
void getPosNums4(int* arr, int arrSize, int ** outPosArrPtr, int* outPosArrSizePtr);

int main()
{
	//initialization
	int arr[arrSize] = { 3, 1,-3,0,6,4 };

	//section a 
	cout << "section a\n\n";
	int size1 = arrSize;
	int* arr1 = getPosNums1(arr, arrSize, size1);
	printArr(arr1, size1);
	delete[] arr1;

	//section b
	cout << "\nsection b\n\n";
	int size2 = arrSize;
	int* arr2 = new int[size2];
	getPosNums2(arr, arrSize, arr2, size2);
	printArr(arr2, size2);
	delete[] arr2;

	//section c
	cout << "\nsection c\n\n";
	int size3 = arrSize;
	int* sizePtr;
	sizePtr = &size3;
	int* arr3 = getPosNums3(arr, arrSize, sizePtr);
	printArr(arr3, *sizePtr);
	delete[] arr3;

	//section d
	cout << "\nsection d\n\n";
	int size4 = arrSize;
	int* sizePtr1;
	int** arrPtr;
	sizePtr1 = &size4;
	int* arr4 = new int[*sizePtr1];
	arrPtr = &arr4;
	getPosNums4(arr, arrSize, arrPtr, sizePtr1);
	printArr(*arrPtr, *sizePtr1);
	delete[] *arrPtr;

    return 0;	
}
int* getPosNums1(int* arr, int arrSize, int& outPosArrSize) {
	int* arr1 = new int[outPosArrSize];
	int count = 0;
	for (int i = 0; i < arrSize; i++)
	{
		if (arr[i] > 0)
		{
			arr1[count] = arr[i];
			count++;
		}
	}
	outPosArrSize = count;
	return arr1;
}
void getPosNums2(int* arr, int arrSize, int *& outPosArr,int& outPosArrSize) {
	int count = 0;
	for (int i = 0; i < arrSize; i++)
	{
		if (arr[i] > 0)
		{
			outPosArr[count] = arr[i];
			count++;
		}
	}
	outPosArrSize = count;
}
int* getPosNums3(int* arr, int arrSize, int *outPosArrSizePtr) {
	int* arr3 = new int[*outPosArrSizePtr];
	int count = 0;
	for (int i = 0; i < arrSize; i++)
	{
		if (arr[i] > 0)
		{
			arr3[count] = arr[i];
			count++;
		}
	}
	*outPosArrSizePtr = count;
	return arr3;
}
void getPosNums4(int* arr, int arrSize, int ** outPosArrPtr, int* outPosArrSizePtr) {
	int count = 0;
	for (int i = 0; i < arrSize; i++)
	{
		if (arr[i] > 0)
		{
			(*outPosArrPtr)[count] = arr[i];
			count++;
		}
	}
	*outPosArrSizePtr = count;
}
void printArr(int *arr, int size) {
	for (int i = 0; i < size; i++)
	{
		cout << arr[i];
		if (i != size - 1)
			cout << ", ";

	}
	cout << endl;
}

