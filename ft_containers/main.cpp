#include <iostream>
#include "type_traits.hpp"
#include "algorithm.hpp"
#include "vector.hpp"
#include "map.hpp"
#include "stack.hpp"
#include "iterator.hpp"
#include <list>
#include <map>

typedef ft::map<int, int>::iterator 		iterator;
typedef ft::map<int, int>::const_iterator 	const_iterator;

#define TESTED_NAMESPACE ft

#define T1 int
#define T2 std::string
typedef ft::pair<const T1, T2> T3;

static int iter = 0;

template <typename MAP>
void printSize(MAP const & mp) {
	std::cout << mp.size() << std::endl;
}

template <typename MAP, typename U>
void	ft_erase(MAP &mp, U param)
{
	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	mp.erase(param);
	printSize(mp);
}

template <typename MAP, typename U, typename V>
void	ft_erase(MAP &mp, U param, V param2)
{
	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	mp.erase(param, param2);
	printSize(mp);
}

// int		main(void)
// {
// 	std::list<T3> lst;
// 	unsigned int lst_size = 7;
// 	for (unsigned int i = 0; i < lst_size; ++i)
// 		lst.push_back(T3(lst_size - i, i));
// 	std::list<T3>::iterator it = lst.begin(), ite = lst.end();
// 	std::cout << "bp\n";
// 	for (; it != ite; ++it) {
// 		std::cout << it->first << ":" << it->second << std::endl;
// 	}
// 	TESTED_NAMESPACE::map<T1, T2> mp(lst.begin(), lst.end());
// 	std::cout << "bp\n";
// 	return (0);
// }

int		main(void)
{
	std::list<T3> lst;
	unsigned int lst_size = 10;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(T3(i, std::string((lst_size - i), i + 65)));
	TESTED_NAMESPACE::map<T1, T2> mp(lst.begin(), lst.end());
	printSize(mp);

	ft_erase(mp, ++mp.begin());

	ft_erase(mp, mp.begin());
	ft_erase(mp, --mp.end());

	ft_erase(mp, mp.begin(), ++(++(++mp.begin())));
	ft_erase(mp, --(--(--mp.end())), --mp.end());

	mp[10] = "Hello";
	mp[11] = "Hi there";
	printSize(mp);
	ft_erase(mp, --(--(--mp.end())), mp.end());

	mp[12] = "ONE";
	mp[13] = "TWO";
	mp[14] = "THREE";
	mp[15] = "FOUR";
	printSize(mp);
	ft_erase(mp, mp.begin(), mp.end());

	return (0);
}

int mymain()
{   
	ft::map<int, int> mp;

	// iterator  itz = mp.begin();
	// const_iterator  citz = mp.end();
	// std::cout << "node inserted\n";
	mp.insert(ft::make_pair(7, 3));
	mp.insert(ft::make_pair(6, 3));
	mp.insert(ft::make_pair(5, 3));
	mp.insert(ft::make_pair(4, 3));
	mp.insert(ft::make_pair(3, 3));
	mp.insert(ft::make_pair(2, 3));
	mp.insert(ft::make_pair(1, 3));
	// std::cout << "node inserted\n";
	// std::cout << "node inserted\n";
	// mp.insert(ft::make_pair(9, 3));
	// mp.insert(ft::make_pair(8, 3));
	mp.erase(7);
	// mp.debug();
	// mp.debug();
	// mp.debug();
	// iterator it = ++mp.begin();
	// std::cout << it->first << ": " << it->second << std::endl;
	// std::cout << "---" << std::endl;
	// mp.erase(mp.begin(), ++mp.begin());
	// mp.erase(--(--(--mp.end())), --mp.end());
	// mp.erase(mp.begin(), ++(--(++mp.begin())));
	// for (iterator itx = mp.begin(); itx != ++++++mp.begin(); ++itx)
	// 	std::cout << it->first << ": " << it->second << std::endl;
	// std::cout << "---" << std::endl;
	for (iterator it = mp.begin(); it != mp.end(); ++it)
		std::cout << it->first << ": " << it->second << std::endl;
	// std::cout << "---" << std::endl;
    return 0;
}
