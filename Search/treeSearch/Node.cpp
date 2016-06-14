#include "Node.h"

Node::Node(string name, float cost, float reliability)
{
	this->name = name;
	this->cost = cost;
	this->reliability = reliability;
	this->path = new list<string>();
	this->visitedNodes = new NodeMap();
}