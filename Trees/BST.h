#include <iostream>
using namespace std;

class BST;

class Node
{
protected:
	int value;
	Node* lChild;
	Node* rChild;
	
public:
	Node(int);
	~Node();
	friend class BST;
};

class BST
{
protected:
	int totalCount;
	Node* root;
	void PreOrder(Node*);
	void PostOrder(Node*);
	void InOrder(Node*);


public:
	BST();
	void Insert(int value);
	void PreOrder();
	void PostOrder();
	void InOrder();

	~BST();
};