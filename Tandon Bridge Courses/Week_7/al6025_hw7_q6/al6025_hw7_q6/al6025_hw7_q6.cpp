#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

const int MAX_INPUT = 100;

void inputNums( int &arrSize, int *& arr);
void searchNum(int num, int * arr, int arrSize, int& numOfRes, int *& results);
void printRes(int numSearch, int numOfRes, int*results);
void inputNumsV( vector<int> &arr);
void searchNumV(int numSearch, vector<int> &arr, vector<int> & results);
void printResV(int numSearch, vector<int> &results);

int main1()
{
	//initialization
	int arrSize = MAX_INPUT, numOfRes = MAX_INPUT;
	int *arr = new int[arrSize];
	int *results = new int[numOfRes];
	int numSearch;

	//input
	cout << "Please enter a sequence of positive integers, each in a separate line.\n";
	cout << "End your input by typing -1\n";
	inputNums( arrSize, arr);
	cout << "Please enter a number you want to search\n";
	cin >> numSearch;

	//process and print the result
	searchNum(numSearch, arr, arrSize, numOfRes, results);
	printRes(numSearch, numOfRes, results);

	delete[] arr;
	delete[] results;
	return 0;
}
int main2()
{
	//initialization
	vector<int> arr;
	vector<int> results;
	int numSearch;

	//input
	cout << "Please enter a sequence of positive integers, each in a separate line.\n";
	cout << "End your input by typing -1\n";
	inputNumsV(arr);

	cout << "Please enter a number you want to search\n";
	cin >> numSearch;

	//process and print the result
	searchNumV(numSearch, arr,  results);
	printResV(numSearch,  results);

	return 0;
}
int main() {
	cout << "section a " << endl;
	main1();
	cout << endl<< "section b " << endl;
	main2();
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
void searchNum(int num, int * arr,int arrSize,int& numOfRes,int *& results) {
	int count = 0;
	for (int i = 0; i < arrSize; i++)
	{
		if (arr[i] == num) {
			results[count] = i + 1;
			count++;
		}
	}
	numOfRes = count;
}
void printRes(int numSearch, int numOfRes, int*results) {
	if (numOfRes ==0)
	{
		cout << numSearch << " does not show at all in the sequence" << endl;
	}
	else {
		cout << numSearch << " shows in lines ";
		for (int i = 0; i < numOfRes; i++)
		{
			cout << results[i];
			if (i != numOfRes - 1)
				cout << ", ";
		}
		cout << ".\n";
	}
}
void inputNumsV( vector<int> &arr) {
	int input;
	while (true)
	{
		cin >> input;
		if (input == -1)
			break;
		else
		{
			arr.push_back(input);
		}
	}
}
void searchNumV(int numSearch, vector<int> &arr, vector<int> & results) {
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] == numSearch) {
			results.push_back(i + 1);
		}
	}
}
void printResV(int numSearch, vector<int> &results) {
	if (results.size() == 0)
	{
		cout << numSearch << " does not show at all in the sequence" << endl;
	}
	else {
		cout << numSearch << " shows in lines ";
		for (int i = 0; i < results.size(); i++)
		{
			cout << results[i];
			if (i != results.size() - 1)
				cout << ", ";
		}
		cout << ".\n";
	}

}