#include "linkedlist.h"


int main()
{
	LinkedList* list = new LinkedList();
	list->AddItem(1);
	list->AddItem(2);
	list->PrintList();
	return 1;
}