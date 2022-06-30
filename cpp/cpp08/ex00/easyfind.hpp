template<typename T>
int & easyfind(T container, int toFind) {
	(void)toFind;
	typename T::iterator it;
	typename T::iterator ite = container.end();
	for (it = container.begin(); it != ite; it++) {
		if (*it == toFind) {
			return (*it);
		}
	}
	
	return (0);
}
