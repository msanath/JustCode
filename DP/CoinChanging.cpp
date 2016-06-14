#include <iostream>
#include <vector>
using namespace std;

vector<int>* CoinChange(int target, vector<int>* denominations);

int main()
{
	vector<int>* denominations = new vector<int>();

	denominations->push_back(1);
	denominations->push_back(10);
	denominations->push_back(15);	

	vector<int>* resultVec = CoinChange(20, denominations);

	for (int i=0; i < resultVec->size(); i++)
	{
		cout << i << "\t";
	}
	cout << endl;

	for (int i=0; i < resultVec->size(); i++)
	{
		cout << resultVec->at(i) << "\t";
	}
	cout << endl;
}

vector<int>* CoinChange(int target, vector<int>* denominations)
{
	vector<int>* resultVec = new vector<int>(target + 1);

	for(int i=1; i < resultVec->size(); i++)
	{
		int min = 999999;

		for(int k=0; k< denominations->size(); k++)
		{
			int index = i - denominations->at(k);
			if(index >= 0)
			{
				if (min > resultVec->at(index))
				{
					min = resultVec->at(index);
				}
			}
		}
		resultVec->at(i) = 1 + min;
	}
	return resultVec;
}