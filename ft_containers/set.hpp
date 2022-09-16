#include "tree.hpp"
#include <functional>

template <class T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
class set
{
    public:
        typedef T               	key_type;
        typedef key_type        	value_type;
        typedef size_t          	size_type;
        typedef ptrdiff_t       	difference_type;
        typedef Compare         	key_compare;
        typedef key_compare     	value_compare;
        typedef Alloc           	allocator_type;
        typedef value_type &    	reference;
        typedef value_type const &  const_reference;
		typedef typename allocator_type::pointer		pointer;
		typedef typename allocator_type::const_pointer	const_pointer;

	private:
		typedef ft::BST<value_type, value_compare, allocator_type>	_tree;

		_tree _base;

	public:
		typedef typename _tree::iterator				iterator;
		typedef typename _tree::const_iterator			const_iterator;
		typedef typename _tree::reverse_iterator		reverse_iterator;
		typedef typename _tree::const_reverse_iterator	const_reverse_iterator;
	
	public:
		set(void)
			: _base()
		{}

		explicit set(Compare const & comp, const Allocator & alloc = Allocator())
			: _base()
		{
			(void)alloc;
		}

		template <class InputIt>
		set(InputIt first, InputIt last, Compare const & comp = Compare(), Allocator const & alloc = Allocator());
};
