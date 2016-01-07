#include <iostream>
using namespace std;

class Node;

class LinkedList
{
	public:
		LinkedList();
		bool AddItem(int);
		bool DeleteItem(int);
		bool CheckItem();
		void PrintList();
		~LinkedList();
	private:
		int nodeCount;
		Node* firstNode;
};

class Node
{
	private:
		Node(int); //
		int value;
		Node* next;
		friend class LinkedList;
};