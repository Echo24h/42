#include "showBits.hpp"

void	showBits(unsigned char const c) {
	//std::cout << "in showBits char\n";
	for (int i = 0; i < 8; i++) {
		std::cout << ((c >> (7 - i)) & 0x1);
		if (i == 3) {
			std::cout << " ";
		}
	}
}

void	showBits(int const x) {
	std::cout << "in showBits int\n";

	unsigned char bytes[4];
	memcpy(bytes, &x, 4);
	
	for (int i = 0; i < 4; i++) {
		showBits((unsigned char)bytes[4 - i]);
		if (i != 4 - 1) {
			std::cout << " | ";
		}
	}

	/*
	for (int i = 0; i < 32; i++) {
		std::cout << ((x >> (31 - i)) & 0x1);
		if (i == 3 || i == 11 || i == 19 || i == 27)
			std::cout << " ";
		else if (i == 7 || i == 15 || i == 23)
			std::cout << " | ";
		
	}
	*/
	std::cout << std::endl;
}

void	showBits(float f) {
	std::cout << "in showBits float\n";

	unsigned char bytes[4];
	memcpy(bytes, &f, 4);

	for (int i = 0; i < 4; i++) {
		showBits((unsigned char)bytes[i]);
		if (i != 4 - 1) {
			std::cout << " | ";
		}
	}
	std::cout << std::endl;
}
