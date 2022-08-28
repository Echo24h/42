#ifndef _map_hpp_
#define _map_hpp_

#include <functional> // * for std::binary_function
#include "utility.hpp"
#include "tree.hpp"

namespace ft
{
	template <
		typename Key,
        typename T,
        typename Compare = std::less<Key>,
        typename Alloc = std::allocator<ft::pair<Key const, T> >
    >
	class map
	{
		public:
			typedef Key											key_type;
			typedef T											mapped_type;
			typedef ft::pair<key_type const, mapped_type> 		value_type;
			typedef Compare										key_compare;
			typedef Alloc										allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef size_t										size_type;

			typedef ft::BST<value_type, key_compare, allocator_type>	_tree;

			// typedef value_compare				Nested function class to compare elements	see value_comp
			// typedef iterator						a bidirectional iterator to value_type	convertible to const_iterator
			// typedef const_iterator				a bidirectional iterator to const value_type	
			// typedef reverse_iterator				reverse_iterator<iterator>	
			// typedef const_reverse_iterator		reverse_iterator<const_iterator>	
			// typedef difference_type				a signed integral type, identical to: iterator_traits<iterator>::difference_type	usually the same as ptrdiff_t

		public:
			class value_compare
				: public std::binary_function<value_type, value_type, bool>
			{
				protected:
					key_compare comp;

					value_compare(key_compare c)
						: comp(c)
					{}
					
				public:
					bool operator()(const value_type & x, const value_type & y) const
					{
						return comp(x->first, x->second);
					}
			};

		private:
			_tree base;	

		public:
			map(void)
			{}

			explicit map(const Compare & comp, const Allocator & alloc = Allocator())
			{}

			map(const map & other)
			{}

			template <typename InputIt>
			map(InputIt first, InputIt last,
				const Compare & comp = Compare(),
				const Allocator & alloc = Allocator())
			{}

			~map(void)
			{}

			size_type size(void) const
			{
				return base.size();
			}

			size_type max_size(void) const
			{
				return base.max_size();
			}

			void clear(void)
			{
				base.clear();
			}

			ft::pair<iterator, bool> insert(value_type const & value)
			{
				bool wasInserted;
				wasInserted = bst.insert(value) ? false : true;
				return ft::make_pair(bst.find(value), wasInserted);
			}

			iterator insert(iterator hint, const value_type & value)
			{
				(void)hint;
				insert(value);
			}

			template <typename Iter>
			void insert(Iter first, Iter last)
			{
				for (; first != last; ++first)
					insert(*first);
			}

			void erase(iterator pos)
			{
				bst.erase(*pos);
			}

			void erase(iterator first, iterator last)
			{
				for (; first != last; ++first)
					erase(*first);
			}

			size_type erase(Key const & key)
			{
				iterator pos = bst.find(ft::make_pair(key, mapped_type()));
				if (pos.base() == _end)
					return 0;
				bst.erase(*pos);
				return 1;
			}
			
			void swap(map & other)
			{
				_tree.swap(other._tree);
			}

			size_type count(key_type const & key) const
			{
				ft::pair<key_type, mapped_type> p;
				p = ft::make_pair(key, mapped_type());
				return (bst.find(p).base() != _end);
			}

			iterator find(Key const & key)
			{
				return find(ft::make_pair(key, mapped_type()));
			}

			// todo : constness
			// const_iterator find(Key const & key) const
			// {}

			std::pair<iterator, iterator> equal_range(Key const & key)
			{
				return ft::make_pair(lower_bound(key), upper_bound(key));
			}

			// std::pair<const_iterator,const_iterator> equal_range( const Key & key ) const
			// {}

			iterator lower_bound(Key const & key)
			{
				return bst.lower_bound(ft::make_pair(key, mapped_type()));
			}

			iterator upper_bound(Key const & key)
			{
				return bst.upper_bound(ft::make_pair(key, mapped_type()));
			}
	};
}

template <class Key, class T, class Compare, class Alloc>
void swap(ft::map<Key,T,Compare,Alloc> & lhs,
			ft::map<Key,T,Compare,Alloc> & rhs)
{
	lhs.swap(rhs);
}

#endif