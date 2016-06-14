#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> *map = new vector<int>(256, 1);
	cout << map->at(1) << endl;
}