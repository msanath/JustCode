#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string>* Subsets(string str);

int main()
{
	string str = "ABC";
	vector<string> *strPerms = Subsets(str);

	for(vector<string>::iterator it = strPerms->begin(); it != strPerms->end(); it++)
	{
		cout << *it << endl;
	}
}

vector<string>* Subsets(string str)
{
	int totalSubs = 1 << str.size();
	vector<string> *vec = new vector<string>();
	while(totalSubs)
	{
		int temp = totalSubs;
		string s;
		for(int i=0; i < str.size(); i++)
		{
			if(temp & 1)
			{
				s = s + str[i];
			}
			temp >>= 1;
		}
		vec->push_back(s);
		totalSubs--;
	}
	return vec;
} 