#ifndef _colorfull_hpp_
#define _colorfull_hpp_

#include <iostream>

#define RED 0
#define BLUE 1
#define GREEN 2
#define YELLOW 3
#define PINK 4
#define WHITE 5

namespace ft {
	template <typename T>
	void colorfull(T const & val, int color = WHITE)
	{
		switch (color)
		{
			case RED:
				std::cout << "\x1B[31m" << val << "\033[0m";
				break;
			case BLUE:
				std::cout << "\x1B[34m" << val << "\033[0m";
				break;
			case GREEN:
				std::cout << "\x1B[32m" << val << "\033[0m";
				break;
			case YELLOW:
				std::cout << "\x1B[33m" << val << "\033[0m";
				break;
			case PINK:
				std::cout << "\x1B[35m" << val << "\033[0m";
				break;
			case WHITE:
				std::cout << "\x1B[37m" << val << "\033[0m";
				break;
			default:
				std::cout << val;
				break;
		}
	}
}


#endif