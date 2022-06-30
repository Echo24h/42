#include <algorithm>

/*
	note that you can do :
		typedef typename Container::iterator iterator;
		iterator it;
*/

template<typename Container>
int & easyfind(Container ctnr, int toFind) {
	typename Container::iterator it = std::find(ctnr.begin(), ctnr.end(), toFind);
	if (it == ctnr.end()) {
		throw (std::runtime_error("easyfind: element not found"));
	} else {
		return (*it);
	}
}
