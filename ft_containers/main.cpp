#include <iostream>
#include <memory>
#include <exception>
#include <iomanip>
#include <vector>
#include <iterator>
#include <algorithm>
#include <type_traits>
#include <functional>
#include <list>
#include <stack>
#include <map>
#include "vector.hpp"
#include "type_traits.hpp"
#include "iterator.hpp"
#include "utility.hpp"
#include "algorithm.hpp"
#include "stack.hpp"
#include "map.hpp"
#include "tree.hpp"
#include <csignal>

typedef std::string															key_type;
typedef int																	mapped_type;
typedef ft::pair<const std::string, int>									type;
typedef ft::BST<type, std::less<type>, std::allocator<type> >	            bst;
typedef ft::map<key_type, mapped_type>										map;
typedef ft::vector<type>													vec;


void print_map(std::string_view comment, const std::map<std::string, int>& m)
{
    std::cout << comment ;
    // iterate using C++17 facilities
	std::map<std::string, int>::const_iterator it = m.begin();
	std::map<std::string, int>::const_iterator ite = m.end();
		std::cout << "\nite: " << '[' << ite->first << "] = " << ite->second << "\n";
	for (; it != ite; it++)
		std::cout << '[' << it->first << "] = " << it->second << "; ";
// C++11 alternative:
//  for (const auto& n : m) {
//      std::cout << n.first << " = " << n.second << "; ";
//  }
// C++98 alternative
//  for (std::map<std::string, int>::const_iterator it = m.begin(); it != m.end(); it++) {
//      std::cout << it->first << " = " << it->second << "; ";
//  }
    std::cout << '\n';
}

struct Test
{
	int x;

	Test(int x) : x(x) {}
};

int main()
{
	bst b;
	b.insert(ft::make_pair("salut", 5));
	b.insert(ft::make_pair("salut", 6));
	const bst::iterator it = b.begin();
	(*it).second = 8;
	struct Test * i = new Test(5);
	(*i).x++;
	std::cout << (*i).x << std::endl;
	return 0;
	map mymap;

	// mymap.insert(ft::make_pair("pute", 12));
	// mymap.insert(ft::make_pair("puteeee", 12));
	// mymap["salope"]=10;
 	// map::iterator it = mymap.begin();
 	// map::iterator ite = mymap.end();
	// bool res = mymap.value_comp()(*it, *++it);
	// if (res)
	// 	std::cout << "bzzbzz\n";

// 	for (; it != ite; ++it)
// 		std::cout << it->first << ": " << it->second << std::endl;
//   // insert some values:
// 	return 0;
//   mymap['b']=20;
//   mymap['c']=30;
//   mymap['d']=40;
//   mymap['e']=50;
//   mymap['f']=60;

//   it=mymap.find('b');
//   mymap.erase (it);                   // erasing by iterator

//   mymap.erase ('c');                  // erasing by key

//   it=mymap.find ('e');
//   mymap.erase ( it, mymap.end() );    // erasing by range

//   // show content:
//   for (it=mymap.begin(); it!=mymap.end(); ++it)
//     std::cout << it->first << " => " << it->second << '\n';
	// std::map<std::string, int> m;
	// m.insert(std::make_pair("pute", 1));
	// m.insert(std::make_pair("salope", 2));
	// m.insert(std::make_pair("boobs", 3));

	// std::map<std::string, int> m2;
	// m2.insert(std::make_pair("pute", 1));
	// m2.insert(std::make_pair("salope", 2));
	// m2.insert(std::make_pair("boobs", 3));


	// const bst bst1;
	// // bst1.insert(std::make_pair("pute", 1));
	// // bst1.insert(std::make_pair("salope", 2));
	// // bst1.insert(std::make_pair("boobs", 3));

	// bst bst2;
	// bst2.insert(std::make_pair("pute", 1));
	// bst2.insert(std::make_pair("salope", 2));
	// bst2.insert(std::make_pair("boobs", 3));

	// bst::const_iterator it = bst1.begin();
	// //bst::const_iterator cit = it
	// //std::cout << (bst1 == bst2) << std::endl;
	return (0);
}
