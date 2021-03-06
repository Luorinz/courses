/*A program to simulate the authentication process*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

const int PIN_NUM = 5;
const int BASIC_NUM = 10;
int PIN[PIN_NUM] = { 1,2,3,4,5 };

void printArray(int arr[], int arrSize);
void generateRandom(int arr[], int arrSize);
bool ifCorrect(int PIN[], int match_arr[],int arrSize, int input[]);
void strToArr(string str, int arr[]);
bool ifArrEqual(int arr1[], int arr2[],int arrSize);

int main()
{
	//initialiazation
	int number[BASIC_NUM] = { 0,1,2,3,4,5,6,7,8,9 };
	int match[BASIC_NUM];
	cout << "Please enter your PIN according to the following mapping:\n";
	cout << "PIN:\t";
	printArray(number,BASIC_NUM);
	cout << "NUM:\t";
	generateRandom(match, BASIC_NUM);
	printArray(match, BASIC_NUM);
	
	//authentication
	string rawInput;
	int userInput[PIN_NUM];

	cin >> rawInput;
	strToArr(rawInput, userInput);
	if (ifCorrect(PIN,match,BASIC_NUM,userInput))
		cout << "Your PIN is correct" << endl;
	else
		cout << "Your PIN is not correct" << endl;

    return 0;
}

void printArray(int arr[], int arrSize) {
	for (int ind = 0; ind < arrSize; ind++)
	{
		cout << arr[ind] << " ";
	}
	cout << endl;
}

void generateRandom(int arr[],int arrSize) {
	srand(time(0));
	for (int ind = 0; ind < arrSize; ind++)
	{
		arr[ind] = rand() % 3 + 1;
	}
}

bool ifCorrect(int PIN[], int match_arr[],int arrSize, int input[]) {
	int key[PIN_NUM];
	for (int i = 0; i < PIN_NUM; i++)
	{
		for (int j = 0; j < arrSize; j++)
		{
			if (PIN[i] == j )
				key[i] = match_arr[j];
		}
	}
	if (ifArrEqual(key,input,PIN_NUM))
		return true;
	else
		return false;
}

void strToArr(string str, int arr[]) {
	for (int ind = 0; ind < str.length(); ind++)
	{
		arr[ind] = str[ind] - 48 ;
	}
}

bool ifArrEqual(int arr1[], int arr2[],int arrSize) {
	for (int ind = 0; ind < arrSize; ind++)
	{
		if (arr1[ind] != arr2[ind])
			return false;
	}
	return true;
}
