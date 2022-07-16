#include <iostream>
#include <sstream>
#include <cmath>
#include <iomanip>

enum literalType {
	INVALID_T,
	FLOAT_T,
	INT_T,
	DOUBLE_T,
	CHAR_T
};

bool isFloat(std::string str) {
	if (str == "nanf" || str == "inff" || str == "+inff" || str == "-inff") {
		return (true);
	}
	if (str.length() < 2
		|| str.find_first_not_of("-0123456789.f", 0) != str.npos
		|| str.find_first_of(".", 0) == str.npos
		|| str.find_first_of(".", 0) != str.find_last_of(".")
		|| str.back() != 'f'
		|| str.find_first_of("-", 0) != str.find_last_of("-")
		|| (str.find_first_of("-", 0) != str.npos && str.front() != '-')) {
		return (false);
	} else {
		return (true);
	}
}

bool isInt(std::string str) {
	if (str.find_first_not_of("-0123456789", 0) != str.npos
		|| str.find_first_of("-", 0) != str.find_last_of("-")
		|| (str.find_first_of("-", 0) != str.npos && str.front() != '-')) {
		return (false);
	} else {
		return (true);
	}
}

bool isDouble(std::string str) {
	if (str == "nan" || str == "inf" || str == "+inf" || str == "-inf") {
		return (true);
	}
	if (str.length() < 2
		|| str.find_first_not_of("-0123456789.", 0) != str.npos
		|| str.find_first_of(".", 0) == str.npos
		|| str.find_first_of(".", 0) != str.find_last_of(".")
		|| str.find_first_of("-", 0) != str.find_last_of("-")
		|| (str.find_first_of("-", 0) != str.npos && str.front() != '-')) {
		return (false);
	} else {
		return (true);
	}
}

bool isChar(std::string str) {
	return ((str.length() == 1) ? true : false);
}

int getType(std::string str) {
	if (str.empty()) {
		return (INVALID_T);
	} else if (isInt(str)) {
		return (INT_T);
	} else if (isChar(str)) {
		return (CHAR_T);
	}  else if (isFloat(str)) {
		return (FLOAT_T);
	} else if (isDouble(str)) {
		return (DOUBLE_T);
	} else {
		return (INVALID_T);
	}
}

void convert(char cVal) {
	if (cVal >= 32 && cVal < 127) {
		std::cout << "char: " << cVal << std::endl;
	} else {
		std::cout << "char: " << "Non displayable" << std::endl;
	}

	std::cout << "int: " << static_cast<int>(cVal) << std::endl;
	std::cout << "float: " << static_cast<float>(cVal) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(cVal) << ".0" << std::endl;
}


void convert(int iVal) {
	if (iVal >= 32 && iVal < 127) {
		std::cout << "char: " << static_cast<char>(iVal) << std::endl;
	} else {
		std::cout << "char: " << "Non displayable" << std::endl;
	}

	std::cout << "int: " << iVal << std::endl;
	std::cout << "float: " << static_cast<float>(iVal) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(iVal) << ".0" << std::endl;
}

void convert(float fVal) {
	if (fVal >= 32 && fVal < 127) {
		std::cout << "char: " << static_cast<char>(fVal) << std::endl;
	} else if (std::isnan(fVal) || std::isinf(fVal)) {
		std::cout << "char: " << "impossible" << std::endl;
	} else {
		std::cout << "char: " << "Non displayable" << std::endl;
	}

	if (std::isnan(fVal) || std::isinf(fVal)) {
		std::cout << "int: " << "impossible" << std::endl;
	} else {
		std::cout << "int: " << static_cast<int>(fVal) << std::endl;
	}

	std::cout << "float: " << fVal;
	if (fVal == std::floor(fVal) && !std::isnan(fVal) && !std::isinf(fVal))
		std::cout << ".0";
	std::cout << "f" << std::endl;

	std::cout << "double: " << static_cast<double>(fVal);
	if (fVal == std::floor(fVal) && !std::isnan(fVal) && !std::isinf(fVal))
		std::cout << ".0";
	std::cout << std::endl;
}

void convert(double dVal) {
	if (dVal >= 32 && dVal < 127) {
		std::cout << "char: " << static_cast<char>(dVal) << std::endl;
	} else if (std::isnan(dVal) || std::isinf(dVal)) {
		std::cout << "char: " << "impossible" << std::endl;
	} else {
		std::cout << "char: " << "Non displayable" << std::endl;
	}

	if (std::isnan(dVal) || std::isinf(dVal)) {
		std::cout << "int: " << "impossible" << std::endl;
	} else {
		std::cout << "int: " << static_cast<int>(dVal) << std::endl;
	}

	std::cout << "float: " << static_cast<float>(dVal);
	if (dVal == std::floor(dVal) && !std::isnan(dVal) && !std::isinf(dVal))
		std::cout << ".0";
	std::cout << "f" << std::endl;

	std::cout << "double: " << dVal;
	if (dVal == std::floor(dVal) && !std::isnan(dVal) && !std::isinf(dVal))
		std::cout << ".0";
	std::cout << std::endl;
}

int	main(int ac, char *av[]) {
	(void)ac;
	if (!av[1]) {
		std::cerr << "usage: ./convert \"yourLiteralValue\"" << std::endl;
		return (1);
	}
	std::string literalVal = av[1];
	std::stringstream ss;
	switch (getType(literalVal)) {
		case INT_T:
			ss << literalVal;
			int iVal;
			ss >> iVal;
			if (ss.fail()) {
				std::cerr << "Invalid literal" << std::endl;
				return (1);
			}
			convert(iVal);
			break;
		case FLOAT_T:
			ss << literalVal.substr(0, literalVal.length() - 1);
			float fVal;
			ss >> fVal;
			if (ss.fail()) {
				std::cerr << "Invalid literal" << std::endl;
				return (1);
			}
			convert(fVal);
			break;
		case DOUBLE_T:
			ss << literalVal;
			double dVal;
			ss >> dVal;
			if (ss.fail()) {
				std::cerr << "Invalid literal" << std::endl;
				return (1);
			}
			convert(dVal);
			break;
		case CHAR_T:
			ss << literalVal;
			char cVal;
			ss >> cVal;
			if (ss.fail()) {
				std::cerr << "Invalid literal" << std::endl;
				return (1);
			}
			convert(cVal);
			break;
		case INVALID_T:
			std::cerr << "Invalid literal, try again nob\n";
			break;
	}
	return (0);
}
