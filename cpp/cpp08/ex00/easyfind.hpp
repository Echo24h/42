template<typename Container>
int & easyfind(Container ctnr, int toFind) {
	typename Container::iterator it;
	it = std::find(ctnr.begin(), ctnr.end(), toFind);
	if (it == ctnr.end()) {
		throw (std::runtime_error("easyfind: element not found"));
	} else {
		return (*it);
	}
}
