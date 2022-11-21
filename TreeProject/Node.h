#pragma once

namespace TreeSpace
{	
	template <typename T>
	class Node
	{
		Node <T>* its_left;
		Node* its_right;
		Node* its_parent;
		T its_val;
		size_t its_height;
	public:
#pragma region GET
		const Node* left() const { return its_left; }
		const Node* right() const { return its_right; }
		const Node* parent() const { return its_parent; }
		const T val() const { return its_val; }
#pragma endregion
#pragma region SET
		Node* left() { return its_left; }
		Node* right() { return its_right; }
		Node* parent() { return its_parent; }
		T val() { return its_val; }
#pragma endregion
		Node <T>(T val, Node* parent = nullptr, Node* left = nullptr, Node* right = nullptr)
			: its_parent{ parent }, its_left{ left }, its_right{ right }, its_val{ val } {}

		bool is_leaf() const
		{
			return left() == nullptr && right() == nullptr;
		}
		bool is_root() const
		{
			return parent() == nullptr;
		}
		
		Node* set_left(T v)
		{
			return left() = new Node(v, this);
		}

		void push_node(T v)
		{
			if (v < val())
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
		Node* set_right(T v)
		{
			return right() = new Node(v, this);
		}
		size_t height() const
		{
			size_t count = 0;
			if (left() != nullptr)
			{
				count += left()->height();
				return count++;
			}
			else
				if (right() != nullptr)
				{
					count += right()->height();
					return count++;
				}
			return count;
		}
	};

}

