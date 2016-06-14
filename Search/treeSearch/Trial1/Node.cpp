#include "Node.h"

Node::Node(string name, double cost)
{
	this->name = name;
	this->cost = cost;
	this->parsedNodes = new list<string>();
}