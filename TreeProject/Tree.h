#pragma once
#include "Node.h"
namespace TreeSpace
{
	enum Side{Parent, Left, Right};
	template <typename T>
	class Tree
	{
		Node <T>* root;

	public:
		Tree() noexcept
			:root{ nullptr }
		{}
		Tree(T v)
			:root{ new Node<T>{v} } {}
		const Node<T>* get_root() const
		{
			return root;
		}
		Node<T>* set_root()
		{
			return root;
		}
		Node<T>* push_node(T v)
		{

		}
	};
}


