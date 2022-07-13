#include <iostream>
#include "Harl.hpp"

int	main(int ac, char *av[]) {
	(void)ac;

	if (!av[1]) {
		return (0);
	}

	Harl		hl;
	std::string levels[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};

	int i;
	for (i = 0; i < 4; i++) {
		if (!levels[i].compare(av[1])) {
			break ;
		}
	}

	switch (i) {
		case 0:
			hl.complain("DEBUG");
			hl.complain("INFO");
			hl.complain("WARNING");
			hl.complain("ERROR");
			break;
		case 1:
			hl.complain("INFO");
			hl.complain("WARNING");
			hl.complain("ERROR");
			break;
		case 2:
			hl.complain("WARNING");
			hl.complain("ERROR");
			break;
		case 3:
			hl.complain("ERROR");
			break;
		default:
			break;
	}

	return (0);
}
