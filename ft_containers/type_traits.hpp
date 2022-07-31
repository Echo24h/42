#ifndef _type_traits_hpp_
#define _type_traits_hpp_

#include <iostream>

namespace ft {
	// enable_if
	template <bool, typename T = void>
	struct enable_if {};

	template <typename T>
	struct enable_if<true, T> { typedef T type; };

	// is_integral
	template <typename T>
	struct is_integral { static bool const value = false; };
	
	template <>
	struct is_integral<bool> { static bool const value = true; };
	
	template <>
	struct is_integral<char> { static bool const value = true; };

	template <>
	struct is_integral<char16_t> { static bool const value = true; };
}

#endif
