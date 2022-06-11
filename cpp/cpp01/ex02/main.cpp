#include <iostream>

int	main()
{
	std::string		str = "HI THIS IS BRAIN";
	std::string*	stringPTR = &str;
	std::string&	stringREF = str;

	std::cout << "----------\n";
	std::cout << "str addr: "<< &str << std::endl;
	std::cout << "stringPTR: "<< stringPTR << std::endl;
	std::cout << "stringREF addr: "<< &stringREF << std::endl;
	std::cout << "str: "<< str << std::endl;
	std::cout << "*stringPTR: "<< *stringPTR << std::endl;
	std::cout << "stringREF: "<< stringREF << std::endl;
	std::cout << "----------\n";
	return (0);
}
