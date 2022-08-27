#ifndef _tree_hpp_
#define _tree_hpp_

#include <exception>
#include <memory>
#include "iterator.hpp"
#include "utility.hpp"

namespace ft
{
	// *****************************************
	// * BSTNode
	// *****************************************
	// ? is it needed to allocate DataType on the heap to inforce the use of DataAllocator
	template <typename DataType, typename DataAllocator>
	struct BSTNode
	{
		typedef BSTNode														value_type;
		typedef typename DataAllocator::template rebind<value_type>::other	allocator_type;
		typedef value_type *												pointer;
		typedef DataType													data_type;

		DataType		data;
		BSTNode *		left;
		BSTNode * 		right;
		BSTNode *		parent;

		BSTNode(DataType const & data,
				BSTNode * parent,
				BSTNode * left,
				BSTNode * right)
			: data(data),
				parent(parent),
				left(left),
				right(right)
		{}

		~BSTNode(void)
		{}

		bool hasNoChild(void) const
		{ return (left == nullptr && right == nullptr); }

		bool hasTwoChild(void) const
		{ return (left != nullptr && right != nullptr); }

		bool hasOneChild(void) const
		{ return (!hasNoChild() && !hasTwoChild()); }

		BSTNode * getChild(void)
		{ return (left != nullptr ? left : right); }

		static pointer newNode(typename BSTNode<DataType, DataAllocator>::data_type const & data,
								pointer parent,
								pointer left,
								pointer right)
		{
			allocator_type alloc;
			pointer node;
			node = alloc.allocate(1);
			alloc.construct(node, value_type(data, parent, left, right));
			return node;
		}

		static void deleteNode(pointer node)
		{
			if (node == nullptr)
				return ;
			allocator_type alloc;
			alloc.destroy(node);
			alloc.deallocate(node, 1);
		}
	};

	// *****************************************
	// * TreeIterator
	// *****************************************
	template <typename NodeType>
	class BSTIterator
		: public ft::iterator<bidirectional_iterator_tag, NodeType>
	{
		public:
			// * ---- member type(s) ----
			typedef BSTIterator						value_type;
			typedef BSTIterator	&					reference;
			typedef typename NodeType::value_type	node_type;
			typedef typename NodeType::pointer		node_pointer;
			typedef typename NodeType::data_type	data_type;

		private:
			node_pointer 	_curr;

		public:
			// * ---- constructor(s) ----
			BSTIterator(void)
				: _curr(nullptr)
			{}

			BSTIterator(node_pointer ptr)
				: _curr(ptr)
			{}

			BSTIterator(BSTIterator const & src)
				: _curr(src.base())
			{}

			// * ---- operator(s) ----
			data_type const & operator*(void) const
			{ return _curr->data; }

			node_pointer operator->(void)
			{ return _curr; }

			// todo : compare my exceptions w. stl ones ; do they even throw ?
			// reference operator++()
			// {
			// 	if (!_curr)
			// 		throw std::overflow_error("ft::BSTIterator");
			// 	node_pointer successor = _getSuccessor(_curr);
			// 	if (!successor)
			// 		_isEnd = true;
			// 	else
			// 		_curr = successor;
			// 	return *this;
			// }

			// reference operator--()
			// {
			// 	if (_isEnd)
			// 		_isEnd = false;
			// 	else
			// 	{
			// 		node_pointer predecessor = _getPredecessor(_curr);
			// 		if (!predecessor)
			// 			throw std::overflow_error("ft::BSTIterator");
			// 		else
			// 			_curr = predecessor;
			// 	}
			// 	return *this;
			// }

			// value_type operator++(int)
			// {
			// 	value_type tmp = *this;
			// 	node_pointer successor = _getSuccessor(_curr);
			// 	if (!successor)
			// 		throw std::overflow_error("ft::BSTIterator");
			// 	else
			// 		_curr = successor;
			// 	return tmp;
			// }

			// value_type operator--(int)
			// {
			// 	value_type tmp = *this;
			// 	node_pointer predecessor = _getPredecessor(_curr);
			// 	if (!predecessor)
			// 		throw std::overflow_error("ft::BSTIterator");
			// 	else
			// 		_curr = predecessor;
			// 	return tmp;
			// }

			// operator BSTIterator<node_type const *>() const
			// { return BSTIterator<node_type const *>(_curr); }

			// ---- member function(s) ----
			node_pointer base(void) const
			{ return _curr; }

		private:	
			node_pointer _getSuccessor(node_pointer node)
			{
				if (!node)
					return nullptr;
				if (node->right)
				{
					while (node->right)
						node = node->right;
					return node;
				}
				node_pointer parent = node->parent;
				while (parent && parent->left != node)
				{
					node = node->parent;
					parent = node->parent;
				}
				return parent;
			}

			node_pointer _getPredecessor(node_pointer node)
			{
				if (!node)
					return nullptr;
				if (node->left)
				{
					while (node->left)
						node = node->left;
					return node;
				}
				node_pointer parent = node->parent;
				while (parent && parent->right != node)
				{
					node = node->parent;
					parent = node->parent;
				}
				return parent;
			}
	};

	template <typename Iter1, typename Iter2>
	bool operator==(BSTIterator<Iter1> const & lhs, BSTIterator<Iter2> const & rhs)
	{ return lhs.base() == rhs.base(); }

	template <typename Iter1, typename Iter2>
	bool operator!=(BSTIterator<Iter1> const & lhs, BSTIterator<Iter2> const & rhs)
	{ return !(lhs == rhs); }

	// *****************************************
	// * BST (aka BinarySearchTree)
	// *****************************************
	template <typename DataType, typename Compare, typename Allocator>
	class BST
	{
		public:
			typedef DataType							data_type;
			typedef Compare								comp;
			typedef BSTNode<DataType, Allocator>		node_type;
			typedef typename node_type::allocator_type	node_allocator;
			typedef node_type *							node_pointer;
			typedef size_t								size_type;
			typedef BSTIterator<node_type>				iterator;

		private:
			node_pointer	_root;
			node_pointer	_end;

		public:
			BST(void)
			{
				_root = node_type::newNode(data_type(), nullptr, nullptr, nullptr);
				_end = _root;
			}

			~BST(void)
			{
				clear();
				node_type::deleteNode(_end);
			}

			// * return false if data is duplicate
			bool insert(data_type const & data)
			{
				if (_root == _end)
				{
					_root = node_type::newNode(data, nullptr, nullptr, _end);
					_end->parent = _root;
					return true;
				}
				node_pointer prev = nullptr;
				node_pointer curr = _root;
				while (curr != nullptr && curr != _end)
				{
					prev = curr;
					if (comp()(data, curr->data))
						curr = curr->left;
					else if (comp()(curr->data, data))
						curr = curr->right;
					else
						return false;
				}
				if (curr == _end)
				{
					prev->right = node_type::newNode(data, prev, nullptr, _end);
					_end->parent = prev->right;
				}
				else
				{
					if (comp()(prev->data, data))
						prev->right = node_type::newNode(data, prev, nullptr, nullptr);
					else
						prev->left = node_type::newNode(data, prev, nullptr, nullptr);
				}
				return true;
			}

			// void insert(data_type const & data)
			// { _root = _insertNode(_root, data, nullptr); }

			void showInOrder(void) const 
			{ _showInOrder(_root); }

			bool empty(void) const
			{ return _root == _end; }

			void clear(void)
			{
				_root = _clear(_root);
				_end->parent = nullptr;
				_root = _end;
			}

			node_pointer find(data_type const & data)
			{ return _find(_root, data); }

			void erase(data_type const & data)
			{ _root = _erase(_root, data); }

			size_type size(void) const
			{ return _size(_root); }

			iterator begin(void)
			{
				node_pointer minNode = _getMin(_root);
				if (!minNode)
					return end();
				else
					return iterator(minNode);
			}

			iterator end(void)
			{ return iterator(_end); }

		private:
			node_pointer _getMin(node_pointer root)
			{
				if (root == _end)
					return nullptr;
				while (root->left)
					root = root->left;
				return root;
			}

			node_pointer _getMax(node_pointer root)
			{
				if (root == _end)
					return nullptr;
				while (root->right && root->right != _end)
					root = root->right;
				return root;
			}

			// // * return nullptr if data is duplicate
			// node_pointer _insertNode(node_pointer root, data_type const & data, node_pointer parent)
			// {
			// 	if (root == nullptr)
			// 		return _newNode(data, parent);
			// 	if (comp()(data, root->data))
			// 		root->left = _insertNode(root->left, data, root);
			// 	else if (comp()(root->data, data))
			// 		root->right = _insertNode(root->right, data, root);
			// 	else
			// 		return nullptr;
			// 	return root;
			// }

			void _showInOrder(node_pointer root) const
			{
				if (root == nullptr || root == _end)
					return ;
				_showInOrder(root->left);
				std::cout << root->data << std::endl;
				_showInOrder(root->right);
			}

			node_pointer _find(node_pointer root, data_type const & data)
			{
				if (root == nullptr || root == _end)
					return nullptr;
				if (comp()(data, root->data))
					return _find(root->left, data);
				else if (comp()(root->data, data))
					return _find(root->right, data);
				else
					return root;
			}

			node_pointer _clear(node_pointer root)
			{
				if (!root || root == _end)
					return nullptr;
				root->left = _clear(root->left);
				root->right = _clear(root->right);
				node_type::deleteNode(root);
				return nullptr;
			}

			node_pointer _erase(node_pointer root, data_type const & data)
			{
				if (!root || root == _end)
					return root;
				if (comp()(data, root->data))
					root->left = _erase(root->left, data);
				else if (comp()(root->data, data))
					root->right = _erase(root->right, data);
				else
				{
					if (root->hasNoChild())
					{
						node_type::deleteNode(root);
						return nullptr;
					}
					else if (root->hasOneChild())
					{
						node_pointer child = root->getChild();
						if (child == _end)
						{
							child->right = _end;
							_end->parent = child;
						}
						node_type::deleteNode(root);
						return child;
					}
					else
					{
						if (root->right == _end)
						{
							node_pointer predecessor = _getMax(root->left);
							predecessor->right = _end;
							_end->parent = predecessor;
							node_type::deleteNode(root);
							return predecessor;
						}
						else
						{
							node_pointer successor = _getMin(root->right);
							root->data = successor->data;
							root->right = _erase(root->right, successor->data);
						}
					}	
				}
				return root;
			}

			size_type _size(node_pointer root, size_type i = 0) const
			{
				if (!root)
					return i;
				i++;
				i += _size(root->left);
				i += _size(root->right);
				return i;
			}
	};
}

/*
    - o
- o
    - o
*/

#endif