// Input.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include	<iostream>
#include	<fstream>
#include <string>
#include <vector>
using namespace std;

void openInputFile(ifstream& inFile) {
	string fileName;
	cout << "What filename?";
	cin >> fileName;
	inFile.open(fileName);
	while (!inFile)
	{
		cout << "FILE FAILED TO OPEN!" << endl;
		cout << "What filename?";
		cin >> fileName;
		inFile.clear();
		inFile.open(fileName);
	}
}

class Student {
public:
	int id;
	double testScore;
	string name;
};

int main()
{
	ifstream inFile;
	openInputFile(inFile);
	
	//How to calculate the average of an array from a file
	/*
	vector<int> v;
	int temp;
	
	while (inFile >> temp)
	{
		v.push_back(temp);
	
	}
	double sum =0;
	for (int item : v) {
		sum += item;
		cout << item << endl;;
	}
	cout << "The average of the integers in the file is : " << sum / v.size() << endl;
	*/

	//how to find students have points more than 95

	vector<Student> vs;
	Student temp;
	while (inFile >> temp.id) {
		inFile >> temp.testScore;
		inFile.ignore(9999, '\t');
		getline(inFile, temp.name);
		vs.push_back(temp);
	}
	cout << "Students with test scores over 90: " << endl;
	for (Student s : vs) {
		if (s.testScore > 90)
		{
			cout << s.name << endl;
		}
	}
    return 0;
}

