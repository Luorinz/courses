#include "stdafx.h"
#include <iostream>
#include <list>
using namespace std;

class Account
{
	int accountNum;
	double	 balance;

public:
	Account(int newNum=0, double newBalance=0) :accountNum(newNum), balance(newBalance) {}
	void setAccount(int num) { accountNum = num; }

	int getAccount() { return accountNum; }
	int getBalance() { return balance; }
	void deposit(double num) { balance += num; }
	virtual void withdraw(double num) { balance -= num; }
	
	virtual void monthly() = 0 {};


};

class checking : public Account {
	checking(int num) { this->setAccount(num); }
	void withdraw(double num) {
		if ((this->getBalance())>= num)
		{
			this->withdraw(num);
		}
	}
	void monthly()  {
		if ((this->getBalance() )< 5000)
		{
			if ((this->getBalance()) - 10 >= 0)
			{
				this->withdraw(10);

			}
			else
				this->withdraw(this->getBalance());

		}


	}
};

class creditCard : public Account {
	creditCard(int num) { this->setAccount(num); }

	void monthly() {
		this->deposit(this->getBalance() * 0.015);
	}

};

int main()
{




    return 0;
}

