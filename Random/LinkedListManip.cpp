#include <iostream>
using namespace std;

class LinkedList;

class Node
{
	int data;
	Node* next;
	friend class LinkedList;
public:
	Node(int);
	~Node();
};

class LinkedList
{
private:
	int count;
	Node* first;
	void PrintReverse(Node*);

public:
	LinkedList();
	void AddItem(int);
	void PrintList();
	void PrintReverse();
};

Node::Node(int data)
{
	this->data = data;
	this->next = NULL;
}

Node::~Node()
{

}

LinkedList::LinkedList()
{
	this->count = 0;
	this->first = NULL;
}

void LinkedList::AddItem(int data)
{
	Node* newObj = new Node(data);

	if (!newObj)
	{
		cout << "ERROR" << endl;
		return;
	}
	this->count++;
	if(this->first == NULL)
	{
		this->first = newObj;
	}
	else
	{
		Node* cur = this->first;
		while(cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = newObj;
	}
}

void LinkedList::PrintList()
{
	Node* cur = this->first;
	while(cur != NULL)
	{
		cout << cur->data << "\t";
		cur = cur->next;
	}
	cout << endl;
}

void LinkedList::PrintReverse(Node* node)
{
	if(node == NULL)
	{
		return;
	}

	PrintReverse(node->next);
	cout << node->data << "\t";
}


void LinkedList::PrintReverse()
{
	PrintReverse(this->first);
	cout << endl;
}

int main()
{
	LinkedList *nList = new LinkedList();
	nList->AddItem(1);
	nList->AddItem(2);
	nList->AddItem(3);
	nList->AddItem(4);
	nList->PrintList();
	nList->PrintReverse();


	return 1;
}