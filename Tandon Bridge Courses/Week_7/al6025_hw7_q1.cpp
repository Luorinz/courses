#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

const int NUM_OF_LETTER = 26;

int countWords(string str);
void countLetters(string str, int *& arr);
void createEmptyArr(int *& arr);
void printResults(int wordCount, int *arr);

int main()
{
	//initialization
	string text;
	int wordCount;
	int *arr = new int[NUM_OF_LETTER];

	//input
	cout << "Please enter a line of text:\n";
	getline(cin, text);

	//count words and letters
	wordCount = countWords(text);
	createEmptyArr(arr);
	countLetters(text,arr);

	//print the result
	printResults(wordCount, arr);

	delete[] arr;
    return 0;
}
int countWords(string str) {
	int count= 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ' | str[i] == '.')
		{
			count++;
		}
	}
	if (count == 0 & str[0] != ' ')
	{
		count++;
	}
	if (str[str.length() - 1] != ' ' & str[str.length() - 1] != '.')
	{
		count++;
	}
	return count;
}
void countLetters(string str,int *& arr) {
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] >= 'a' & str[i] <='z')
		{
			arr[str[i] - 97] ++;
		}
		if (str[i] >= 'A' & str[i] <= 'Z')
		{
			arr[str[i] - 65] ++;
		}
	}
}
void createEmptyArr(int *& arr) {
	for (int i = 0; i < NUM_OF_LETTER; i++)
	{
		arr[i] = 0;
	}
}
void printResults(int wordCount, int *arr) {
	char letter;
	cout << wordCount << "\twords" << endl;
	for (int i = 0; i < NUM_OF_LETTER; i++)
	{
		if (arr[i] != 0)
		{
			letter = i + 97;
			cout<< arr[i] << "\t" <<  letter << endl;
		}
	}
}