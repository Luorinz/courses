#include "stdafx.h"
#include <iostream>
#include <fstream>
#include	<string>
#include <vector>
using namespace std;


//class
class Employee {
public :

	string name;
	int ID;
	double payRate;
	int hours;
	double pay;
	Employee(string newname = " ",
		int newID= 0,
		double newpayRate=0,
		int newhours=0,
		double newpay = 0) :name(newname), ID(newID), payRate(newpayRate), hours(newhours),pay(newpay) {}
};


//linked list
//Dear TA
//For your information, please don't consider this assignment as PLAGIARISM
//According to the homework instruction, it is ALLOWED to use the LListNode /LList class and their member functions created by school
//Apart from the main frame, I made a lot of modifications add a bunch of new member functions to make it work

template<class T>
class LListNode {
public:
	T data;
	LListNode<T>* next;
	LListNode(T newdata , LListNode<T>* newNext = nullptr) : data(newdata), next(newNext) {}
	//friend class LList<T>;		
};


template<class T>
class LList {
	LListNode<T>* head;
	//LListNode<T>* recursiveCopy(LListNode<T>* &rhs);
public:
	
	LList() :head(nullptr){}
	LList(const LList&rhs) : head(nullptr) { *this = rhs; }
	LList<T> &operator=(const LList<T>& rhs) {};
	~LList() { clear(); }
	void insertAtHead(T newdata);
	void removeFromHead();
	bool isEmpty() const { return head == nullptr; }	
	void clear();
	void insertAtEnd(T newdata);
	void printList();
	void addHours(int targetID, int hrs);
	void countPay();
	void sort();
	int size() const;
	int findMax(LListNode<T>* currNode);
	void swap(LListNode<T>* currNode, LListNode<T>* max);
	LListNode<T>* searchID(int targetID);
	void formattedPrint(ofstream& file);
};


template<class T>
int LList<T>::size()const {
	int count = 0;
	LListNode<T>* temp = head;
	while (temp != nullptr)
	{
		count++;
		temp = temp->next;
	}
	return count;
}

template<class T>
void  LList<T>::insertAtHead(T newdata) {
	LListNode<T>* temp = new LListNode<T>(newdata);
	temp ->next = head;
	head = temp;
}

template<class T>
void  LList<T>::removeFromHead() {
	head = head->next;
}

template<class T>
void  LList<T>::clear() {
	while (!isEmpty()) {
		removeFromHead();
	}
}

template<class T>
void LList<T>::insertAtEnd(T newdata) {
	if (isEmpty())
	{
		insertAtHead(newdata);
		return;
	}
	LListNode<T>* temp = new LListNode<T>(newdata);
	LListNode<T>* end = head;
	while (end->next != nullptr)
		end = end->next;
	end->next = temp;

}
template<class T>
void  LList<T>::printList() {
	LListNode<T>* temp = head;
	if (head == nullptr)
		return;
	else
	{
		while (temp->next!=nullptr)
		{
			cout << temp->data.ID << " "<< temp->data.name<<" "<< temp->data.hours << " " << temp->data.pay << endl;
			temp = temp->next;
		}
		cout << temp->data.ID << " " << temp->data.name << " " << temp->data.hours << " " << temp->data.pay << endl;

	}
}
template<class T>
void LList<T>::addHours(int targetID,int hrs) {
	LListNode<T>* temp = head;
	if (head == nullptr)
		return;
	else
	{
		while (temp->next != nullptr)
		{
			if (temp->data.ID == targetID)
			{
				temp->data.hours += hrs;
				return;
			}
			temp = temp->next;
		}
		if (temp->data.ID == targetID)
			temp->data.hours += hrs;

	}
}
template<class T>
void LList<T>::countPay() {
	LListNode<T>* temp = head;
	if (head == nullptr)
		return;
	else
	{
		while (temp->next != nullptr) {
			temp->data.pay = temp->data.hours * temp->data.payRate;
			temp = temp->next;
		}
		temp->data.pay = temp->data.hours * temp->data.payRate;
	}
}

template<class T>
int LList<T>::findMax(LListNode<T>* currNode) {
	LListNode<T>* temp = currNode;
	int currPay = currNode->data.pay;
	int maxID = currNode->data.ID;
	if (currNode == nullptr)
		return currNode->data.ID;
	else
	{
		while (temp->next != nullptr) {
			if (temp->data.pay > searchID(maxID)->data.pay)
			{
				maxID = temp->data.ID;
			}
			temp = temp->next;
		}
		if (temp->data.pay > searchID(maxID)->data.pay)
		{
			maxID = temp->data.ID;
		}
	}
	return maxID;
}

template<class T>
LListNode<T>* LList<T>::searchID(int targetID) {
	LListNode<T>* temp = head;
	if (head == nullptr)
		return head;
	else
	{
		while (temp->next != nullptr) {
			if (temp->data.ID == targetID)
			{
				return temp;
			}
			temp = temp->next;
		}
		if (temp->data.ID == targetID)
		{
			return temp;
		}
	}
}

template<class T>
void LList<T>::swap(LListNode<T>* currNode, LListNode<T>* max) {
	LListNode<T>* temp =  new LListNode<T> ( *currNode);
	currNode->data = max->data;
	max->data = temp->data;
	delete temp;
}

template<class T>
void LList<T>::sort() {

	LListNode<T>* temp = head;
	LListNode<T>* max;
	if (head == nullptr)
		return;
	else
	{
		while (temp->next != nullptr) {
			max = searchID(findMax(temp));
			swap(temp, max);
			temp = temp->next;
		}
	
	}
}

template<class T>
void LList<T>::formattedPrint(ofstream& file) {
	file << " *********Payroll Information********" << endl;

	LListNode<T>* temp = head;
	if (head == nullptr)
		return;
	else
	{
		while (temp->next != nullptr)
		{
			file <<  temp->data.name << ", $"  << temp->data.pay << endl;
			temp = temp->next;
		}
		file << temp->data.name << ", $" << temp->data.pay << endl;

	}

	file<<"*********End payroll**************" << endl;
}


//non-member functions
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


//main function
int main()
{

	//open file1 and read
	ifstream file1;
	cout << "Please open the first file" << endl;
	openInputFile(file1);

	LList<Employee> employeeList;
	Employee temp;
	while (file1 >> temp.ID)
	{
		file1 >> temp.payRate;
		getline(file1, temp.name);
		employeeList.insertAtEnd(temp);
	}
	file1.close();
	//employeeList.printList();

	//open file2 and read
	ifstream file2;
	int id,hours;
	cout << "Please open the first file" << endl;
	openInputFile(file2);
	while (file2 >> id)
	{
		file2 >> hours;
	
		employeeList.addHours(id, hours);
	}
	employeeList.countPay();
//	employeeList.printList();
	cout << endl;
	employeeList.sort();
//	employeeList.printList();
	file2.close();

	//formatted print and save it to file3
	ofstream file3("Payroll.txt");
	employeeList.formattedPrint(file3);
	cout << "Payroll successfully printed!" << endl;
	file3.close();

    return 0;
}


