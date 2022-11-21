#pragma once
#include "Node.h"
namespace TreeSpace
{
	enum Side{Parent, Left, Right};
	template <typename T>
	class Tree
	{
		Node <T>* root;
		static Node<T>* push_node(Node<T>* node, Node<T>* cur_node)
		{
			
			if (node->val < cur_node->val)
			{
				if (cur_node->left == nullptr)
				{
					node->parent = cur_node;
					cur_node->left = node;
					return node;
				}
				else {
					return push_node(node, cur_node->left);
				}
			}
			else {
				if (cur_node->right == nullptr)
				{
					node->parent = cur_node;
					cur_node->right = node;
					return node;
				}
				else
				{
					return push_node(node, cur_node->right);
				}
			}
		}

		void pop_node(Node<T> node, Node<T>* cur_node) 
		{
			Node<T>* parent = node.parent();
			if (node.is_leaf())
			{
				if (parent->left() == node) {
					parent->left() = nullptr;
				}
				else
				{
					parent->right() = nullptr;
				}
				delete node;
				return;
			}
			else {
				if (node.left() == nullptr) {
					if (parent->left() == node) {
						parent->left() = node.right();
						node.right()->parent() = parent;
					}
					else
					{
						parent->right() = node.right();
						node.right()->parent() = parent;
					}
					delete node;
					return;
				}
				else if(node.right() == nullptr){
					if (parent->left() == node) {
						parent->left() = node.left();
						node.left ()->parent() = parent;
					}
					else
					{
						parent->right() = node.left();
						node.left()->parent() = parent;
					}
					delete node;
					return;
				}
				else {
					if (parent->left() == node) {
						parent->left() = node.right();
						node.right()->parent() = parent;
					}
					else
					{
						parent->right() = node.right();
						node.right()->parent() = parent;
					}
					push_node(node.left(), parent->right());
					delete node;
					return;
				}
			}
		}


		Node <T>* find(Node<T> node, T v) {
			if (node == nullptr) return nullptr;
			if (node.val() == v)
			{
				return node;
			}
			if (node.val() > v) {
				return find(node.left(), v);
			}
			else
			{
				return find(node.right(), v);
			}
		}


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
		Node<T>* get_root()
		{
			return root;
		}

		Node<T>* set_root()
		{
			return root;
		}
		Node<T>* push_node(T v)
		{
			if (root == nullptr)
			{
				root = new Node<T>(v);
				return root;
			}
			return push_node(new Node<T>(v), root);
		}

		void pop_node(T v)
		{
			Node <T>* temp = find(v);
			if (temp == root)
			{
				pop_root();
			}
			if (temp != nullptr)
			{
				pop_node(temp, root);
			}
		}

		Node <T>* find(T v)
		{
			if (root->val == v) {
				return root;
			}
			if (root->val > v) {
				return find(root->left(), v);
			}
			else {
				return find(root->right, v)
			}
		}




	};
}


