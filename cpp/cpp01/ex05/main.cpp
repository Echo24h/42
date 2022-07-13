#include <iostream>
#include "Harl.hpp"

int	main(int ac, char *av[]) {
	(void)ac;
	(void)av;

	Harl	hl;
	hl.complain("DEBUG");
	hl.complain("INFO");
	hl.complain("WARNING");
	hl.complain("ERROR");
	hl.complain("RANDOM");
	return (0);
}
