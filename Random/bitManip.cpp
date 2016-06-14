#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int tnum = 9;
	int num = tnum;
	int oneCount = 0;
	while (num > 0)
	{
		if (num & 1)
			oneCount++;
		num >>= 1;
	}

	int smallest = (1 << (oneCount)) - 1;
	cout << smallest << endl;

	int foundFirstO = 0;
	int countOfBits = 0;
	num = tnum;
	while (num > 0)
	{
		countOfBits++;
		if ((num & 1) && !foundFirstO)
		{
			foundFirstO = 1;
		}
		else if (foundFirstO && ((num & 1) == 0))
		{
			break;
		}
		num >>= 1;
	}
	num = tnum;
	int Zmask = ~(1 << (countOfBits - 2));
	int Omask = 1 << (countOfBits - 1);

	num &= Zmask;
	num |= Omask;

	cout << num << endl;
}