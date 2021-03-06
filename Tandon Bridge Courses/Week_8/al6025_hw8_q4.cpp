#include "stdafx.h"
#include <iostream>
using namespace std;
int countJump(int arr[], int arrSize, int physicalSize, int &ind );

int main()
{	
	int board[6] = { 0,3,80,6,57,10};
	int jumpPoint = 0;
	int cost = countJump(board,6,6, jumpPoint);
	cout << "The lowest cost is "<<cost << endl;
    return 0;
}

int countJump(int arr[],int arrSize,int physicalSize, int &ind ) {
	int cost;
	if (arrSize == 3)
	{
		if (arr[1] < arr[2])
		{
			ind = 1;
			return arr[ind];
		}
		else {
			ind = 2;			
			return arr[ind];
		}
	}
	else
	{
		cost = countJump(arr, arrSize - 1, physicalSize, ind);
		if (arrSize == physicalSize)
		{
			return cost + arr[physicalSize - 1];
		}
		else
		{
			if (arrSize == ind + 3)
			{
				if (arr[arrSize - 1] <= arr[arrSize - 2])
				{
					ind = arrSize - 1;
				}
				else
					ind = arrSize - 2;
				return (cost + arr[ind]);
			}
			else
				return cost;
		}
	}
		
	
}