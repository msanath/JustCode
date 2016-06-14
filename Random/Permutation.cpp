#include <iostream>
using namespace std;

void Permutate(string str, int length);

int main()
{
	string str = "ABC";
	Permutate(str, str.size());
}

void Permutate(string str, int length)
{
	if(length == 1)
	{
		cout << str << endl;
	}
	else
	{
		for(int i=0; i < length - 1; i++)
		{
			Permutate(str, length - 1);
			swap(str[i], str[length - 1]);
		}
		Permutate(str, length - 1);
	}
}


















/*int main()
{
	char a[] = "ABC";
	Permutate(a, strlen(a));
	return 0;
}

void Output(char *a)
{
	static int counter = 1;
	cout << counter++ << " " <<  a << endl;
}

void Permutate(char *a, int length)
{
	if(length == 1)
	{
		Output(a);
	}
	else
	{
		for (int i=0; i < length - 1; i++)
		{
			Permutate(a, length - 1);
			//if (length % 2 == 0)
				swap(a[i], a[length - 1]);
			//else
			//	swap(a[0], a[length - 1]);
		}
		Permutate(a, length - 1);
	}
}
*/