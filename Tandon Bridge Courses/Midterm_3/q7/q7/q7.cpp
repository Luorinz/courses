#include "stdafx.h"
#include <iostream>
using namespace std;

class Node {

public:

	Node * next;

	int data;
	Node(Node * newnext = nullptr, int newdata= 0):next(newnext),data(newdata){}
};

class LList {
	Node* head;
public:
	LList(Node* newhead = nullptr):head(newhead){}
};

Node* getLast(Node* node) {
	if (node == nullptr)
	{
		return nullptr;
	}
	Node* temp = node;
	
	while (temp->next!= nullptr)
	{
		temp = getLast(temp->next);
	}

	return temp;
}


int main()
{


    return 0;
}

