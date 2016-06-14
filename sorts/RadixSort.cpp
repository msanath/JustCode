#include <iostream>
#include <vector>
#include <list>
using namespace std;

typedef vector<list<int>*> myVector;


void InitializeVector(myVector* vec)
{
	for(int i = 0; i < 10; i++)
	{
		list<int> *mylist = new list<int>();
		vec->push_back(mylist);
	}
}

int main()
{
	vector<int> input;

	cout << "Enter number of items: ";
	int count;
	cin >> count;
	
	for (int i = 0; i < count; i++)
	{
		int element;
		cin >> element;
		input.push_back(element);
	} 

	int numberOfDigits = 3;
	int modifier = 1;

	while(numberOfDigits > 0)
	{
		myVector *vec1 = new myVector();
		InitializeVector(vec1);
		modifier *= 10;

		for (int i=0; i < input.size(); i++)
		{
			int element = input.at(i);
			int index = (element % modifier);
			if (index)
			{
				index /=(modifier/10);
			}
			vec1->at(index)->push_back(element);
		}

		input.clear();

		for (int i = 0; i < vec1->size(); i++)
		{
			list<int> *li = vec1->at(i);
			while(!li->empty())
			{
				int item = li->front();
				input.push_back(item);
				li->pop_front();
			}
		}

		delete vec1;

		numberOfDigits--;
	}

	for (int i=0; i < input.size(); i++)
	{
		cout << input[i] << "\t";
	}
	cout << endl;
}