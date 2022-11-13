#include "Tree.h"

void Tree::push_node(int val)
{
	if (v<val())
	{
		if (left() == nullptr)
			set_left(v);
		else
		{
			left()->push_node(v);
		}
	}
	else
	{
		if (right() == nullptr)
		{
			set_right(v);
		}
		else
			right->push_node(v);
	}
}
