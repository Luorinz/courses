/*Inplement a number guessing game*/

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;
const int TOTAL_GUESS = 5;
const int MIN = 0, MAX = 100;
int main()
{
	//initialization
	int curr_guess;
	int key;
	int lower = MIN, upper = MAX, guess_left = TOTAL_GUESS;
	bool ifCorrect = false;
	string ifBigger;
	cout << "I thought of a number between 1 and 100! Try to guess it.\n";
	srand(time(0));
	key = (rand() % 100) + 1;
	ifBigger = "";

	//inplementation
	while (guess_left > 0 and ifCorrect == false)
	{
		cout << "Range: [" << lower << ", " << upper << "], Number of guesses left: " << guess_left << endl;
		cout << "Your guess: ";
		cin >> curr_guess;
		guess_left--;
		if (curr_guess == key)
		{
			cout << "Congrats! You guessed my number in " << TOTAL_GUESS - guess_left << " guesses.\n";
			ifCorrect = true;
		}
		else
		{
			if (guess_left == 0)
			{
				cout << "Out of guesses! My number is " << key << endl;
			}
			else
			{
				if (curr_guess<key)
				{
					ifBigger = "bigger";
					if (curr_guess > lower)
					{
						lower = curr_guess + 1;
					}

				}
				else
				{
					ifBigger = "smaller";
					if (curr_guess < upper)
					{
						upper = curr_guess - 1;

					}
				}
				cout << "Wrong! My number is " << ifBigger <<"."<< endl<<endl;
			}
		}


	}


    return 0;
}

