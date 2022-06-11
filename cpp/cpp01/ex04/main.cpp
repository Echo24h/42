#include <iostream>
#include <fstream>

int	main(int ac, char *av[]) {
	if (!av[1] || !av[2] || !av[3]) {
		std::cerr << "usage: ./openOpen filename oldString newString\n";
		return (1);
	}

	// open file
	std::ifstream file;
	file.open(av[1]);
	if (file.fail()) {
		std::cerr << "could not open " << av[1] << std::endl;
		return (1);
	}

	// read file data
	char 		c;
	std::string	data = "";
	while (file.get(c)) {
		data.push_back(c);
	}
	if (file.bad()) {
		std::cerr << "error reading the file\n";
		return (1);
	}
	file.close();

	// replace oldString with newString in data
	std::string	oldStr = av[2];
	std::string newStr = av[3];
	if (!oldStr.empty()) {
		for (int i = 0; i < data.length(); i++) {
			if (!data.compare(i, oldStr.length(), oldStr)) {
				data.erase(i, oldStr.length());
				data.insert(i, newStr);
				i += newStr.length() - 1;
			}
		}
	}

	// write modified data to a 'a[1].replace' file
	std::ofstream newFile;
	newFile.open(std::string(av[1]).append(".replace"));
	if (newFile.fail()) {
		std::cerr << "could not create/open " << std::string(av[1]).append(".replace") << std::endl;
		return (1);
	}
	newFile << data;
	if (newFile.bad()) {
		std::cerr << "error writing to the new file\n";
		return (1);
	}
	newFile.close();

	return (0);
}
