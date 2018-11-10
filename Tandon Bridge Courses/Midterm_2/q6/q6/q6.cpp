
#include "stdafx.h"
#include <iostream>
using namespace std;
bool isZeroSumPairwiseSeq(int seq[], int seqSize);

int main()
{
	int arr[8] = {3,-7,0,6,-6,0,7,-3};

	if (isZeroSumPairwiseSeq(arr, 8))
	{
		cout << "yes" << endl;

	}
	else
		cout << "no" << endl;
    return 0;
}

bool isZeroSumPairwiseSeq(int seq[], int seqSize) {

	bool res;
	int* arr = seq;	
	if (seqSize == 0)
	{
		return true;
	}
	else
	{
		res = isZeroSumPairwiseSeq(arr, seqSize - 2);
		if (seq[0] == -1 * seq[seqSize - 1])
		{
			return true;
		}
		else if (seq[0] == 0 && seq[seqSize - 1] == 0)
		{
			return true;
		}
		else
			return false;
	}

}
