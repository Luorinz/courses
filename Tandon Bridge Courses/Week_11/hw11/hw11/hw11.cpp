#include "stdafx.h"
#include <iostream>
#include <stack>
#include <ctime>
#include <queue>

using namespace std;
template <class T>
class BST;

template <class T>
class BSTNode {
	BSTNode<T>* left;
	BSTNode<T>* right;
	BSTNode<T>* parent;
	T data;
public:
	BSTNode(T newdata = T(), BSTNode<T>* newparent = nullptr, BSTNode<T>* newleft = nullptr, BSTNode<T>* newright = nullptr) {
		data = newdata; parent = newparent; left = newleft; right = newright; ;
	}
	int getHeight() { return height; };
	friend class BST < T >;
};



template <class T>
class BST {
	BSTNode<T>* root;
	int countOfNodes;
	BSTNode<T>* recursiveCopy(const BSTNode<T>* rhs);
	void printInOrder(BSTNode<T>* ptr);
public:
	BST() :root(nullptr) {}
	BST(const BST<T>& rhs) :root(nullptr) { *this = rhs; }
	~BST() { clear(); }
	bool isEmpty() { return root == nullptr; }
	void remove(const T& val) { remove(find(val)); }
	bool findInTree(const T& val) { return find(val) != nullptr; }
	void clear() { while (!isEmpty()) remove(root); }
	int size() { return countOfNodes; }

	BST<T>& operator=(const BST<T>& rhs);
	void remove(BSTNode<T>* ptr);
	BSTNode<T>* find(const T&);
	void printInOrder() { if (root != nullptr) printInOrder(root); }
	void insert(const T& val);


	//avl tree
	BSTNode<T>* rotation_LL(BSTNode<T>* node);
	BSTNode<T>* rotation_RR(BSTNode<T>* node);
	BSTNode<T>* rotation_LR(BSTNode<T>* node);
	BSTNode<T>* rotation_RL(BSTNode<T>* node);
	int getHeight(BSTNode<T>* node);
	BSTNode<T>* balance(BSTNode<T>* currRoot, T val);
	BSTNode<T>* getRoot() { return this->root; }
	void printLevelOrder();

};
template<class T>
void BST<T>::printLevelOrder() {
	queue<BSTNode<T>*>q;
	q.push(root);
	while (!q.empty())
	{
		BSTNode<T>* temp = q.front();
		q.pop();
		cout << temp->data << ",";
		if (temp->left != nullptr)
		{
			q.push(temp->left);
		}
		if (temp->right!= nullptr)
		{
			q.push(temp->right);
		}
	}
}


template<class T>
BSTNode<T>* BST<T>::balance(BSTNode<T>* currRoot,  T val) {
	if (currRoot == nullptr)
	{
		return nullptr;
	}

	BSTNode<T>* temp = currRoot;

	if (val < temp->data)
	{
		temp->left = balance(temp->left,val);//currRoot going left
		if (getHeight(temp->left) - getHeight(temp->right) >= 2)//when imbalance occurs
		{
			if (val < temp->left->data)//LL
			{
				temp = rotation_LL(temp);
			}
			else//LR
				temp = rotation_LR(temp);
		}
	}
	else
	{
		temp->right = balance(temp->right, val);//currRoot going right
		if (getHeight(temp->right) - getHeight(temp->left) >= 2)//when imbalance occurs
		{
			if (val >= temp->right->data)//RR
			{
				temp = rotation_RR(temp);
			}
			else//RL
				temp = rotation_RL(temp);
		}
	}
	return temp;
}


template<class T>
T getMax(T a, T b) {
	if (a >= b)
	{
		return a;
	}
	else
		return b;
}

template<class T>
int BST<T>::getHeight(BSTNode<T>* node) {//what's wrong with this function? i cannot understand why it's failed
	BSTNode<T>* temp = node;
	if (node == nullptr)
	{
		return -1;
	}

	int leftCount = 0;
	int rightCount = 0;
	int height = 0;
	if (temp->left != nullptr)
	{
		leftCount += getHeight(temp->left)+1;
	}
	if (temp->right != nullptr)
	{
		rightCount += getHeight(temp->right) + 1;
	}
	cout << "ok" << endl;
	if (leftCount >= rightCount)
	{
		height = leftCount;
	}
	else
		height = rightCount;

	return height;
}

template<class T>
BSTNode<T>* BST<T>::rotation_RL(BSTNode<T>* node)
{
	//first do a LL rotation of right child of root, then do a RR rotation of root
	node->right = rotation_LL(node->right);
	BSTNode<T>* temp = rotation_RR(node);
	return temp;

}

template<class T>
BSTNode<T>* BST<T>::rotation_LR(BSTNode<T>* node)
{
	//first do a RR rotation of left child of root, then do a LL rotation of root
	node->left = rotation_RR(node->left);
	BSTNode<T>* temp = rotation_LL(node);
	return temp;
	
}


template<class T>
BSTNode<T>* BST<T>::rotation_LL(BSTNode<T>* node)
//single right rotation of a LL situation
{
	if (node == nullptr)
	{
		return nullptr;
	}
	BSTNode<T>* temp = node->left;//define temp is the left child of root node

	temp->parent = node->parent;
	temp->right = node;//replace root with temp

	node->parent = temp;
	node->left = temp->right;//change the status of root

	node->left->parent = node; // change the status of temp's right child

	return temp;
}

template<class T>
BSTNode<T>* BST<T>::rotation_RR(BSTNode<T>* node)
//single right rotation of a RR situation, it's a mirror of LL rotation
{
	if (node == nullptr)
	{
		return nullptr;
	}
	BSTNode<T>* temp = node->right;//define temp is the right child of root node

	temp->parent = node->parent;
	temp->left = node;//replace root with temp

	node->parent = temp;
	node->right = temp->left;//change the status of root

	node->right->parent = node; // change the status of temp's left child

	return temp;

}

template<class T>
void BST<T>::printInOrder(BSTNode<T>* ptr) {
	if (ptr->left != nullptr)
		printInOrder(ptr->left);
	cout << ptr->data << endl;
	if (ptr->right != nullptr)
		printInOrder(ptr->right);
}

template <class T>
BSTNode<T>* BST<T>::find(const T& val) {
	BSTNode<T>* temp = root;
	while (temp != nullptr && temp->data != val) {
		if (val < temp->data)
			temp = temp->left;
		else
			temp = temp->right;
	}
	return temp;
}

template <class T>
void BST<T>::remove(BSTNode<T>* ptr) {
	if (ptr == nullptr) //someone asked me to remove a value that isnt in the tree... okay, done!
		return;
	if (countOfNodes == 1 && ptr == root) { //this is the last node
		countOfNodes--;
		delete root;
		root = nullptr;
	}
	else if (ptr->left == nullptr && ptr->right == nullptr) { //no children, delete and update parent
		BSTNode<T>* parent = ptr->parent;
		if (parent != nullptr) { //update the parent's child pointer
			if (ptr == parent->left)
				parent->left = nullptr;
			else
				parent->right = nullptr;
		}
		delete ptr;
		countOfNodes--;
	}
	else if (ptr->left == nullptr) { //node has a right child
		BSTNode<T>* temp = ptr->right;
		BSTNode<T>* parent = ptr->parent;
		if (parent != nullptr) {
			if (ptr == parent->left)
				parent->left = temp;
			else
				parent->right = temp;
		}
		else
			root = temp;
		temp->parent = parent;
		delete ptr;
		countOfNodes--;
	}
	else if (ptr->right == nullptr) { //node has a left child
		BSTNode<T>* temp = ptr->left;
		BSTNode<T>* parent = ptr->parent;
		if (parent != nullptr) {
			if (ptr == parent->right)
				parent->right = temp;
			else
				parent->left = temp;
		}
		else
			root = temp;
		temp->parent = parent;
		delete ptr;
		countOfNodes--;
	}
	else { //the node has two children!!! - Bad
		   //Replace the data with the min of the right subtree
		BSTNode<T>* temp = ptr->right;
		while (temp->left != nullptr)
			temp = temp->left;
		ptr->data = temp->data;
		remove(temp); //Recursion at its finest....ahhh!
	}
}

template <class T>
void BST<T>::insert(const T& val) {
	countOfNodes++;
	if (root == nullptr) {//New node is the first on the tree
		root = new BSTNode<T>(val);
		return;
	}
	else {
		BSTNode<T>* prev = root;
		BSTNode<T>* temp = root;
		while (temp != nullptr) {
			prev = temp;
			if (val < temp->data)
				temp = temp->left;
			else
				temp = temp->right;
		}
		//prev is a pointer to the node on which we will insert
		if (val < prev->data) { //val will be a left child of prev
			prev->left = new BSTNode<T>(val, prev);
		}
		else
			prev->right = new BSTNode<T>(val, prev);
	}
}

template <class T>
BSTNode<T>* BST<T>::recursiveCopy(const BSTNode<T>* rhs) {
	if (rhs == nullptr)
		return nullptr;
	BSTNode<T>* temp = new BSTNode<T>(rhs->data);
	temp->left = recursiveCopy(rhs->left);
	temp->right = recursiveCopy(rhs->right);
	if (temp->left != nullptr)
		temp->left->parent = temp;
	if (temp->right)
		temp->right->parent = temp;
	return temp;
}


template <class T>
BST<T>& BST<T>::operator=(const BST<T>& rhs) {
	if (this == &rhs)
		return *this;
	clear();
	root = recursiveCopy(rhs.root);
	countOfNodes = rhs.countOfNodes;
	return *this;
}

int main() {
	BST < int > t1;
	srand(time(NULL));
	BSTNode<int>* temp = new BSTNode<int> (111);
	int* val= new int();
	for (int i = 0; i < 100; i++)
	{
		val[i] = rand() % 1000;
		t1.insert(val[i]);
	}
	t1.printLevelOrder();

	cout << endl << endl;
	for (int i = 0; i < 100; i++)
	{
		t1.balance(t1.getRoot(),val[i]);//something wrong with getHeight(), but i cannot find out why


	}

	t1.printLevelOrder();


}

