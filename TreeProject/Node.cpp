#include "Node.h"

void Node::set_left(int v)
{
	if (its_left == nullptr)
	{
		its_left = new Node(v, this)
	}
	else
		throw std::runtime_error();
}
