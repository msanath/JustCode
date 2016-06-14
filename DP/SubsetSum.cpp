#include <iostream>
#include <vector>
using namespace std;

int IsSubsetSum(int target, vector<int>*);

int main()
{
	vector<int> *denominations = new vector<int>();

	denominations->push_back(3);
	denominations->push_back(5);
	denominations->push_back(8);
	denominations->push_back(22);
	denominations->push_back(23);

	int target = 36;

	if(IsSubsetSum(target, denominations))
	{
		cout << "YES. POSSIBLE!" << endl;
	} 
	else
	{
		cout << "NOPE. SORRY!" << endl;
	}
	return 1;
}

int GetIndex(int Trow, int Dcolumn, int denominationSize, vector< vector<int> > resultArray, int target)
{
	if(Dcolumn == 0)
	{
		return 1;
	}
	if(Trow < 0)
	{
		return 0;
	}
	if(Dcolumn < 0)
	{
		return 0;
	}
	return resultArray[Trow][Dcolumn];
}


int IsSubsetSum(int target, vector<int>* denominations)
{
	int result = false;

	vector< vector<int> > resultVector(target+1, vector<int>(denominations->size(), 0));

	int resultArray[target + 1][denominations->size()];

	for(int j=denominations->size() - 1; j >= 0; j--)
	{
		for(int i=0; i<target + 1; i++)
		{
			int value1 = GetIndex(i - denominations->at((j)), j + 1, denominations->size(), resultVector, target);
			int value2 = GetIndex(i, j + 1, denominations->size(), resultVector, target);

			if(value1 > value2)
			{
				resultArray[i][j] = value1;
			}
			else
			{
				resultArray[i][j] = value2;
			}
		}
	}
	return result;
}