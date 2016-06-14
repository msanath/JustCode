#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int>* test = new vector<int>();
	test->push_back(4);
	test->push_back(1);
	test->push_back(2);
	test->push_back(6);
	test->push_back(3);
	test->push_back(7);

	vector<int>::iterator minElement = min_element(test->begin(), test->end());
	cout << *minElement << endl;
	cout << *(test->begin()) << endl;
	sort(test->begin(), test->end());
	cout << *(test->begin()) << endl;

	if(binary_search(test->begin(), test->end(), 1))
	{
		cout << "FOUND!" << endl;
	}
	else
	{
		cout << "END" << endl;
	}

	return 1;
}