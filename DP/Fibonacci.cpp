#include <iostream>
using namespace std;

void Fibonacci(int numberOfValues);

int main()
{	
	cout << "Enter number of Fibonacci numbers to print : " ;
	int count;
	cin >> count;

	Fibonacci(count);
}

void Fibonacci(int numberOfValues)
{

	int x1 = 1;
	int x2 = 1;

	int count = 0;
	while(count < numberOfValues)
	{
		if(count < 2)
		{
			cout << x1 << "\t";
		}
		else
		{
			int nextValue = x1 + x2;
			x2 = x1;
			x1 = nextValue;
			cout << nextValue << "\t";		
		}
		count++;
	}
	cout << endl;

}