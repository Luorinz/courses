// LList_Webinar.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include	<fstream>

#include <iostream>
using namespace std;
class Thing;

class Thing {
	int x;
public:
	Thing(int newx = 0):x(newx){}
	int getX()const { return x; }
	friend void myFunc(Thing& item); // not a member just a friend
	friend istream& operator>>(istream& ins, const Thing& rhs);


};

void myFunc(Thing& item) {
	item.x = 100;
}

ostream& operator<<(ostream& outs, const Thing& rhs) {
	outs <<( rhs.getX());
	return outs;
}

istream& operator>>(istream& ins, const Thing& rhs) {
	ins >> rhs.x;
	return ins;
}

int main()
{
	Thing t1;
	ofstream outFile("output.txt");
	cout << t1 << endl;
	outFile << t1 <<endl;
	cin >> t1;

    return 0;
}

