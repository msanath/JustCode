#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
#include <map>
#include <list>
using namespace std;

class Node
{
public:
	string name;
	double cost;
	list<string> *parsedNodes;

	Node(string, double);
};

typedef list<Node*> NODELIST;
typedef list<Node*>::iterator NODELIST_ITER;
typedef map<string, NODELIST*> NODEMAP;
typedef map<string, NODELIST*>::iterator NODEMAP_ITER;

#endif