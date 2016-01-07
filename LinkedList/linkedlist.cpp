#include "linkedlist.h"
#include <cassert>
using namespace std;


Node::Node(int value) 
{
	this->next = NULL;
	this->value = value;
}

LinkedList::LinkedList()
{
	this->firstNode = NULL;
	this->nodeCount = 0;
}

bool LinkedList::AddItem(int value)
{
	if(this->nodeCount == 0)
	{
		assert(this->firstNode == NULL);
		this->firstNode = new Node(value);
		if(this->firstNode == NULL)
		{
			return 0;
		}
	}
	else 
	{
		assert(this->firstNode != NULL);
		Node* temp = this->firstNode;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new Node(value);
		if(temp->next == NULL)
		{
			return 0;
		}
	}
	this->nodeCount++;
	return 1;
}

void LinkedList::PrintList()
{
	cout << "Count of Items : " << this->nodeCount << endl;
	cout << "Items -> ";

	Node* temp = this->firstNode;
	while(temp != NULL)
	{
		cout << temp->value << "\t";
		temp = temp->next;
	}
	cout << endl;
}