#include <iostream>
#include "Span.hpp"

int	main(int ac, char *av[]) {
	(void)ac;
	(void)av;
	Span sp = Span(10000);
	try {
		sp.addRandomNumbers(10000, 1, 10);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		std::cout << sp;
	} catch (std::runtime_error e) {
		std::cout << e.what() << std::endl;
	}
	
	return 0;
}
