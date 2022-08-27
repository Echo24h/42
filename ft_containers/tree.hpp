#ifndef _tree_hpp_
#define _tree_hpp_

#include <exception>
#include <memory>
#include <csignal>
#include "iterator.hpp"
#include "utility.hpp"

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
			value_type const & operator*(void) const
			{ return _curr->data; }

			pointer operator->(void)
			{ return &_curr->data; }

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

			operator BSTIterator<value_type const>() const
			{ return BSTIterator<value_type const>(_curr); }

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
					node = node->right;
					while (node && node->left)
						node = node->left;
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
					node = node->left;
					while (node->right)
						node = node->right;
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
	template <typename DataType, typename DataCompare, typename DataAllocator>
	class BST
	{
		public:
			typedef DataType							data_type;
			typedef DataCompare							data_compare;
			typedef DataAllocator						data_allocator;
			typedef BSTNode<data_type>					node_type;
			typedef node_type *							node_pointer;
			typedef BSTIterator<data_type>				iterator;
			// typedef BSTIterator<data_type const>		const_iterator;
			typedef size_t								size_type;

			typedef typename data_allocator::template rebind<node_type>::other	node_allocator;
			
		private:
			node_pointer	_root;
			node_pointer	_end;

		public:
			BST(void)
			{
				_root = _newNode(data_type(), nullptr, nullptr, nullptr);
				_end = _root;
			}

			~BST(void)
			{
				clear();
				_deleteNode(_end);
			}

			size_type max_size(void)
			{
				node_allocator alloc;
				return alloc.max_size();
			}

			// * return false if data is duplicate
			bool insert(data_type const & data)
			{
				if (_root == _end)
				{
					_root = _newNode(data, nullptr, nullptr, _end);
					_end->parent = _root;
					return true;
				}
				node_pointer prev = nullptr;
				node_pointer curr = _root;
				while (curr != nullptr && curr != _end)
				{
					prev = curr;
					if (data_compare()(data, curr->data))
						curr = curr->left;
					else if (data_compare()(curr->data, data))
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
					if (data_compare()(prev->data, data))
						prev->right = _newNode(data, prev, nullptr, nullptr);
					else
						prev->left = _newNode(data, prev, nullptr, nullptr);
				}
				return true;
			}

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
				if (data_compare()(data, root->data))
					return _find(root->left, data);
				else if (data_compare()(root->data, data))
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
				if (data_compare()(data, root->data))
					root->left = _erase(root->left, data);
				else if (data_compare()(root->data, data))
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

#endif