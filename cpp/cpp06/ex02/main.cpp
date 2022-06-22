#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>

Base * generate(void) {
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

void identify(Base* p) {
	if (dynamic_cast<A *>(p)) {
		std::cout << "A\n";
	} else if (dynamic_cast<B *>(p)) {
		std::cout << "B\n";
	} else if (dynamic_cast<C *>(p)) {
		std::cout << "C\n";
	} else {
		std::cout << "I'm just a baaazzzzee\n"; 
	}
}

void identify(Base& p) {
	try {
		A & ref = dynamic_cast<A &>(p);
		(void)ref;
		std::cout << "A\n";
		return ;
	} catch (std::bad_cast & e) {}

	try {
		B & ref = dynamic_cast<B &>(p);
		(void)ref;
		std::cout << "B\n";
		return ;
	} catch (std::bad_cast & e) {}

	try {
		C & ref = dynamic_cast<C &>(p);
		(void)ref;
		std::cout << "C\n";
		return ;
	} catch (std::bad_cast & e) {}

	std::cout << "I'm just a baaazzzzee\n"; 
}

int	main(int ac, char *av[]) {
	(void)av;
	(void)ac;
	srand(time(nullptr));
	for (int i = 0; i < 100; i++) {
		Base * ptr = generate();
		identify(*ptr);
		delete ptr;
	}
	return (0);
}
