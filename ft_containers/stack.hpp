#ifndef _stack_hpp_
#define _stack_hpp_

#include "vector.hpp"

namespace ft
{
	template <typename T, typename Container = ft::vector<T> >
	class stack
	{
		public:
			typedef T			value_type;
			typedef Container	container_type;
			typedef size_t		size_type;

		private:
			container_type _ctnr;

		public:
			explicit stack(const container_type & ctnr = container_type())
				: _ctnr(ctnr)
			{}

			~stack() {}

			bool				empty(void) const 				{ return _ctnr.empty(); }
			size_type 			size(void) const 				{ return _ctnr.size(); }
			value_type & 		top(void)						{ return _ctnr.back(); }
			value_type const & 	top(void) const 				{ return _ctnr.back(); }
			void 				push(const value_type & val) 	{ _ctnr.push_back(val); }
			void 				pop(void) 						{ _ctnr.pop_back(); }

		private:
			template <typename T1, typename _C1>
    		friend bool operator==(const stack<T1, _C1>& __x, const stack<T1, _C1>& __y);

			template <typename T1, typename _C1>
			friend bool operator<(const stack<T1, _C1>& __x, const stack<T1, _C1>& __y);
	};

	template <typename T, typename Container>
	bool operator==(const ft::stack<T,Container> & lhs, const ft::stack<T,Container> & rhs )
	{
		return lhs._ctnr == rhs._ctnr;
	}
 	
	template <typename T, typename Container>
	bool operator!=(const ft::stack<T,Container> & lhs, const ft::stack<T,Container> & rhs )
	{
		return !(lhs == rhs);
	}

	template <typename T, typename Container>
	bool operator<( const ft::stack<T,Container> & lhs, const ft::stack<T,Container> & rhs )
	{
		return (lhs._ctnr < rhs._ctnr);
	}

	template <typename T, typename Container>
	bool operator<=( const ft::stack<T,Container> & lhs, const ft::stack<T,Container> & rhs )
	{
		return (lhs == rhs || lhs < rhs);
	}

	template <typename T, typename Container>
	bool operator>( const ft::stack<T,Container> & lhs, const ft::stack<T,Container> & rhs )
	{
		return !(lhs <= rhs);
	}

	template <typename T, typename Container>
	bool operator>=( const ft::stack<T,Container> & lhs, const ft::stack<T,Container> & rhs )
	{
		return !(lhs < rhs);
	}
}

#endif