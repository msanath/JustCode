#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <cstdlib>
using namespace std;

#include "Node.h"
#include "BFS.h"

void InitializeNodes(string inFile);
void PrintList();

NodeMap* nMap;


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

	InitializeNodes(inFile);
	//PrintList();
	BFS(nMap, startNode, goalNode); 


}

void InitializeNodes(string inFile)
{
	nMap = new NodeMap();
	ifstream iFile (inFile.c_str());

	if (iFile.is_open())
	{
		string line;
		while(getline(iFile, line))
		{
			istringstream iss(line);
			string node1, node2, costString, relString;

			getline(iss, node1, ',');
			getline(iss, node2, ',');
			getline(iss, costString, ',');
			getline(iss, relString, ',');

			Node* n12 = new Node(node2, atof(costString.c_str()), atof(relString.c_str()));
			Node* n21 = new Node(node1, atof(costString.c_str()), atof(relString.c_str()));

			if(nMap->find(node1) == nMap->end())
			{
				NodeList *nList = new NodeList();
				nMap->insert(pair<string, NodeList*> (node1, nList));
			}
			NodeList *nList = nMap->find(node1)->second;
			nList->push_back(n12);

			if (nMap->find(node2)  == nMap->end())
			{
				NodeList *nList = new NodeList();
				nMap->insert(pair<string, NodeList*> (node2, nList));	
			}
			nList = nMap->find(node2)->second;
			nList->push_back(n21);
		}
	} 
}

void PrintList()
{
	for(NodeMap::iterator it = nMap->begin(); it != nMap->end(); it++)
	{
		cout << (*it).first << " -> ";
		NodeList *lt = (*it).second;

		for (NodeList::iterator lit = lt->begin(); lit != lt->end(); lit++) 
		{
			cout << (*lit)->name << "," << (*lit)->cost << "," << (*lit)->reliability << " -> ";
		}
		cout << endl;
	}
}
















