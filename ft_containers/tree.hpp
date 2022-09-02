#ifndef _tree_hpp_
#define _tree_hpp_

#include <exception>
#include <memory>
#include <csignal>
#include "iterator.hpp"
#include "utility.hpp"
#include "type_traits.hpp"

static void printPtr(std::string const & pfx, void * ptr)
{
	std::cout << pfx << ": ";
	if (!ptr)
		std::cout << "null";
	else
		std::cout << ptr;
	std::cout << std::endl;
}

namespace ft
{
	// *****************************************
	// * BSTNode
	// *****************************************
	template <typename DataType>
	struct BSTNode
	{
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

		void debug(std::string const & pfx = "BSTNode")
		{
			std::cout << pfx << std::endl;
			std::cout << data << std::endl;
			printPtr("parent", parent);
			printPtr("left", left);
			printPtr("right", right);
		}
	};

	template <class DataType>
	BSTNode<DataType> * _getSuccessor(BSTNode<DataType> * node)
	{
		if (!node)
			return nullptr;
		if (node->right)
		{
			node = node->right;
			while (node && node->left)
				node = node->left;
			return node;
		}
		BSTNode<DataType> * parent = node->parent;
		while (parent && parent->left != node)
		{
			node = node->parent;
			parent = node->parent;
		}
		return parent;
	}

	template <class DataType>
	BSTNode<DataType> * _getPredecessor(BSTNode<DataType> * node)
	{
		if (!node)
			return nullptr;
		if (node->left)
		{
			node = node->left;
			while (node->right)
				node = node->right;
			return node;
		}
		BSTNode<DataType> * parent = node->parent;
		while (parent && parent->right != node)
		{
			node = node->parent;
			parent = node->parent;
		}
		return parent;
	}

	// *****************************************
	// * TreeIterator
	// *****************************************
	template <typename DataType>
	class BSTIterator
	{
		public:
			typedef DataType 					value_type;
			typedef ptrdiff_t 					difference_type;
			typedef value_type *				pointer;
			typedef value_type &  				reference;
			typedef bidirectional_iterator_tag	iterator_category;

			typedef BSTNode<value_type>			node_type;
			typedef node_type *					node_pointer;

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
			value_type & operator*(void) const
			{
				return _curr->data;
			}

			pointer operator->(void)
			{
				return &_curr->data;
			}

			BSTIterator & operator++()
			{
				_curr = _getSuccessor(_curr);
				if (!_curr)
					std::raise(SIGSEGV);
				return *this;
			}

			BSTIterator & operator--()
			{
				_curr = _getPredecessor(_curr);
				if (!_curr)
					std::raise(SIGSEGV);
				return *this;
			}

			BSTIterator operator++(int)
			{
				BSTIterator tmp = *this;
				*this = operator++();
				return tmp;
			}

			BSTIterator operator--(int)
			{
				BSTIterator tmp = *this;
				*this = operator--();
				return tmp;
			}

			// ---- member function(s) ----
			node_pointer base(void) const
			{
				return _curr;
			}

			friend bool operator==(BSTIterator<DataType> const & lhs, BSTIterator<DataType> const & rhs)
			{
				return lhs.base() == rhs.base();
			}

			friend bool operator!=(BSTIterator<DataType> const & lhs, BSTIterator<DataType> const & rhs)
			{
				return !(lhs == rhs);
			}
	};

	template <typename DataType>
	bool operator!=(BSTIterator<DataType> const & lhs, BSTIterator<DataType> const & rhs)
	{
		return !(lhs == rhs);
	}

	template <typename DataType>
	class BSTConstIterator
	{
		public:
			typedef DataType 					value_type;
			typedef ptrdiff_t 					difference_type;
			typedef value_type const *			pointer;
			typedef value_type const &  		reference;
			typedef bidirectional_iterator_tag	iterator_category;

			typedef BSTNode<DataType>			node_type;
			typedef node_type *					node_pointer;

		private:
			node_pointer 	_curr;

		public:
			// * ---- constructor(s) ----
			BSTConstIterator(void)
				: _curr(nullptr)
			{}

			BSTConstIterator(node_pointer ptr)
				: _curr(ptr)
			{}

			BSTConstIterator(BSTConstIterator const & src)
				: _curr(src.base())
			{}

			BSTConstIterator(BSTIterator<DataType> const & src)
				: _curr(src.base())
			{}

			// * ---- operator(s) ----
			value_type const & operator*(void) const
			{
				return _curr->data;
			}

			pointer operator->(void) const
			{
				return &_curr->data;
			}

			BSTConstIterator & operator++()
			{
				_curr = _getSuccessor(_curr);
				if (!_curr)
					std::raise(SIGSEGV);
				return *this;
			}

			BSTConstIterator & operator--()
			{
				_curr = _getPredecessor(_curr);
				if (!_curr)
					std::raise(SIGSEGV);
				return *this;
			}

			BSTConstIterator operator++(int)
			{
				BSTConstIterator tmp = *this;
				*this = operator++();
				return tmp;
			}

			BSTConstIterator operator--(int)
			{
				BSTConstIterator tmp = *this;
				*this = operator--();
				return tmp;
			}

			// ---- member function(s) ----
			node_pointer base(void) const
			{
				return _curr;
			}

			friend bool operator==(BSTConstIterator<DataType> const & lhs, BSTConstIterator<DataType> const & rhs)
			{
				return lhs.base() == rhs.base();
			}

			friend bool operator!=(BSTConstIterator<DataType> const & lhs, BSTConstIterator<DataType> const & rhs)
			{
				return !(lhs == rhs);
			}
	};

	// *****************************************
	// * BST (aka BinarySearchTree)
	// *****************************************
	template <typename DataType, typename DataCompare, typename DataAllocator>
	class BST
	{
		public:
			typedef DataType								data_type;
			typedef DataCompare								data_compare;
			typedef DataAllocator							data_allocator;
			typedef BSTNode<data_type>						node_type;
			typedef node_type *								node_pointer;
			typedef BSTIterator<data_type>					iterator;
			typedef BSTConstIterator<data_type>				const_iterator;
			typedef ft::reverse_iterator<iterator>			reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;
			typedef size_t									size_type;

			typedef typename data_allocator::template rebind<node_type>::other	node_allocator;
			
		private:
			node_pointer	_root;
			node_pointer	_end;
			data_compare	_comp;

		public:
			BST(data_compare const & c)
				: _comp(c)
			{
				_end = _newNode(data_type(), nullptr, nullptr, nullptr);
				_root = _end;
			}

			BST(BST const & other)
				: _comp(other._comp)
			{
				_end = _newNode(data_type(), nullptr, nullptr, nullptr);
				_root = _end;
				const_iterator it = other.begin();
				const_iterator ite = other.end();
				for (; it != ite; ++it)
					insert(*it);
			}

			~BST(void)
			{
				clear();
				_deleteNode(_end);
			}

			BST & operator=(BST const & other)
			{
				clear();
				const_iterator cit = other.begin();
				const_iterator cite = other.end();
				for (; cit != cite; ++cit)
					insert(*cit);
				return *this;
			}

			size_type max_size(void) const
			{
				node_allocator alloc;
				return alloc.max_size();
			}

			// * return false if data is duplicate
			bool insert(data_type const & data)
			{
				if (_root == _end)
				{
					std::cout << "kseskek\n";
					_root = _newNode(data, nullptr, nullptr, _end);
					_end->parent = _root;
					return true;
				}
				node_pointer prev = nullptr;
				node_pointer curr = _root;
				while (curr != nullptr && curr != _end)
				{
					prev = curr;
					if (_comp(data, curr->data))
						curr = curr->left;
					else if (_comp(curr->data, data))
						curr = curr->right;
					else
						return false;
				}
				if (curr == _end)
				{
					prev->right = _newNode(data, prev, nullptr, _end);
					_end->parent = prev->right;
				}
				else
				{
					if (_comp(prev->data, data))
						prev->right = _newNode(data, prev, nullptr, nullptr);
					else
						prev->left = _newNode(data, prev, nullptr, nullptr);
				}
				return true;
			}

			void showInOrder(void) const 
			{
				_showInOrder(_root);
			}

			bool empty(void) const
			{
				return _root == _end;
			}

			void clear(void)
			{
				_root = _clear(_root);
				_end->parent = nullptr;
				_root = _end;
			}

			iterator find(data_type const & data)
			{
				return iterator(_find(_root, data));
			}

			void erase(data_type const & data)
			{
				_root = _erase(_root, data);
			}

			size_type size(void) const
			{
				return _size(_root);
			}

			iterator begin(void)
			{
				node_pointer minNode = _getMin(_root);
				if (!minNode)
					return end();
				else
					return iterator(minNode);
			}

			const_iterator begin(void) const
			{
				node_pointer minNode = _getMin(_root);
				const_iterator res = minNode;
				if (!minNode)
					return end();
				else
					return res;
			}

			iterator end(void)
			{
				return iterator(_end);
			}

			const_iterator end(void) const
			{
				return const_iterator(_end);
			}

			reverse_iterator rbegin(void)
			{
				return reverse_iterator(end());
			}

			const_reverse_iterator rbegin(void) const
			{
				return reverse_iterator(end());
			}

			reverse_iterator rend(void)
			{
				return reverse_iterator(begin());
			}

			const_reverse_iterator rend(void) const
			{
				return const_reverse_iterator(begin());
			}

			void swap(BST const & other)
			{
				std::swap(_root, other._root);
				std::swap(_end, other._end);
			}

			iterator lower_bound(data_type const & data)
			{
				iterator it = begin();
				iterator ite = end();
				while (it != ite && _comp(*it, data))
					++it;
				return it;
			}

			const_iterator lower_bound(data_type const & data) const
			{
				const_iterator it = begin();
				const_iterator ite = end();
				while (it != ite && _comp(*it, data))
					++it;
				return it;
			}

			iterator upper_bound(data_type const & data)
			{
				iterator it = lower_bound(data);
				if (it.base() != _end && *it == data)
					it++;
				return it;
			}

			const_iterator upper_bound(data_type const & data) const
			{
				const_iterator it = lower_bound(data);
				if (it.base() != _end && *it == data)
					it++;
				return it;
			}

		private:
			node_pointer _newNode(data_type const & data,
									node_pointer parent,
									node_pointer left,
									node_pointer right)
			{
				node_allocator alloc;
				node_pointer node;
				node = alloc.allocate(1);
				alloc.construct(node, node_type(data, parent, left, right));
				return node;
			}

			void _deleteNode(node_pointer node)
			{
				if (node == nullptr)
					return ;
				node_allocator alloc;
				alloc.destroy(node);
				alloc.deallocate(node, 1);
			}

			node_pointer _getMin(node_pointer root) const
			{
				if (root == _end)
					return nullptr;
				while (root->left)
					root = root->left;
				return root;
			}

			node_pointer _getMax(node_pointer root) const
			{
				if (root == _end)
					return nullptr;
				while (root->right && root->right != _end)
					root = root->right;
				return root;
			}

			void _showInOrder(node_pointer root) const
			{
				if (root == nullptr || root == _end)
					return ;
				_showInOrder(root->left);
				std::cout << root->data.first << ": " << root->data.second << std::endl;
				_showInOrder(root->right);
			}

			node_pointer _find(node_pointer root, data_type const & data)
			{
				if (root == nullptr || root == _end)
					return _end;
				if (_comp(data, root->data))
					return _find(root->left, data);
				else if (_comp(root->data, data))
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
				_deleteNode(root);
				return nullptr;
			}

			node_pointer _erase(node_pointer root, data_type const & data)
			{
				if (!root || root == _end)
					return root;
				if (_comp(data, root->data))
					root->left = _erase(root->left, data);
				else if (_comp(root->data, data))
					root->right = _erase(root->right, data);
				else
				{
					if (root->hasNoChild())
					{
						_deleteNode(root);
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
						_deleteNode(root);
						return child;
					}
					else
					{
						if (root->right == _end)
						{
							node_pointer predecessor = _getMax(root->left);
							predecessor->right = _end;
							_end->parent = predecessor;
							_deleteNode(root);
							return predecessor;
						}
						else
						{
							node_pointer successor = _getMin(root->right);
							node_pointer tmp = root;
							root = _newNode(successor->data, root->parent, root->left, root->right);
							_deleteNode(tmp);
							root->right = _erase(root->right, successor->data);
						}
					}	
				}
				return root;
			}

			size_type _size(node_pointer root, size_type i = 0) const
			{
				if (!root || root == _end)
					return i;
				i++;
				i += _size(root->left);
				i += _size(root->right);
				return i;
			}
	};

	template <typename DataType, typename DataCompare, typename DataAlloc>
	bool operator==(const BST<DataType, DataCompare, DataAlloc> & lhs, const BST<DataType, DataCompare, DataAlloc> & rhs)
	{
		typedef typename BST<DataType, DataCompare, DataAlloc>::const_iterator const_iterator;
		if (lhs.size() != rhs.size())
			return false;
		const_iterator it1 = lhs.begin();
		const_iterator ite = lhs.end();
		const_iterator it_rhs = rhs.begin();
		while (it1 != ite)
		{
			if (*it1 != *it_rhs)
				return false;
			++it1;
			++it_rhs;
		}
		return true;
	}

	template <typename DataType, typename DataCompare, typename DataAlloc>
	bool operator!=(const BST<DataType, DataCompare, DataAlloc> & lhs, const BST<DataType, DataCompare, DataAlloc> & rhs)
	{
		return !(lhs == rhs);
	}

	template <typename DataType, typename DataCompare, typename DataAlloc>
	bool operator<(const BST<DataType, DataCompare, DataAlloc> & lhs, const BST<DataType, DataCompare, DataAlloc> & rhs)
	{
		typedef typename BST<DataType, DataCompare, DataAlloc>::const_iterator const_iterator;
		if (lhs.size() > rhs.size())
			return false;
		const_iterator it1 = lhs.begin();
		const_iterator ite = lhs.end();
		const_iterator it2 = rhs.begin();
		while (it1 != ite)
		{
			if (*it1 >= *it2)
				return false;
			++it1;
			++it2;
		}
		return true;
		return (lhs < rhs);
	}

	template <typename DataType, typename DataCompare, typename DataAlloc>
	bool operator<=(const BST<DataType, DataCompare, DataAlloc> & lhs, const BST<DataType, DataCompare, DataAlloc> & rhs)
	{
		return (lhs == rhs || lhs < rhs);
	}

	template <typename DataType, typename DataCompare, typename DataAlloc>
	bool operator>(const BST<DataType, DataCompare, DataAlloc> & lhs, const BST<DataType, DataCompare, DataAlloc> & rhs)
	{
		return !(lhs <= rhs);
	}

	template <typename DataType, typename DataCompare, typename DataAlloc>
	bool operator>=(const BST<DataType, DataCompare, DataAlloc> & lhs, const BST<DataType, DataCompare, DataAlloc> & rhs)
	{
		return !(lhs < rhs);
	}
}

#endif