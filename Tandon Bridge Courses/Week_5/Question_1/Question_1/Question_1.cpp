/*write a function about fibonacchi sequence*/

#include "stdafx.h"
#include <iostream>
using namespace std;

int fib(int n);
int findFib(int n);
int main()
{
	cout << "section a\n";
	//input
	int n,output;
	cout << "Please enter a positive integer:\n";
	cin >> n;
	//processing
	output = fib(n);
	//output
	cout << output << endl;

	cout << "section b\n";
	int n1,output1;
	cout << "Please enter a positive integer to find its index:\n";
	cin >> n1;
	output1 = findFib(n1);
	cout << output1 << endl;
    return 0;
}

int fib(int n) {
	int count = 3;
	int preLastNum = 1, lastNum = 1;
	int curr_num= 0;
	if (n != 2) {
		while (count <= n)
		{
			curr_num = preLastNum + lastNum;
			preLastNum = lastNum;
			lastNum = curr_num;
			count++;
		}
		return curr_num;
	}
	return 1;
}
int findFib(int n) {
	bool isFind = false;
	int count = 1;
	while (true)
	{
		if (fib(count) == n)
		{
			return count;
		}
		else
			count++;
	}
}