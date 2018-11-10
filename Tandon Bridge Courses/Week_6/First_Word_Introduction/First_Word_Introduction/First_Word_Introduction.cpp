/*Read from the user 3 words and prints the one that comes first in an alphabetical order*/

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string name1, name2, name3;
	cout << "Please enter 3 names separated by a space:\n";
	cin >> name1 >> name2 >> name3;

	if (name1 <= name2 && name1 <= name3)
		cout << name1 << endl;
	else if (name2 <= name1 && name2 <= name3)
		cout << name2 << endl;
	else // name3 is the smallest
		cout << name3 << endl;
    return 0;
}

