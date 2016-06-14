#include "BFS.h"

#include <list>
using namespace std;

void BFS(NodeMap* nMap, string startNode, string goalNode)
{
	QUEUE *q = new QUEUE();

	NodeList* nlist = nMap->find(startNode)->second;

	for (NodeList::iterator it = nlist->begin(); it != nlist->end(); it++)
	{
		(*it)->path->push_back(startNode);
		(*it)->visitedNodes->insert(pair<string, NodeList*> (startNode, nlist));
		q->push(*it);
	}

	cout << startNode << endl;


	while(!q->empty())
	{
		Node* firstNode = q->front();
		q->pop();
		cout << firstNode->name << endl;

		if (firstNode->name == goalNode)
		{
			cout << "END" << endl;
			cout << "Final path : ";

			for(list<string>::iterator sit = firstNode->path->begin(); sit != firstNode->path->end(); sit++)
			{
				cout << (*sit) << endl;
				cout << firstNode->name << endl;
			}
			break;
		}

		if (firstNode->visitedNodes->find(firstNode->name) != firstNode->visitedNodes->end())
		{
			continue;
		}		

		nlist = nMap->find(firstNode->name)->second;

		for (NodeList::iterator it = nlist->begin(); it != nlist->end(); it++)
		{		
			(*it)->path = new list<string>(firstNode->path->begin(), firstNode->path->end());
			(*it)->visitedNodes = new NodeMap(firstNode->visitedNodes->begin(), firstNode->visitedNodes->end());

			(*it)->path->push_back(firstNode->name);
			(*it)->visitedNodes->insert(pair<string, NodeList*> (firstNode->name, NULL));
			q->push(*it);
		}

	}
}