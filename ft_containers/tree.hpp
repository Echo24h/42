#ifndef _tree_hpp_
#define _tree_hpp_

#include <memory>

namespace ft
{
	template <typename T, typename Allocator>
	struct Node
	{
		// ? should data be a value_type pointer to force the use of Allocator
		// ? typedef Allocator data_allocator_type;
		typedef T																data_value_type;
		typedef typename Allocator::template rebind<Node>::other 				allocator_type;
		typedef typename std::allocator_traits<allocator_type>::value_type 		value_type;
		typedef typename std::allocator_traits<allocator_type>::pointer 		pointer;
		typedef typename std::allocator_traits<allocator_type>::const_pointer 	const_pointer;

		data_value_type	data;
		pointer			left;
		pointer 		right;

		Node(data_value_type const & d = data_value_type())
			: data(d), left(nullptr), right(nullptr)
		{}

		~Node(void)
		{}

		bool hasNoChild(void) 	{ return (left == nullptr && right == nullptr); }
		bool hasTwoChild(void)	{ return (left != nullptr && right != nullptr); }
		bool hasOneChild(void)	{ return (!hasNoChild() && !hasTwoChild()); }

		pointer getChild(void)
		{
			if (left)
				return left;
			return right;
		}

		const_pointer getChild(void) const
		{
			if (left)
				return left;
			return right;
		}

		static pointer newNode(data_value_type const & d = data_value_type())
		{
			std::cout << "newNode\n";
			allocator_type _alloc;
			pointer newNode;
			newNode = _alloc.allocate(1);
			_alloc.construct(newNode, d);
			return newNode;
		}

		static void deleteNode(pointer node)
		{
			std::cout << "deleteNode\n";
			if (node == nullptr)
				return ;
			allocator_type _alloc;
			_alloc.destroy(node);
			_alloc.deallocate(node, 1);
		}
	};

	template <typename T, typename Compare, typename Allocator>
	class BinarySearchTree
	{
		public:
			typedef T									value_type;
			typedef Compare								comp;
			typedef Node<value_type, Allocator>			node_type;
			typedef size_t								size_type;

		private:
			typedef typename node_type::allocator_type	_node_allocator;
		
		public:
			typedef typename std::allocator_traits<_node_allocator>::value_type		node_value_type;
			typedef typename std::allocator_traits<_node_allocator>::pointer		node_pointer;
			typedef typename std::allocator_traits<_node_allocator>::const_pointer	const_node_pointer;

		private:
			node_pointer	_root;

		public:
			BinarySearchTree(void)
				: _root(nullptr)
			{}

			BinarySearchTree(value_type const & data)
				: _root(nullptr)
			{
				_root = node_type::newNode(data);
			}

			~BinarySearchTree(void)
			{
				clear();
			}

			void 				insert(value_type const & data) 			{ _root = _insert(_root, data); }
			void 				showInOrder(void) const						{ _showInOrder(_root); }
			bool 				empty(void) const							{ return _root == nullptr; }
			void 				clear(void)									{ _root = _clear(_root); }
			node_pointer 		searchNode(value_type const & data) 		{ return _searchNode(_root, data); }
			const_node_pointer 	searchNode(value_type const & data) const 	{ return _searchNode(_root, data); }
			void 				deleteNode(value_type const & data)			{ _root = _deleteNode(_root, data); }
			size_type 			size(void) const							{ return _size(_root, 0); }

		private:
			node_pointer _insert(node_pointer root, value_type const & data)
			{
				if (root == nullptr)
					return node_type::newNode(data);
				if (comp()(data, root->data))
					root->left = _insert(root->left, data);
				else if (comp()(root->data, data))
					root->right = _insert(root->right, data);
				else
					throw std::runtime_error("ft::BinarySearchTree: cannot insert duplicate data");
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

			node_pointer _searchNode(node_pointer root, value_type const & data)
			{
				if (root == nullptr || (!comp()(data, root->data) && !comp()(root->data, data)))
					return root;
				if (comp()(data, root->data))
					return _searchNode(root->left, data);
				else
					return _searchNode(root->right, data);
			}

			const_node_pointer _searchNode(const_node_pointer root, value_type const & data) const
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

			node_pointer _deleteNode(node_pointer root, value_type const & data)
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