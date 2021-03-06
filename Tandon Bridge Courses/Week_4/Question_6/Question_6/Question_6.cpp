/*Input a positive integer n, and print all of the numbers from 1 to n that have more even digits than odd digits.*/

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	//input
	int n;
	int total_count=1;
	int even_count = 0, odd_count = 0;
	int	curr_num = 0,curr_digit = 0;
	cout << "Please enter a positive integer n: " ;
	cin >> n;

	//process
	while (total_count<=n)
	{
		curr_num = total_count;
		even_count = 0;
		odd_count = 0;
		while (curr_num > 0)
		{
			curr_digit = curr_num % 10;
			if (curr_digit %2 == 0)
			{
				even_count += 1;
			}
			else
			{
				odd_count += 1;
			}
			curr_num = curr_num / 10;
		
		}
		if (even_count > odd_count)
		{
			cout << total_count << endl;
		}
		total_count++;
	}
	//output

    return 0;
}

