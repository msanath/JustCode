#include <iostream>
#include <vector>
using namespace std;

vector<int>* LongestSubSequence(vector<int>*);
int FirstIndexIncreasing(int index, vector<int>*,vector<int>*);

int main()
{
	vector<int> *sequence = new vector<int>();
	cout << "Enter number of elements: ";
	int count;
	cin >> count;

	cout << "Enter elements: "; 
	
	while(count > 0)
	{
		int element;
		cin >> element;
		sequence->push_back(element);
		count--;
	}


/*	sequence->push_back(3);
	sequence->push_back(4);
	sequence->push_back(1);
	sequence->push_back(2);
	sequence->push_back(8);
	sequence->push_back(6);
	sequence->push_back(7);
	sequence->push_back(5);
	sequence->push_back(9); */


	

	vector<int>* resultVec = LongestSubSequence(sequence);
	for (int i = 0; i < resultVec->size() - 1; i++)
	{
		cout << sequence->at(i) << "\t";
	}
	cout << endl;
	for (int i = 0; i < resultVec->size() - 1; i++)
	{
		cout << resultVec->at(i) << "\t";
	}
		cout << endl;
}

vector<int>*  LongestSubSequence(vector<int>* sequence)
{
	vector<int>* resultVec = new vector<int>(sequence->size() + 1);

	for (int i = sequence->size() - 1; i >= 0; i--)
	{
		int index = FirstIndexIncreasing(i, sequence, resultVec);
		resultVec->at(i) = 1 + resultVec->at(index);
	}	

	return resultVec;
}

int FirstIndexIncreasing(int index, vector<int>* sequence, vector<int>* resultVec)
{
	int returnIndex = sequence->size();
	int max = 0;

	for(int i = index + 1; i < sequence->size(); i++)
	{
		if(sequence->at(i) > sequence->at(index))
		{
			if(max < resultVec->at(i))
			{
				returnIndex = i;
				max = resultVec->at(i);
			}
		}
	}

	return returnIndex;
}