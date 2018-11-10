#include <iostream>
#include <stack>
#include <ctime>

using namespace std;
template <class T>
class BST;

template <class T>
class BSTNode{
	BSTNode<T>* left;
	BSTNode<T>* right;
	BSTNode<T>* parent;
	T data;
public:
	BSTNode(T newdata = T(), BSTNode<T>* newparent = nullptr, BSTNode<T>* newleft = nullptr, BSTNode<T>* newright = nullptr){
		data = newdata; parent = newparent; left = newleft; right = newright;
	}
	friend class BST < T > ;
};



template <class T>
class BST{
	BSTNode<T>* root;
	int countOfNodes;
	BSTNode<T>* recursiveCopy(const BSTNode<T>* rhs);
	void printInOrder(BSTNode<T>* ptr);
public:
	BST() :root(nullptr){}
	BST(const BST<T>& rhs) :root(nullptr){ *this = rhs; }
	~BST(){ clear(); }
	bool isEmpty(){ return root == nullptr; }
	void remove(const T& val){ remove(find(val)); }
	bool findInTree(const T& val){ return find(val) != nullptr; }
	void clear(){ while (!isEmpty()) remove(root); }
	int size(){ return countOfNodes; }

	BST<T>& operator=(const BST<T>& rhs);
	void insert(const T&);
	void remove(BSTNode<T>* ptr);
	BSTNode<T>* find(const T&);
	void printInOrder(){ if (root!=nullptr) printInOrder(root); }
};

template<class T>
void BST<T>::printInOrder(BSTNode<T>* ptr){
	if (ptr->left != nullptr)
		printInOrder(ptr->left);
	cout << ptr->data<<endl;
	if (ptr->right != nullptr)
		printInOrder(ptr->right);
}

template <class T>
BSTNode<T>* BST<T>::find(const T& val){
	BSTNode<T>* temp = root;
	while (temp != nullptr && temp->data != val){
		if (val < temp->data)
			temp = temp->left;
		else
			temp = temp->right;
	}
	return temp;
}

template <class T>
void BST<T>::remove(BSTNode<T>* ptr){
	if (ptr == nullptr) //someone asked me to remove a value that isnt in the tree... okay, done!
		return;
	if (countOfNodes == 1 && ptr == root){ //this is the last node
		countOfNodes--;
		delete root;
		root = nullptr;
	}
	else if (ptr->left == nullptr && ptr->right == nullptr){ //no children, delete and update parent
		BSTNode<T>* parent = ptr->parent;
		if (parent != nullptr){ //update the parent's child pointer
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
		if (parent != nullptr){
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
		if (parent != nullptr){
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
	else{ //the node has two children!!! - Bad
		//Replace the data with the min of the right subtree
		BSTNode<T>* temp = ptr->right;
		while (temp->left != nullptr)
			temp = temp->left;
		ptr->data = temp->data;
		remove(temp); //Recursion at its finest....ahhh!
	}
}

template <class T>
void BST<T>::insert(const T& val){
	countOfNodes++;
	if (root == nullptr){//New node is the first on the tree
		root = new BSTNode<T>(val);
		return;
	}
	else{
		BSTNode<T>* prev=root;
		BSTNode<T>* temp=root;
		while (temp != nullptr){
			prev = temp;
			if (val < temp->data)
				temp = temp->left;
			else
				temp = temp->right;
		}
		//prev is a pointer to the node on which we will insert
		if (val < prev->data){ //val will be a left child of prev
			prev->left = new BSTNode<T>(val, prev);
		}
		else
			prev->right = new BSTNode<T>(val, prev);
	}
}

template <class T>
BSTNode<T>* BST<T>::recursiveCopy(const BSTNode<T>* rhs){
	if (rhs == nullptr)
		return nullptr;
	BSTNode<T>* temp = new BSTNode<T>(rhs->data);
	temp->left = recursiveCopy(rhs->left);
	temp->right = recursiveCopy(rhs->right);
	if (temp->left!=nullptr)
		temp->left->parent = temp;
	if (temp->right)
		temp->right->parent = temp;
	return temp;
}


template <class T>
BST<T>& BST<T>::operator=(const BST<T>& rhs){
	if (this == &rhs)
		return *this;
	clear();
	root = recursiveCopy(rhs.root);
	countOfNodes = rhs.countOfNodes;
	return *this;
}

int main(){
	BST < int > t1;
	srand(time(NULL));

	for (int i = 0; i < 100; i++)
		t1.insert(rand() % 1000);
	BST<int> t2 = t1;
	
	for (int i = 0; i < 10; i++)
		t2.remove(rand() % 1000);
	t2.printInOrder();

}


int stackDemo(){
	stack<char> s;
	string input = "int main(){cout<<\"this is a test\"; int x[5]; myfunc(x[0]);}";

	for (int i=0; i < input.length(); i++){
		char c = input[i];
		if (c == '{' || c == '(' || c == '"' || c == '['){
			if (c == '"' && s.top() == '"')
				s.pop();
			else
				s.push(c);
		}
		else if (c == '}' || c == ')' || c == ']'){
			if (c == '}' && s.top() == '{')
				s.pop();
			else if (c == ')' && s.top() == '(')
				s.pop();
			else if (c == ']' && s.top() == '[')
				s.pop();
			else{
				cout << "ERROR! Found " << c << " but the top is " << s.top() << endl;
				return 1;
			}
		}
	}
	if (!s.empty())
		cout << "ERROR the stack is not empty but the string is done!" << endl;
	else{
		cout << "The code is balanced." << endl;
	}
	return 0;
}