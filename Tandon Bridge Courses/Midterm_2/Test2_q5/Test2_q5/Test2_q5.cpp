#include "stdafx.h"
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int* createNumbersArray(string numsStr, int& outNumsArrSize);
int strToInt(string str);


int main()
{
	string a = "123 12  251 51215 3 5132";
	string b = "123";
	int x = strToInt(b);
	cout << x << endl;
	int x1 = a.length();
	cout << createNumbersArray(a,x1) << endl;

    return 0;
}

int* createNumbersArray(string numsStr, int& outNumsArrSize) {
	char curr_num  ;
	int numCount = 0;
	int* numsArr = new int[outNumsArrSize];
	int ind = 0;
	string tempStr;
	int num;
	for (int i = 0; i < outNumsArrSize; i++)
	{
		curr_num = numsStr[i];
		if (curr_num != ' ')
		{
			tempStr = numsStr.substr(i - numCount, numCount);
			num = strToInt(tempStr);
			numsArr[ind] = num;
			numCount = 0;
		}
		else
		{
			numCount++;
		}
	}
	return numsArr;
}
int strToInt(string str) {
	int num = 0;
	int count = 0;
	int curr_num;
	for (int i = str.length() - 1; i >=0; i--)
	{
		curr_num = str[i]-48;
		cout << curr_num << endl;
		num += pow(10, count) * curr_num;
		count++;

	}
	return num;
}
