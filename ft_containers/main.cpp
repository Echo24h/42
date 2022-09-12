#include <iostream>
#include "type_traits.hpp"
#include "algorithm.hpp"
#include "vector.hpp"
#include "map.hpp"
#include "stack.hpp"
#include "iterator.hpp"

typedef ft::map<int, int>::iterator 		iterator;
typedef ft::map<int, int>::const_iterator 	const_iterator;

int main()
{   
	ft::map<int, int> mp;

	iterator  itz = mp.begin();
	const_iterator  citz = mp.end();
	mp.insert(ft::make_pair(1, 3));

	mp.insert(ft::make_pair(6, 3));
	mp.insert(ft::make_pair(5, 3));
	mp.insert(ft::make_pair(3, 3));
	mp.insert(ft::make_pair(4, 3));
	mp.insert(ft::make_pair(2, 3));
	mp.insert(ft::make_pair(1, 3));
	mp.insert(ft::make_pair(9, 3));
	mp.insert(ft::make_pair(8, 3));
	mp.insert(ft::make_pair(7, 3));

	mp.erase(3);
	iterator it = ++mp.begin();
	std::cout << it->first << ": " << it->second << std::endl;
	std::cout << "---" << std::endl;
	mp.erase(mp.begin(), ++mp.begin());
	mp.erase(--(--(--mp.end())), --mp.end());
	mp.erase(mp.begin(), ++(--(++mp.begin())));
	for (iterator itx = mp.begin(); itx != ++++++mp.begin(); ++itx)
		std::cout << it->first << ": " << it->second << std::endl;
	std::cout << "---" << std::endl;
	for (iterator it = mp.begin(); it != mp.end(); ++it)
		std::cout << it->first << ": " << it->second << std::endl;
	std::cout << "---" << std::endl;
    return 0;
}
