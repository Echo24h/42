#ifndef _tree_hpp_
#define _tree_hpp_

#include <exception>
#include <algorithm>
#include <memory>
#include <csignal>
#include "iterator.hpp"
#include "utility.hpp"
#include "type_traits.hpp"
#include "algorithm.hpp"

#define RED true
#define BLACK false

namespace ft
{
	// *****************************************
	// * BSTNode
	// *****************************************
	template <typename DataType>
	struct BSTNode
	{
		DataType		data;
		bool			color;
		BSTNode *		parent;
		BSTNode *		left;
		BSTNode * 		right;

		BSTNode(DataType const & data, bool color, BSTNode * parent, BSTNode * left, BSTNode * right)
			: data(data), color(color), parent(parent), left(left), right(right)
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

		void printPtr(std::string const & pfx, void * ptr) {
			std::cout << pfx << ":" << ptr << std::endl;
		}

		void debug(std::string const & pfx = "BSTNode")
		{
			std::cout << "----\n";
			std::cout << pfx << std::endl;
			std::cout << data << std::endl;
			std::cout << "color: " << color << std::endl;
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
			node = parent;
			parent = parent->parent;
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
			node = parent;
			parent = parent->parent;
		}
		return parent;
	}

	// * return false if node is root
	template <class DataType>
	bool isLeftChild(BSTNode<DataType> * node)
	{
		if (node == nullptr || node->parent == nullptr)
			return false;
		if (node->parent->left == node)
			return true;
		return false;
	}

	template <class DataType>
	bool isRightChild(BSTNode<DataType> * node)
	{
		if (node == nullptr || node->parent == nullptr)
			return false;
		return !isLeftChild(node);
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

			pointer operator->(void) const
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
				_end = _newNode(data_type(), BLACK, nullptr, nullptr, nullptr);
				_root = _end;
			}

			BST(BST const & other)
				: _comp(other._comp)
			{
				_end = _newNode(data_type(), BLACK, nullptr, nullptr, nullptr);
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

			data_type & at(data_type const & key)
			{
				iterator pos = find(key);
				if (pos == _end)
					throw std::out_of_range("BST");
				return *pos;
			}

			data_type const & at(data_type const & key) const
			{
				const_iterator pos = find(key);
				if (pos == _end)
					throw std::out_of_range("BST");
				return *pos;
			}

			void debug(void) {
				std::cout << "----\n";
				std::cout << "_root:" << _root << std::endl;
				if (_root)
					_root->debug("root");
				else
					return ;
				if (_root->left)
					_root->left->debug("root->left");
				if (_root->right)
					_root->right->debug("root->right");
				std::cout << "----\n";
				std::cout << "_end:" << _end << std::endl;
			}

			// * return false if data is duplicate
			bool insert(data_type const & data) {
				node_pointer node = _newNode(data, RED, nullptr, nullptr, nullptr);

				node_pointer y = nullptr;
				node_pointer x = _root;

				while (x != nullptr && x != _end) {
					y = x;
					if (_comp(node->data, x->data)) {
						x = x->left;
					} else if (_comp(x->data, node->data)) {
						x = x->right;
					} else {
						_deleteNode(node);
						return false;
					}
				}

				node->parent = y;
				if (y == nullptr) {
					_root = node;
					node->right = _end;
					_end->parent = node;
				} else if (_comp(node->data, y->data)) {
					y->left = node;
				} else {
					if (y->right == _end) {
						node->right = _end;
						_end->parent = node;
					}
					y->right = node;
				}

				if (node->parent == nullptr) {
					node->color = BLACK;
				} else if (node->parent->parent != nullptr) {
					_insertFix(node);
				}
				return true;
			}

			void erase(data_type const & data) {
				node_pointer curr = _root;
				node_pointer z = nullptr;
				node_pointer x;
				node_pointer y;
				while (curr != nullptr && curr != _end) {
					if (_comp(data, curr->data)) {
						curr = curr->left;
					} else if (_comp(curr->data, data)) { 
						curr = curr->right;
					} else {
						z = curr;
						break ;
					}
				}

				if (z == nullptr || z == _end) {
					return ; // * data not found
				}

				y = z;
				bool y_original_color = y->color;
				if (z->left == nullptr) {
					// std::cout << "1\n";
					x = z->right;
					_rbTransplant(z, z->right);
				} else if (z->right == nullptr || z->right == _end) {
					// std::cout << "2\n";
					if (z->right == _end) {
						_getMax(z->left)->right = _end;
						_end->parent = z->left;
					}
					x = z->left;
					_rbTransplant(z, z->left);
				} else {
					// std::cout << "3\n";
					y = _getMin(z->right);
					y_original_color = y->color;
					x = y->right;
					if (y->parent == z) {
						if (x) // added this
							x->parent = y;
					} else {
						_rbTransplant(y, y->right);
						y->right = z->right;
						y->right->parent = y;
					}

					_rbTransplant(z, y);
					y->left = z->left;
					y->left->parent = y;
					y->color = z->color;
				}
				// std::cout << "4\n";
				_deleteNode(z);
				if (y_original_color == BLACK) {
					_deleteFix(x);
				}
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

			const_iterator find(data_type const & data) const
			{
				return const_iterator(_find(_root, data));
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

			void swap(BST & other)
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
				if (it != end() && it == find(data))
					return ++it;
				return it;
			}

			const_iterator upper_bound(data_type const & data) const
			{
				const_iterator it = lower_bound(data);
				if (it != end() && it == find(data))
					return ++it;
				return it;
			}

		private:
			node_pointer _newNode(data_type const & data,
									bool color,
									node_pointer parent,
									node_pointer left,
									node_pointer right)
			{
				node_allocator alloc;
				node_pointer node;
				node = alloc.allocate(1);
				alloc.construct(node, node_type(data, color, parent, left, right));
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

			void _rbTransplant(node_pointer u, node_pointer v)
			{
				if (u->parent == nullptr)
					_root = v;
				else if (u == u->parent->left)
					u->parent->left = v;
				else
					u->parent->right = v;
				v->parent = u->parent;
			}

			void _rotateLeft(node_pointer x)
			{
				// std::cout << "enter rotate left\n";
				node_pointer y = x->right;
				x->right = y->left;
				if (y->left)
					y->left->parent = x;
				y->parent = x->parent;
				if (x->parent == nullptr)
					_root = y;
				else if (isLeftChild(x))
					x->parent->left = y;
				else
					x->parent->right = y;
				y->left = x;
				x->parent = y;
			}

			void _rotateRight(node_pointer x)
			{
				// std::cout << "enter rotate right\n";
				node_pointer y = x->left;
				x->left = y->right;
				if (y->right != nullptr)
					y->right->parent = x;
				y->parent = x->parent;
				if (x->parent == nullptr)
					_root = y;
				else if (x == x->parent->right)
					x->parent->right = y;
				else
					x->parent->left = y;
				y->right = x;
				x->parent = y;
			}

			void _deleteFix(node_pointer x)
			{
				node_pointer s;
				while (x != _root && x->color == BLACK)
				{
					if (x == x->parent->left)
					{
						s = x->parent->right;
						if (s->color == RED)
						{
							s->color = BLACK;
							x->parent->color = RED;
							_rotateLeft(x->parent);
							s = x->parent->right;
						}
						if (s->left->color == BLACK && s->right->color == BLACK)
						{
							s->color = RED;
							x = x->parent;
						}
						else
						{
							if (s->right && s->right->color == BLACK)
							{
								s->left->color = BLACK;
								s->color = RED;
								_rotateRight(s);
								s = x->parent->right;
							}
							s->color = x->parent->color;
							x->parent->color = BLACK;
							s->right->color = BLACK;
							_rotateLeft(x->parent);
							x = _root;
						}
					}
					else
					{
						s = x->parent->left;
						if (s->color == RED)
						{
							s->color = BLACK;
							x->parent->color = RED;
							_rotateRight(x->parent);
							s = x->parent->left;
						}
						if (s->right && s->right->color == BLACK && s->right->color == BLACK)
						{
							s->color = RED;
							x = x->parent;
						}
						else
						{
							if (s->left && s->left->color == BLACK)
							{
								s->right->color = BLACK;
								s->color = RED;
								_rotateLeft(s);
								s = x->parent->left;
							}
							s->color = x->parent->color;
							x->parent->color = BLACK;
							if (s->left)
								s->left->color = BLACK;
							_rotateRight(x->parent);
							x = _root;
						}
					}
				}
				x->color = BLACK;
			}

			void _insertFix(node_pointer k)
			{
				// std::cout << "enter insert fix on node -> " << k->data.first << ":" << k->data.second << std::endl;
				node_pointer u;
				while (k->parent->color == RED)
				{
					if (k->parent == k->parent->parent->right)
					{
						// std::cout << "1\n";
						u = k->parent->parent->left;
						if (u != nullptr && u->color == RED)
						{
							// std::cout << "1.1\n";
							u->color = BLACK;
							k->parent->color = BLACK;
							k->parent->parent->color = RED;
							k = k->parent->parent;
						}
						else
						{
							// std::cout << "1.2\n";
							if (k == k->parent->left)
							{
								k = k->parent;
								_rotateRight(k);
							}
							k->parent->color = BLACK;
							k->parent->parent->color = RED;
							_rotateLeft(k->parent->parent);
						}
					}
					else
					{
						// std::cout << "2\n";
						u = k->parent->parent->right;
						if (u != nullptr && u->color == RED)
						{
							// std::cout << "2.1\n";
							u->color = BLACK;
							k->parent->color = BLACK;
							k->parent->parent->color = RED;
							k = k->parent->parent;
						}
						else
						{
							// std::cout << "2.2\n";
							if (k == k->parent->right)
							{
								k = k->parent;
								_rotateLeft(k);
							}
							k->parent->color = BLACK;
							k->parent->parent->color = RED;
							_rotateRight(k->parent->parent);
						}
					}
					if (k == _root)
						break;
				}
				_root->color = BLACK;
			}

			void _showInOrder(node_pointer root) const
			{
				if (root == nullptr || root == _end)
					return ;
				_showInOrder(root->left);
				std::cout << root->data.first << ": " << root->data.second << std::endl;
				_showInOrder(root->right);
			}

			node_pointer _find(node_pointer root, data_type const & data) const
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

			// node_pointer _erase(node_pointer root, data_type const & data)
			// {
			// 	if (!root || root == _end)
			// 		return root;
			// 	if (_comp(data, root->data))
			// 		root->left = _erase(root->left, data);
			// 	else if (_comp(root->data, data))
			// 		root->right = _erase(root->right, data);
			// 	else
			// 	{
			// 		if (root->hasNoChild())
			// 		{
			// 			_deleteNode(root);
			// 			return nullptr;
			// 		}
			// 		else if (root->hasOneChild())
			// 		{
			// 			node_pointer child = root->getChild();
			// 			if (child)
			// 				child->parent = root->parent;
			// 			_deleteNode(root);
			// 			return child;
			// 		}
			// 		else
			// 		{
			// 			node_pointer node = root->right == _end ? _getMax(root->left) : _getMin(root->right);
			// 			node_pointer tmp = root;
			// 			root = _newNode(node->data, node->color, root->parent, root->left, root->right);
			// 			root->left->parent = root;
			// 			root->right->parent = root;
			// 			_deleteNode(tmp);
			// 			if (root->right == _end)
			// 				root->left = _erase(root->left, node->data);
			// 			else
			// 				root->right = _erase(root->right, node->data);
			// 		}	
			// 	}
			// 	return root;
			// }

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
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
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