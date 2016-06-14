#include <iostream>
#include <list>
using namespace std;

int main()
{
	list<int> *lt = new list<int>();
	lt->push_back(4);
	lt->push_back(5);
	lt->push_back(2);
	lt->push_back(1);
	lt->push_back(5);

	for(list<int>::iterator it = lt->begin(); it != lt->end(); it++)
	{
		cout << *it << endl;
	}



}