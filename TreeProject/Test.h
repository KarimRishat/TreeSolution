#pragma once
#include <iostream>
#include "Tree.h"
namespace TreeSpace
{
	class Test
	{
	public:
		void test1() {
			Tree<int> t{ 10 };
			t.push_node(3);
			t.push_node(12);
			t.push_node(2);
			t.push_node(5);
			Node<int>* head = t.get_root();
			while (head != nullptr)
			{
				std::cout << head->val() << ', ';
				head = head->left();
			}
		}
	};
}


