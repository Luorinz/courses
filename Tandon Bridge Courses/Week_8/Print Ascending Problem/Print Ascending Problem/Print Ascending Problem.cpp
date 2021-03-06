/*Print ascending number*/
#include "stdafx.h"
#include <iostream>
using namespace std;
void printAsc1(int start, int end);
void printAsc2(int start, int end);
void printAsc3(int start, int end);
void printAscAndDesc(int start, int end);

int main()
{
	printAscAndDesc( 1,  10);

    return 0;
}

void printAsc1(int start, int end) {
	if (start == end)
	{
		cout << start << endl;
	}
	else
	{
		printAsc1(start, end - 1);
		cout << end << endl;
	}
}
void printAsc2(int start, int end) {
	if (start == end)
	{
		cout << start << endl;
	}
	else
	{
		cout << start << endl;
		printAsc2(start + 1, end);
	}
}
void printAsc3(int start, int end) {
	int mid;
	if (start == end)
	{
		cout << start << endl;
	}
	else
	{
		mid = (start + end) / 2;
		printAsc3(start,  mid);
		printAsc3(mid + 1, end);
	}
}
void printAscAndDesc(int start, int end) {
	if (start == end)
	{
		cout << start << endl;
	}
	else
	{
		cout << start << endl;
		printAscAndDesc(start + 1, end);
		cout << start << endl;
	}
}

