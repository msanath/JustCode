#ifndef NODE
#define NODE


#include <iostream>
#include <string>
#include <list>
#include <map>
using namespace std;

class Node;
typedef list<Node*> NodeList;
typedef map<string, NodeList*> NodeMap;

class Node
{
public:
	Node(string, float, float);
	string name;
	float cost;
	float reliability;

	list<string> *path;
	NodeMap* visitedNodes;
};

typedef list<Node*> NodeList;
typedef map<string, NodeList*> NodeMap;

#endif