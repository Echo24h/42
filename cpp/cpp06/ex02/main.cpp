#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void) {
	srand(time(nullptr));
	switch (rand() % 3) {
		case 0:
			return (new A);
		case 1:
			return (new B);
		case 2:
			return (new C);
	}
	return (nullptr);
}

void identify(Base* p);
void identify(Base& p);

int	main(int ac, char *av[]) {
	Base *ptr = generate();
	delete ptr;
	return (0);
}
