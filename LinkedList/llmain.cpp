#include "linkedlist.h"


int main()
{
	LinkedList* list = new LinkedList();
	list->AddItem(1);
	list->AddItem(2);

	list->PrintList();
	
	if(!list->DeleteItem(3))
	{
		cout << "Unable to delete 3" << endl;
	}

	cout << "Deleting 2" << endl;
	list->DeleteItem(2);
	list->PrintList();

	cout << "Adding 3 and 4" << endl;
	list->AddItem(3);
	list->AddItem(4);
	list->PrintList();

	cout << "deleting 3" << endl;
	list->DeleteItem(3);
	list->PrintList();

	return 1;
}