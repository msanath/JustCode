#include <iostream>
#include <vector>
using namespace std;

void Print(vector<int> *a)
{
	for(vector<int>::iterator it = a->begin(); it != a->end(); it++)
	{
		cout << *it << "\t";
	}
	cout << endl;
}

void Swap (int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

int main()
{
	vector<int> *a = new vector<int>();
	a->push_back(12);
	a->push_back(13);
	a->push_back(14);
	Print(a);
	cout << a->size() << endl;
	cout << a->at(0) << endl;

	swap (a->at(0), a->at(a->size() - 1));
	Print(a);
}