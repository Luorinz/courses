// Output.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>	
#include <fstream>
using namespace std;

int main()
{
	ofstream outFile("helloWorld.txt");
	//outFile.open("helloWorld.txt");
	outFile << "Hello world! ";
	outFile.close();

    return 0;
}

