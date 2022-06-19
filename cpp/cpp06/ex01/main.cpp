#include <iostream>

typedef struct Data {
	int x;
	int y;
} Data;

uintptr_t serialize(Data* ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data *>(raw));
}

int	main(int ac, char *av[]) {
	Data x;
	x.x = 5;
	x.y = 6;
	std::cout << x.x << "|" << x.y << std::endl;
	uintptr_t t = serialize(&x);
	Data *p = deserialize(t);
	std::cout << p->x << "|" << p->y << std::endl;
	std::cout << std::hex << t << std::dec << "|" << &x << std::endl;
	return (0);
}
