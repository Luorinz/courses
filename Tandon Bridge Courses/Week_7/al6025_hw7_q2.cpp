#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

const int NUM_OF_LETTER = 26;

void createEmptyArr(int *& arr);
void countLetters(string str, int *& arr);
bool isAnagram(string str1, string str2, int *arr1, int *arr2);

int main()
{
	//initialization
	string str1, str2;
	int *arr1 = new int[NUM_OF_LETTER];
	int *arr2 = new int[NUM_OF_LETTER];

	//input
	cout << "Please enter string 1:" << endl;
	getline(cin, str1);
	cout << "Please enter string 2:" << endl;
	getline(cin, str2);

	//process the input and print the result
	if (isAnagram(str1, str2, arr1, arr2))
		cout << "String 1 and String 2 are anagrams" << endl;
	else
		cout << "String 1 and String 2 are not anagrams" << endl;
	
	delete[] arr1;
	delete[] arr2;

    return 0;
}
void createEmptyArr(int *& arr) {
	for (int i = 0; i < NUM_OF_LETTER; i++)
	{
		arr[i] = 0;
	}
}
void countLetters(string str, int *& arr) {
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] >= 'a' & str[i] <= 'z')
		{
			arr[str[i] - 97] ++;
		}
		if (str[i] >= 'A' & str[i] <= 'Z')
		{
			arr[str[i] - 65] ++;
		}
	}
}
bool isAnagram(string str1, string str2,int *arr1,int *arr2) {
	countLetters(str1, arr1);
	countLetters(str2, arr2);
	for (int i = 0; i < NUM_OF_LETTER; i++)
	{
		if (arr1[i] != arr2[i])
			return false;
	}
	return true;
}