#ifndef _tree_hpp_
#define _tree_hpp_

#include <exception>
#include <memory>
#include "iterator.hpp"

namespace ft
{
	// *****************************************
	// * BinaryNode
	// *****************************************
	template <typename DataType, typename DataAllocator>
	struct BinaryNode
	{
		typedef DataType														data_type;
		typedef typename DataAllocator::template rebind<BinaryNode>::other 		allocator_type;
		typedef typename std::allocator_traits<allocator_type>::value_type 		value_type;
		typedef typename std::allocator_traits<allocator_type>::pointer 		pointer;
		typedef value_type &													reference;
		typedef size_t															size_type;

		data_type		data;
		pointer			left;
		pointer 		right;
		pointer			parent;

		BinaryNode(data_type const & data = data_type(), pointer parent = nullptr)
			: data(data), left(nullptr), right(nullptr), parent(parent)
		{}

		~BinaryNode(void)
		{}

		bool hasNoChild(void) const
		{ return (left == nullptr && right == nullptr); }

		bool hasTwoChild(void) const
		{ return (left != nullptr && right != nullptr); }

		bool hasOneChild(void) const
		{ return (!hasNoChild() && !hasTwoChild()); }

		bool hasParent(void) const
		{ return parent != nullptr; }

		pointer getChild(void)
		{ return (left != nullptr ? left : right); }

		static void * operator new(size_type n)
		{
			allocator_type alloc;
			void * ptr = alloc.allocate(n * sizeof(value_type));
			//alloc.construct(ptr, value_type)
			return ptr;
		}

		static void operator delete(void * ptr, size_type n = 1)
		{
			allocator_type alloc;
			alloc.deallocate(ptr, n);
			//alloc.construct(ptr, value_type)
			return ptr;
		}

		static pointer newNode(data_type const & data = data_type(), pointer parent = nullptr)
		{
			allocator_type _alloc;
			pointer newNode;
			newNode = _alloc.allocate(1);
			_alloc.construct(newNode, BinaryNode(data, parent));
			return newNode;
		}

		static void deleteNode(pointer node)
		{
			if (node == nullptr)
				return ;
			allocator_type _alloc;
			_alloc.destroy(node);
			_alloc.deallocate(node, 1);
		}
	};

	// *****************************************
	// * TreeIterator
	// *****************************************
	template <typename NodeType>
	class BSTIterator
		: public std::iterator<bidirectional_iterator_tag, NodeType>
	{
		public:
			// ---- member type(s) ----
			typedef BSTIterator						type;
			typedef typename NodeType::value_type	node_type;
			typedef typename NodeType::pointer		node_pointer;
			typedef typename NodeType::data_type	data_type;
			typedef data_type const &    			data_const_reference;

		private:
			node_pointer _curr;

		public:
			// ---- constructor(s) ----
			BSTIterator(void)
				: _curr(nullptr)
			{}

			BSTIterator(node_pointer ptr)
				: _curr(ptr)
			{}

			BSTIterator(BSTIterator const & src)
				: _curr(src.base())
			{}

			// ---- operator(s) ----
			data_const_reference operator*(void) const
			{ return _curr->data; }

			// todo : compare my exceptions w. stl ones
			// BSTIterator & operator++()
			// {
			// 	node_pointer successor = BST::getSuccessor(this->_curr);
			// 	if (!successor)
			// 		throw std::overflow_error("ft::BSTIterator");
			// 	else
			// 		_curr = successor;
			// 	return *this;
			// }

			// BSTIterator & operator--()
			// {
			// 	node_pointer predecessor = BST::getPredecessor(this->_curr);
			// 	if (!predecessor)
			// 		throw std::overflow_error("ft::BSTIterator");
			// 	else
			// 		_curr = predecessor;
			// 	return *this;
			// }

			// BSTIterator operator++(int)
			// {
				
			// 	node_pointer successor = BST::getSuccessor(this->_curr);
			// 	if (!successor)
			// 		throw std::overflow_error("ft::BSTIterator");
			// 	else
			// 		_curr = successor;
			// 	return *this;
			// }

			// BSTIterator operator--(int)
			// {
			// 	node_pointer predecessor = BST::getPredecessor(this->_curr);
			// 	if (!predecessor)
			// 		throw std::overflow_error("ft::BSTIterator");
			// 	else
			// 		_curr = predecessor;
			// 	return *this;
			// }

			// operator BSTIterator<node_type const *>() const
			// { return BSTIterator<node_type const *>(_curr); }

			// ---- member function(s) ----
			node_pointer base(void) const
			{ return _curr; }
	};

	template <typename Iter1, typename Iter2>
	bool operator==(const BSTIterator<Iter1>& lhs, const BSTIterator<Iter2>& rhs)
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
			typedef BinaryNode<DataType, Allocator>		node_type;
			typedef DataType							data_type;
			typedef Compare								comp;
			typedef typename node_type::pointer			node_pointer;
			typedef size_t								size_type;

		private:
			node_pointer	_root;

		public:
			BST(void)
				: _root(nullptr)
			{}

			BST(data_type const & data)
				: _root(nullptr)
			{
				_root = node_type::newNode(data);
			}

			~BST(void)
			{
				clear();
			}

			void 				insert(data_type const & data) 			{ _root = _insert(_root, data, nullptr); }
			void 				showInOrder(void) const					{ _showInOrder(_root); }
			bool 				empty(void) const							{ return _root == nullptr; }
			void 				clear(void)									{ _root = _clear(_root); }
			node_pointer 		searchNode(data_type const & data) 		{ return _searchNode(_root, data); }
			void 				deleteNode(data_type const & data)			{ _root = _deleteNode(_root, data); }
			size_type 			size(void) const							{ return _size(_root, 0); }

			static node_pointer getMin(node_pointer root)
			{
				while (root && root->left)
					root = root->left;
				return root;
			}

			static node_pointer getMax(node_pointer root)
			{
				while (root && root->right)
					root = root->right;
				return root;
			}

			static node_pointer getSuccessor(node_pointer node)
			{
				if (!node)
					return nullptr;
				if (node->right)
					return getMin(node->right);
				node_pointer parent = node->parent;
				while (parent && parent->left != node)
				{
					node = node->parent;
					parent = node->parent;
				}
				return parent;
			}

			static node_pointer getPredecessor(node_pointer node)
			{
				if (!node)
					return nullptr;
				if (node->left)
					return getMax(node->left);
				node_pointer parent = node->parent;
				while (parent && parent->right != node)
				{
					node = node->parent;
					parent = node->parent;
				}
				return parent;
			}

		private:
			node_pointer _insert(node_pointer root, data_type const & data, node_pointer parent)
			{
				if (root == nullptr)
					return node_type::newNode(data, parent);
				if (comp()(data, root->data))
					root->left = _insert(root->left, data, root);
				else if (comp()(root->data, data))
					root->right = _insert(root->right, data, root);
				else
					throw std::runtime_error("ft::BST: cannot insert duplicate data");
				return root;
			}

			void _showInOrder(node_pointer root) const
			{
				if (root == nullptr)
					return ;
				_showInOrder(root->left);
				std::cout << root->data << std::endl;
				_showInOrder(root->right);
			}

			node_pointer _searchNode(node_pointer root, data_type const & data)
			{
				if (root == nullptr || (!comp()(data, root->data) && !comp()(root->data, data)))
					return root;
				if (comp()(data, root->data))
					return _searchNode(root->left, data);
				else
					return _searchNode(root->right, data);
			}

			node_pointer _clear(node_pointer root)
			{
				if (!root)
					return nullptr;
				root->left = _clear(root->left);
				root->right = _clear(root->right);
				node_type::deleteNode(root);
				return nullptr;
			}

			node_pointer _getMinNode(node_pointer root)
			{
				if (!root || !root->left)
					return root;
				return getMinNode(root->left);
			}

			node_pointer _deleteNode(node_pointer root, data_type const & data)
			{
				if (!root)
					return nullptr;
				if (root->left && comp()(data, root->data))
					root->left = _deleteNode(root->left, data);
				else if (root->right && comp()(root->data, data))
					root->right = _deleteNode(root->right, data);
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
						node_type::deleteNode(root);
						return child;
					}
					else
					{
						node_pointer successor = _getMinNode(root->right);
						root->data = successor->data;
						root->right = _deleteNode(root->right, successor->data);
					}	
				}
				return root;
			}

			size_type _size(node_pointer root, size_type i) const
			{
				if (!root)
					return i;
				i++;
				i += _size(root->left, 0);
				i += _size(root->right, 0);
				return i;
			}
	};
}

#endif