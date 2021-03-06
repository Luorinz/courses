#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

bool ifWord(string str);
void changeToX(string& str, int startind, int len);


int main()
{
	string str;
	cout << "Please enter a line of text:\n";
	getline(cin, str);

	int wordLen = 0;
	for (int ind = 0; ind < str.length(); ind++)
	{
		if (str[ind] == ' ')
		{
			if (not ifWord(str.substr(ind - wordLen, wordLen)))
				changeToX(str,ind - wordLen, wordLen);
			wordLen = 0;

		}
		else if(ind == str.length() - 1)
		{
			wordLen++;
			if (not ifWord(str.substr(ind - wordLen +1 , wordLen)))
				changeToX(str, ind - wordLen + 1, wordLen);
		}
		else
			wordLen++;
	}
	cout << str << endl;
	
    return 0;
}

bool ifWord(string str) {
	int numCount = 0;
	for (int ind = 0; ind < str.length(); ind++)
	{
		if (str[ind] >= '0' && str[ind] <= '9')
			numCount++;
	}
	return numCount != str.length();
}

void changeToX(string& str, int startind, int len) {
	for (int ind = startind; ind < startind + len; ind++)
	{
		str[ind] = 'x';
	}
}
