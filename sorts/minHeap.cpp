#include <iostream>
#include <vector>
using namespace std;


class MinHeap
{
	private:
		vector<int> *v;
		int GetParent(int index);
		int GetMinChild(int index);
		void PercolateUp(int index);
		void PercolateDown(int index);

	public:
		MinHeap(int heapSize);
		void Insert(int value);
		int PeekMin();
		int GetMin();
		void PrintAll();
		~MinHeap();
};

MinHeap::MinHeap(int heapSize)
{
	this->v = new vector<int>();
}

MinHeap::~MinHeap()
{
	delete this->v;
}

int MinHeap::GetParent(int index)
{
	return (index - 1)/2;
}

int MinHeap::GetMinChild(int index)
{
	int lChild = (2 * index) + 1;
	int rChild = (2 * index) + 2;

	if ((lChild <= v->size() - 1) && (v->at(index) >  v->at(lChild)))
	{
		index = lChild;
	}
	if ((rChild <= v->size() - 1) && (v->at(index) > v->at(rChild)))
	{
		index = rChild;
	}
	return index;
}

void Swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void MinHeap::PercolateUp(int index)
{
	int parent = GetParent(index);

	if ((parent < index) && v->at(parent) > v->at(index))
	{
		swap(v->at(parent), v->at(index));
		PercolateUp(parent);
	}
}

void MinHeap::PercolateDown(int index)
{
	int minChildIndex = GetMinChild(index);

	if(minChildIndex != index)
	{
		swap(v->at(minChildIndex), v->at(index));
		PercolateDown(minChildIndex);
	}
}

void MinHeap::PrintAll()
{
	cout << "Heap -> ";
	for (vector<int>::iterator it = v->begin(); it != v->end(); it++)
	{
		cout << *it << "\t";
	}
	cout << endl;
}

void MinHeap::Insert(int value)
{
	v->push_back(value);
	PercolateUp(v->size() - 1);
}


int MinHeap::PeekMin()
{
	if (v->size())
		return v->at(0);
	
	cout << "No elements in heap." << endl;
	return -1; 

}

int MinHeap::GetMin()
{
	if (!v->size())
	{
		cout << "No elements in heap." << endl;
		return -1; 		
	}

	int min = v->at(0);
	swap(v->at(0), v->at(v->size() - 1));
	v->pop_back();
	PercolateDown(0);
	return min;
}

int main()
{
	MinHeap *mh = new MinHeap(10);

	while(1)
	{
		cout << "Enter element: ";
		int element;
		cin >> element;

		if (element == -1)
			break;

		if (element == -2)
		{
			cout << "Removing Min = " << mh->GetMin() << endl;
			mh->PrintAll();
			continue;
		}

		mh->Insert(element);

		cout << "Min element = " << mh->PeekMin() << endl;
		mh->PrintAll();
	}
}