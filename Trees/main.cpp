#include <iostream>
using namespace std;

#include "BST.h"

int main()
{
	BST *bst = new BST();

	bst->Insert(4);
	bst->Insert(2);
	bst->Insert(3);
	bst->Insert(1);
	bst->Insert(6);
	bst->Insert(5);
	bst->Insert(7);

	bst->InOrder();
	bst->PreOrder();
	bst->PostOrder();
	return 0;
}