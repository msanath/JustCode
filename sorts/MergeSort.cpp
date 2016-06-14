#include <iostream>
using namespace std;

void MergeSort(int *a, int start, int end);
void Merge(int *a, int start, int mid, int end);
void PrintArray(int *a, int totalElems);

int main()
{
	int totalElems = 5;
	cout << "Enter number of elements to sort : " << endl;
	cin >> totalElems;

	int a[totalElems];
	for(int i=0; i < totalElems; i++)
	{
		cin >> a[i];
	}

	PrintArray(a, totalElems);
	MergeSort(a, 0, totalElems - 1);
	PrintArray(a, totalElems);
}

void PrintArray(int *a, int totalElems)
{
	
	for (int i=0; i < totalElems; i++)
	{
		cout << a[i] << "\t";
	}
	cout << endl;
}


void MergeSort(int *a, int start, int end)
{
	if (end > start)
	{ 
		int mid = (start + end)/2;
		{
			MergeSort(a, start, mid);
			MergeSort(a, mid + 1, end);
			Merge(a, start, mid, end);
		}
	}
}

void Merge(int *a, int start, int mid, int end)
{
	int c[end - start], k = 0;
	int i = start;
	int j = mid + 1;

	while ((i < (mid + 1)) && (j <= end))
	{
		if (a[i] < a[j])
		{
			c[k++] = a[i++];
		}
		else
		{
			c[k++] = a[j++];
		}
	}

	while(i < (mid + 1))
	{
		c[k++] = a[i++];
	}

	while (j <= end)
	{
		c[k++] = a[j++];
	}

	k = 0;

	for (i = start; i <= end; i++)
	{
		a[i] = c[k++];
	}
}