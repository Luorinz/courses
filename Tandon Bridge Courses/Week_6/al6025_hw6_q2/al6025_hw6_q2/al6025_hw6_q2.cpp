/*Read from a user a word and return if it is palindrome*/

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string str);

int main()
{
	string str;
	int len;
	cout << "Please enter a word:";
	cin >> str;
	if (isPalindrome(str))
		cout << str << " is a palindrome" << endl;
	else
		cout << str << " is not a palindrome" << endl;
    return 0;
}

bool isPalindrome(string str) {
	string reverse;
	for (int ind = str.length() - 1; ind >= 0; ind--)
	{
		reverse += str[ind];
	}
	if (reverse == str)
		return true;
	else
		return false;
}
