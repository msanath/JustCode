#include <iostream>
#include <fstream>
#include <sstream>

#include "Node.h"
using namespace std;

NODEMAP* InitializeNodes(string inFile);
void PrintMap(NODEMAP*);

int main(int argc, char* argv[])
{
	if(argc != 13)
	{
		cout << "not enough params" << endl;
		return 0;
	}

	int parser = 1;
	int task;
	string startNode;
	string goalNode;
	string opPath;
	string opLog;
	string inFile;

	while (parser < 13)
	{
		if (strcmp (argv[parser], "-t") == 0)
		{
			task = atoi(argv[parser + 1]);
		}
		else if (strcmp (argv[parser], "-s") == 0)
		{
			startNode = argv[parser + 1];
		}
		else if (strcmp (argv[parser], "-g") == 0)
		{
			goalNode = argv[parser + 1];
		}
		else if (strcmp (argv[parser], "-op") == 0)
		{
			opPath = argv[parser + 1];
		}
		else if (strcmp (argv[parser], "-ol") == 0)
		{
			opLog = argv[parser + 1];
		}
		else if (strcmp (argv[parser], "-i") == 0)
		{
			inFile = argv[parser + 1];
		}
		parser += 2;
	}

	NODEMAP* nMap = InitializeNodes(inFile);
	PrintMap(nMap);
}


NODEMAP* InitializeNodes(string inFile)
{
	NODEMAP *nMap = new NODEMAP();
	ifstream iFile(inFile.c_str());

	if(iFile.is_open())
	{
		string line;
		while(getline(iFile, line))
		{
			istringstream iss(line);
			string startNode, endNode, costString, reliabString;

			getline(iss, startNode, ',');
			getline(iss, endNode, ',');
			getline(iss, costString, ',');
			getline(iss, reliabString, ',');

			Node* n1 = new Node(endNode, atof(costString.c_str()));
			Node* n2 = new Node(startNode, atof(costString.c_str()));

			if(nMap->find(startNode) == nMap->end())
			{
				NODELIST *nList = new NODELIST();
				nMap->insert(pair<string, NODELIST*> (startNode, nList));
			}
			if(nMap->find(endNode) == nMap->end())
			{
				NODELIST *nList = new NODELIST();
				nMap->insert(pair<string, NODELIST*> (endNode, nList));	
			}

			NODELIST *node1list = nMap->find(startNode)->second;
			node1list->push_back(n1);

			NODELIST *node2list = nMap->find(endNode)->second;
			node2list->push_back(n2);
		}
	}

	return nMap;
}

void PrintMap(NODEMAP* nMap)
{
	for(NODEMAP_ITER it = nMap->begin(); it != nMap->end(); it++)
	{
		cout << (*it).first << " ----> ";
		NODELIST* nList = (*it).second;

		for(NODELIST_ITER lit = nList->begin(); lit != nList->end(); lit++)
		{
			Node* node = (*lit);
			cout << node->name << "," << node->cost << " ----> ";
		}
		cout << endl;
	}
}

