#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

string* createWordsArray(string sentence, int& outWordsArrSize);
int countWords(string str);
void printArr(string *arr, int arrSize);

int main()
{
	//initialization
	string text;
	int arrSize = 0;

	//input
	cout << "Please enter a sentence( without punctuation and words separated by a single space):\n";
	getline(cin, text);

	//process and print the result
	string *arr = createWordsArray(text, arrSize);
	cout << "The new array is ";
	printArr(arr, arrSize);
	delete[] arr;

    return 0;
}

string* createWordsArray(string sentence, int& outWordsArrSize) {
	outWordsArrSize = countWords(sentence);
	string *arr = new string[outWordsArrSize];

	int lenCount = 0,arrInd = 0;
	for (int i = 0; i < sentence.length(); i++)
	{

		if (sentence[i] == ' ' )
		{
			arr[arrInd] = sentence.substr(i - lenCount, lenCount);
			arrInd++;
			lenCount = 0;
		}
		else
			lenCount++;
		if (i == sentence.length() - 1)
		{
			arr[arrInd] = sentence.substr(i- lenCount +1, lenCount);
		}
	}

	return arr;
}
int countWords(string str) {
	int count = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ')
		{
			count++;
		}
	}
	return count + 1;
}
void printArr(string *arr, int arrSize) {
	cout << "[";
	for (int i = 0; i < arrSize; i++)
	{
		cout << "'"<<arr[i]<<"'";
		if (i != arrSize - 1)
			cout << ", ";
	}
	cout << "]" << endl;
}