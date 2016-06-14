#include <iostream>
using namespace std;

void Swap(int &a, int &b);
void PrintElems(int *a, int totalElems);
int SetPivot(int *a, int start, int end);
int QuickSelect(int *a, int start, int end, int position);
void QuickSort(int *a, int start, int end);

int main()
{
	//cout << "Enter the number of elements:";
	int totalElems = 7;

	//cin >> totalElems;
	//int a[totalElems];
	int a[] = {71,65,82,35,27,96,30};

	//cout << "Enter the elements: ";
	/*for (int i=0; i < totalElems; i++)
	{
		cin >> a[i];
	} */

	PrintElems(a, totalElems);
	//QuickSort(a, 0, totalElems - 1);
	int position = QuickSelect(a, 0, totalElems - 1, 0);
	cout << "Position: " << position << endl;
	PrintElems(a, totalElems);

}


void PrintElems(int *a, int totalElems)
{
	for(int i=0; i < totalElems; i++)
	{
		cout << a[i] << "\t";
	}
	cout << endl;
}

void Swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

int SetPivot(int *a, int start, int end)
{

	if (start == end)
	{
		return start;
	}

	int pivot = a[start];
	int i = start + 1;
	int j = end;

	while (i <= j)
	{
		if (a[i] < pivot)
			i++;
		else if (a[j] > pivot)
			j--;
		else if (i < j)
		{
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}

	if ((i-1) != start)
	{
		swap (a[start], a[i-1]);
	}

	return i - 1;
}

int QuickSelect(int *a, int start, int end, int position)
{
	int pivot = SetPivot(a, start, end);

	if (pivot == position)
	{
		return a[pivot];
	}

	if (pivot < position)
	{
		return QuickSelect(a, pivot + 1, end, position);
	}
	else
	{
		return QuickSelect(a, start, pivot - 1, position);
	}
}

void QuickSort(int *a, int start, int end)
{
	int pivot = SetPivot(a, start, end);

	if (pivot != start)
		QuickSort(a, start, pivot - 1);

	if (pivot != end)
		QuickSort(a, pivot + 1, end);
}







