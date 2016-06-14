#include "BST.h"

Node::Node(int value)
{
	this->value = value;
	this->lChild = NULL;
	this->rChild = NULL;
}

Node::~Node()
{
	if(rChild)
	{
		delete rChild;
	}
	if(lChild)
	{
		delete lChild;
	}
}


BST::BST()
{
	this->totalCount = 0;
	this->root = NULL;
}

BST::~BST()
{
	if(root)
		delete root;
}

void BST::PreOrder()
{
	cout << "PreOrder : ";
	this->PreOrder(this->root);
	cout << endl;
}

void BST::PostOrder()
{
	cout << "PostOrder : ";
	this->PostOrder(this->root);
	cout << endl;
}

void BST::InOrder()
{
	cout << "InOrder : ";
	this->InOrder(this->root);
	cout << endl;
}


void BST::InOrder(Node* temp)
{
	if(temp)
	{
		cout << temp->value << "\t";
		InOrder(temp->lChild);
		InOrder(temp->rChild);
	}
}

void BST::PostOrder(Node* temp)
{
	if(temp)
	{
		PostOrder(temp->lChild);
		PostOrder(temp->rChild);
		cout << temp->value << "\t";
	}
}

void BST::PreOrder(Node* temp)
{
	if(temp)
	{
		PreOrder(temp->lChild);
		cout << temp->value << "\t";
		PreOrder(temp->rChild);
	}
}


void BST::Insert(int value)
{
	Node* nNode = new Node(value);

	if(!root)
	{
		this->root = nNode;
		return;
	}

	Node* temp = root;
	while(temp != NULL)
	{
		if(value < temp->value)
		{
			if(temp->lChild != NULL)
			{
				temp = temp->lChild;
			}
			else
			{
				temp->lChild = nNode;
				break;
			}
		}
		else
		{
			if(temp->rChild != NULL)
			{
				temp = temp->rChild;
			}
			else
			{
				temp->rChild = nNode;
				break;
			}
		}
	}
}