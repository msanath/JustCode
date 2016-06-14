#include <iostream>
#include <vector>
#include <set>
using namespace std;


int main()
{
	int graph[6][6] = { {0, 1, 5, 8, 999, 999},
					    {999, 0, 999, 2, 999, 999},
					   {999,999,0,999,3,1},
					   {999,999,999,0,3,999},
					   {999,999,999,999,0,3},
					   {999,999,999,999,999,0}};

	vector<int> previousNodes(6, 0);
	vector<int> distanceArray(6, 999);
	set<int> nodes;
	nodes.insert(1);
	nodes.insert(2);
	nodes.insert(3);
	nodes.insert(4);
	nodes.insert(5);
	
	while(!nodes.empty())
	{
		int nextNode = GetMinAmongDistance(distanceArray);

		for(int i=0; i < 6; i ++)
		{
			if (i == nextNode)
			{
				continue;
			}

			if(distanceArray[i] > (distanceArray[nextNode] + graph[nextNode][i]))
			{
				distanceArray[i] = distanceArray[nextNode] + graph[nextNode][i];
				previousNodes[i] = nextNode;
			}
		}
		nodes.erase(nextNode);
	}

}