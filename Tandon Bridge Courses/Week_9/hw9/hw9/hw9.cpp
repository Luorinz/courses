#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Settings
const int MAX_ROW = 20 ;
const int MAX_LINE = 20 ;
const int TOTAL_ROOMS = 400;
const int INITIAL_ANTS = 100;
const int INITIAL_BUGS = 5;

bool isOutOfBound(int a, int b);
bool isOccupied(int antPosArr[][MAX_ROW], int line, int row);
int* gen_random(int a);

//Class and Function declaration
class Organism
{
public:
	int line, row;	//define the position of organism
	int targetLine, targetRow;
	int breedCount;	//define the count of breed time steps

	//Member functions
	Organism() { line = 1; row = 1; breedCount = 0; }
	Organism(int a, int b, int breed = 0) :line(a), row(b), breedCount(breed) {}	//test constructor
	
	virtual void move()  const {}
	virtual void isbreed() const {}
	int getLine() {return line;}
	int getRow() {return row;}
	int getTargetL() { return targetLine; }
	int getTargetR() { return targetRow; }
	void setLine(int x) { line = x; }
	void setRow(int y) { row = y; }


};

class Ant : public Organism {
	int breedTime = 3;
	bool isDead = false;
public:
	Ant(int a, int b) :Organism( a, b) { line = a; row = b; breedCount = 0; }
	void move() {
		int randDirection;
		targetLine = line;
		targetRow = row;
		randDirection = rand() % 4 + 1;
		switch (randDirection)
		{
		case 1: // move up
			--targetLine;
			//cout << "up";
			break;
		case 2://move down
			++targetLine;
			//cout << "down";

			break;
		case 3: //move left
			--targetRow;
			//cout << "left";

			break;
		case 4://move right
			++targetRow;
			//cout << "right";

			break;
		default:
			break;
		}
		//cout << targetLine << " " << targetRow << endl;
	};
	void isbreed(int randDirection) {
		targetLine = line;
		targetRow = row;
		switch (randDirection)
		{
		case 1: // move up
			--targetLine;
			//cout << "up";
			break;
		case 2://move down
			++targetLine;
			//cout << "down";

			break;
		case 3: //move left
			--targetRow;
			//cout << "left";

			break;
		case 4://move right
			++targetRow;
		//	cout << "right";

			break;
		default:
			break;
		}
	}
	bool getIfDead() { return isDead; }
	int getBreedTime() { return breedTime; }
	void kill() { this->isDead = true; }

};

class DoodleBug : public Organism {
	int starveCount = 0;
	int starveTime = 10;
	int breedTime = 8;
	bool isDead = false;
public:
	DoodleBug(int a, int b) :Organism(a, b) { line = a; row = b; breedCount = 0; }
	int getStarveCount() {
		return this->starveCount;
	}
	void move() {
		int randDirection;
		targetLine = line;
		targetRow = row;
		randDirection = rand() % 4 + 1;
		switch (randDirection)
		{
		case 1: // move up
			--targetLine;
			//cout << "up";
			break;
		case 2://move down
			++targetLine;
			//cout << "down";

			break;
		case 3: //move left
			--targetRow;
			//cout << "left";

			break;
		case 4://move right
			++targetRow;
			//cout << "right";

			break;
		default:
			break;
		}
		//cout << targetLine << " " << targetRow << endl;
	};
	void isbreed(int randDirection) {
		targetLine = line;
		targetRow = row;
		switch (randDirection)
		{
		case 1: // move up
			--targetLine;
			//cout << "up";
			break;
		case 2://move down
			++targetLine;
			//cout << "down";

			break;
		case 3: //move left
			--targetRow;
			//cout << "left";

			break;
		case 4://move right
			++targetRow;
			//	cout << "right";

			break;
		default:
			break;
		}
	}
	bool starve() {
		if (starveCount>= this->starveTime)
		{
			this->isDead = true;
			return true;
		}
		else
		{
			++this->starveCount;
			return false;
		}
	}
	bool getIfDead() { return isDead; }
	int getBreedTime() { return breedTime; }
	void resetStarve() { this->starveCount = 0; }
	void kill() { this->isDead = true; }
};
//Function declaration

void drawBoard(int antPosArr[][MAX_ROW],int line) {
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < MAX_ROW; j++)
		{

			if (antPosArr[i][j] == 1)
				cout << "o";
			else if(antPosArr[i][j] == 2)
				cout << "X";
			else
				cout << "-";
		}
		cout << endl;
	}
}

bool isOutOfBound(int a, int b) {
	if (a <= 0 | a > MAX_LINE)
		return true;
	else if (b <= 0 | b > MAX_ROW)
		return true;
	else
		return false;
}

void ini_position( int antPosArr[][MAX_ROW], int line) {
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < MAX_ROW; j++)
		{
			antPosArr[i][j] = 0;
		}
	}
}

void updatePosition(int line,int row, int* lineArr, int *rowArr) {
	for (int i = 0; i < MAX_LINE; i++)
	{
		lineArr[line - 1] = 1;
	}
	for (int i = 0; i < MAX_ROW; i++)
	{
		rowArr[row - 1] = 1;
	}
}

int get_rand_line() {
	int line;
	line = rand() % MAX_LINE + 1;
	return line;
}

int get_rand_row() {
	int row;
	row = rand() % MAX_ROW+ 1;
	return row;
}

bool isOccupied(int antPosArr[][MAX_ROW],int line, int row) {
	if (antPosArr[line][row] != 0)
		return true;
	else
		return false;
}
void checkMove(Ant &ant1,int antPosArr[][MAX_ROW], int TargeLine, int TargetRow) {
	if (isOutOfBound(TargeLine, TargetRow) == false && isOccupied(antPosArr, TargeLine, TargetRow) == false)
	{
		ant1.setLine(TargeLine) ;
		ant1.setRow(TargetRow);
	}
}
void checkMoveBug(DoodleBug &ant1, int antPosArr[][MAX_ROW], int TargeLine, int TargetRow) {

	if (isOutOfBound(TargeLine, TargetRow) == false && isOccupied(antPosArr, TargeLine, TargetRow) == false)
	{
		ant1.setLine(TargeLine);
		ant1.setRow(TargetRow);
	}
	
}

bool checkBreed(Ant &ant1, int antPosArr[][MAX_ROW], int MAX_LINE) {
	if (ant1.breedCount >= ant1.getBreedTime())
	{
		int* randList = gen_random(4);
		int randDirection;
		int count = 0;
		while (count < 4)
		{
			randDirection = randList[count];
			ant1.isbreed(randDirection);
			if (isOutOfBound(ant1.getTargetL(), ant1.getTargetL()) == false && isOccupied(antPosArr, ant1.getTargetL(), ant1.getTargetL()) == false)
			{

				ant1.breedCount = 0;
				return true;
				break;
			}
			else
				++count;
		}
		return false;
	}
	else
		++ant1.breedCount;
		return false;
}
bool checkBreedBug(DoodleBug &ant1, int antPosArr[][MAX_ROW], int MAX_LINE) {
	if (ant1.breedCount >= ant1.getBreedTime())
	{
		int* randList = gen_random(4);
		int randDirection;
		int count = 0;
		while (count < 4)
		{
			randDirection = randList[count];
			ant1.isbreed(randDirection);
			if (isOutOfBound(ant1.getTargetL(), ant1.getTargetL()) == false && isOccupied(antPosArr, ant1.getTargetL(), ant1.getTargetL()) == false)
			{

				ant1.breedCount = 0;
				return true;
				break;
			}
			else
				++count;
		}
		return false;
	}
	else
		++ant1.breedCount;
		return false;
}

bool isAntAround(DoodleBug &bug1, int antPosArr[][MAX_ROW], int MAX_LINE) {
	int* randList = gen_random(4);
	int randint;
	int targetLine = bug1.getLine();
	int targetRow = bug1.getRow();

	for (int i = 0; i < 4; i++)
	{
		randint = randList[i];
		switch (randint)
			{
			case 1:
				--targetLine;
				break;
			case 2://move down
				++targetLine;

				break;
			case 3: //move left
				--targetRow;

				break;
			case 4://move right
				++targetRow;

				break;
			default:
				break;
			}
		if (antPosArr[targetLine][targetRow] == 1)
		{
			bug1.setLine(targetLine);
			bug1.setLine(targetLine);
			return true;
			break;
		}
	}
	return false;
}


int* gen_random(int a) {
	int* num = new int[a];
	for (int i = 0; i < a; i++)
	{
		num[i] = i + 1;
	}
	for (int i = 0; i < a; i++)
	{
		int randint = rand() % 4;
		int j = num[i];
		num[i] = num[randint];
		num[randint] = j;
	}
	return num;
}

//Main function
int main()
{
	//generate random
	srand((unsigned)time(NULL));


	//initialization
	int numOfAnts = INITIAL_ANTS;
	int numOfBugs = INITIAL_BUGS;


	int posArr[MAX_LINE][MAX_ROW];
	Ant* antArr[TOTAL_ROOMS];
	DoodleBug* bugArr[TOTAL_ROOMS];

	int randLine = 0, randRow = 0;
	int timeStep = 0;
	while (timeStep <= 50)
	{
		if (timeStep == 0)//initialization
		{
			ini_position(posArr, MAX_LINE);

			for (int i = 0; i < numOfAnts; i++)
			{
				randLine = get_rand_line();
				randRow = get_rand_row();
				antArr[i] = new Ant(randLine, randRow);
				//	cout <<"initial\n"<< antArr[i]->getLine() <<" " << antArr[i]->getRow() << endl;
				posArr[antArr[i]->getLine() - 1][antArr[i]->getRow() - 1] = 1;
			}
			for (int i = 0; i < numOfBugs; i++)
			{
				
				randLine = get_rand_line();
				randRow = get_rand_row();
				bugArr[i] = new DoodleBug(randLine, randRow);
				//	cout <<"initial\n"<< antArr[i]->getLine() <<" " << antArr[i]->getRow() << endl;
				posArr[bugArr[i]->getLine() - 1][bugArr[i]->getRow() - 1] = 2;
				
				
			}
			drawBoard(posArr, MAX_LINE);
		}
		else
		{
			cout << endl << "Current time step: " << timeStep << endl;
			
			ini_position(posArr, MAX_LINE);
			for (int i = 0; i < numOfBugs; i++)
			{
				if (bugArr[i]->getIfDead() == false)
				{
					if ( isAntAround(*bugArr[i],posArr, MAX_LINE) == true)
					{
						posArr[bugArr[i]->getLine() - 1][bugArr[i]->getRow() - 1] = 2;
						bugArr[i]->resetStarve();
						for (int j = 0; j < numOfAnts; j++)
						{
							if (antArr[j]->getLine() == bugArr[i]->getLine() && antArr[j]->getRow() == bugArr[i]->getRow())
							{
								posArr[antArr[j]->getLine() - 1][antArr[j]->getRow() - 1] = 0;
								 antArr[j]->kill();
							}
						}
					}
					else {
						bugArr[i]->move();
						checkMoveBug(*bugArr[i], posArr, bugArr[i]->getTargetL(), bugArr[i]->getTargetR());
						posArr[bugArr[i]->getLine() - 1][bugArr[i]->getRow() - 1] = 2;
						if (bugArr[i]->starve() == true)
						{
							posArr[bugArr[i]->getLine() - 1][bugArr[i]->getRow() - 1] = 0;
							bugArr[i]->kill();

						}
						else {
							if ((checkBreedBug(*bugArr[i], posArr, MAX_LINE) == true)) {

								//	ant1.setLine(ant1.getTargetL());
								//ant1.setRow(ant1.getTargetR());
								bugArr[numOfBugs] = new DoodleBug(bugArr[i]->getTargetL(), bugArr[i]->getTargetR());
								++numOfBugs;
								posArr[bugArr[i]->getLine() - 1][bugArr[i]->getRow() - 1] = 2;
							}
					}
					
					}
				}
			}

			for (int i = 0; i < numOfAnts; i++)
			{
				if (antArr[i]->getIfDead() == false) {
					antArr[i]->move();
					checkMove(*antArr[i], posArr, antArr[i]->getTargetL(), antArr[i]->getTargetR());
					//cout << antArr[i]->getLine() <<" " << antArr[i]->getRow() << endl;
					posArr[antArr[i]->getLine() - 1][antArr[i]->getRow() - 1] = 1;

					if ((checkBreed(*antArr[i], posArr, MAX_LINE) == true)) {

						//	ant1.setLine(ant1.getTargetL());
						//ant1.setRow(ant1.getTargetR());
						antArr[numOfAnts] = new Ant(antArr[i]->getTargetL(), antArr[i]->getTargetR());
						++numOfAnts;
						posArr[antArr[i]->getLine() - 1][antArr[i]->getRow() - 1] = 1;
					}
				}

				
			}

			drawBoard(posArr, MAX_ROW);


			//check doodle then move
			//ant move
			//check doodle starve
			//check doodle breed
			//check ant breed
			//draw
		}
		cout << endl << "Press Enter to the next time step" << endl;
		cin.get();
		++timeStep;
	}


	
    return 0;
}

