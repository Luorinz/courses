#include "stdafx.h"
#include <iostream>
#include	<list>	
using namespace std;

template <class T>
class Stack {
	list<T> data;
public:
	void push(T newItem) { data.push_front(newItem); }
	void pop() { data.pop_front(); }
	T top()const { return *data.begin(); }
	bool isEmpty()const { return data.size() == 0; }
	int size()const { return data.size(); }
	void clear() { data.clear(); }

};

template <class T>
class Queue {
	list<T> data;
public:
	void enqueue(T newItem) { data.push_back(newItem); }
	void dequeue() { data.pop_front(); }
	T top()const { return *data.begin(); }
	bool isEmpty()const { return data.size() == 0; }
	int size()const { return data.size(); }
	void clear() { data.clear(); }

};

int main()
{
	//test code of stack
	/*
	Stack<int> numberStack;
	for (int i = 0; i < 10; i++)
	{
		numberStack.push(i + 1);
		cout << numberStack.top() << endl;
	}

	cout << endl << numberStack.size() << endl;
	for (int i = 0; i < 10; i++)
	{
		numberStack.pop();
	}
	cout << endl << numberStack.size() << endl << endl;

	for (int i = 0; i < 10; i++)
	{
		numberStack.push(i + 1);
		cout << numberStack.top() << endl;
	}
	numberStack.clear();
	cout << endl << numberStack.size() << endl;
	*/
	//test code of queue
	Queue<int> numberQueue;
	for (int i = 0; i < 10; i++)
	{
		numberQueue.enqueue(i + 1);
		cout << numberQueue.top();
	}
	cout << endl << numberQueue.size() << endl<<endl;
	for (int i = 0; i < 10; i++)
	{
		cout << numberQueue.top() << endl;

		numberQueue.dequeue();
	}

	cout << endl << numberQueue.size() << endl << endl;

	return 0;
}

