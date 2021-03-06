/*write a program prints a pine tree*/

#include "stdafx.h"
#include <iostream>
using namespace std;

void printShiftedTriangle(int n, int m, char symbol);
void printPineTree(int n, char symbol);

int main()
{
	//input
	int n, m;
	char symbol;
	cout << "Please enter n, m, symbol: \n";
	cin >> n >> m >> symbol;
	printShiftedTriangle(n, m, symbol);

	//input
	int n1;
	char symbol1;
	cout << "Please enter n1 and symbol1:\n";
	cin >> n1 >> symbol1;
	printPineTree(n, symbol);
    return 0;
}

void printShiftedTriangle(int n, int m, char symbol) {
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m + n - i; j++)
		{
			cout << " ";
		}
		for (int k = 1; k <= 2*i-1; k++)
		{
			cout << symbol;
		}
		cout << endl;
	}	
}
void printPineTree(int n, char symbol) {
	for (int i = 1; i <= n; i++)
	{
		printShiftedTriangle(i + 1, n - i, symbol);
	}
}

