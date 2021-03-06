/* multiple functions about divisors*/

#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs);
bool isPerfect(int num);


int main()
{
	//test function analyzeDividors
	int num, outCountDivs = 0, outSumDivs = 0;
	cout << "Please enter a positive integer:\n";
	cin >> num;
	analyzeDividors( num,  outCountDivs,  outSumDivs);
	cout << outCountDivs <<" " <<outSumDivs<<endl;

	//test function ifPerfect
	int num1;
	cout << "Please enter a positive integer: \n";
	cin >> num1;
	if (isPerfect(num1))
		cout << num1 << " is a perfect number" << endl;
	else
		cout<< num1 << " is not a perfect number" << endl;

	// find all perfect numbers and all pairs of amicable numbers between 2 and m
	int m;
	int count,sum;
	int sum1,sum2;
	int lastsum=0;
	cout << "Please enter a positive integer greater than 2" << endl;
	cin >> m;
	for (int i = 2; i <= m; i++)
	{
		if (isPerfect(i))
		{
			cout << i << endl;
		}
	}
	cout << endl;
	for (int k = 2; k <= m; k++)
	{
		analyzeDividors(k, count, sum);
		sum1 = sum;
		count = 0;
		sum = 0;
		analyzeDividors(sum1, count, sum);
		sum2 = sum;
		count = 0;
		sum = 0;
		if (k == sum2 and sum1 <= m and not isPerfect(k))
			if (k != lastsum){
				cout << k << " " << sum1 << endl;
				lastsum = sum1;
			}
	}

    return 0;
}

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs) {
	int count = 2;
	while (count <= sqrt(num))
	{
		if (num % count == 0)
		{
			if (count == sqrt(num))
			{
				outCountDivs += 1;
				outSumDivs += count;
			}
			else
				outCountDivs += 2;
				outSumDivs += count + num / count;
		}
		count++;
	}
	outCountDivs += 1;
	outSumDivs += 1;
}

bool isPerfect(int num) {
	int count= 0, sum= 0;
	analyzeDividors(num, count, sum);
	if (num == sum)
		return true;
	else
		return false; 
}
