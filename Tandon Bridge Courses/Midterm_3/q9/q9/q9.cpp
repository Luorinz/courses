#include "stdafx.h"
#include <iostream>
#include <list>
using namespace std;

class StackNode {
public:
	int data;
	friend class Stack;
	StackNode(int newdata = 0) :data(newdata) {}
};

class Stack: public list<int> {
	StackNode* head;
public:
	Stack(StackNode* newhead = nullptr) :head(newhead){}
	void push(int num) { this->push_front(num); }
	void pop( ) { this->pop_front(); }
	void top() { this->pop(); }
};

template <class T>
void swap(T&a, T& b) {
	T temp = b;
	b = a;
	a = temp;

}

void selectionSort(list<int>& l) {
	list<int>* tempL = new list<int>(l);

}


void removeDuplicates(list<int>& l) {
	
	//using a stack to store the list
	//using selection sort to sort the stack
	//then go through the stack and check if duplicate and remove it
	//if the element is different from the last one, push it,otherwise skip it
	//then the stack is sorted and remove the duplicate
	//O(n) = n^2
	StackNode* head= new StackNode(l.front());
	Stack stack1(head);
	StackNode* temp = head;
	while (temp!= nullptr)
	{
		temp
	}
	
}


int main()
{
    return 0;
}

