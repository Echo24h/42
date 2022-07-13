#include <iostream>
#include <fstream>

std::string	replacorExtremus(std::string const & data, std::string const & oldStr, std::string const & newStr) {
	std::string newData = data;
	if (!oldStr.empty()) {
		for (int i = 0; i < newData.length(); i++) {
			if (!newData.compare(i, oldStr.length(), oldStr)) {
				newData.erase(i, oldStr.length());
				newData.insert(i, newStr);
				i += newStr.length() - 1;
			}
		}
	}
	return (newData);
} 

int	main(int ac, char *av[]) {
	(void)ac;

	if (!av[1] || !av[2] || !av[3]) {
		std::cerr << "usage: ./openOpen filename oldString newString\n";
		return (1);
	}

	// open file
	std::string filename = av[1];
	std::ifstream file;
	file.open(filename);
	if (file.fail()) {
		std::cerr << "could not open " << filename << std::endl;
		return (1);
	}

	// read file data
	std::string	data;
	std::string line;
	while (std::getline(file, line)) {
		line.push_back('\n');
		data.append(line);
	}
	if (!file.eof() || file.bad()) {
		std::cerr << "error while reading " << filename << std::endl;
		return (1);
	}
	file.close();

	// replace all occurence of oldStr with newStr in data and save the result
	std::string oldStr = av[2];
	std::string newStr = av[3];
	std::string dataModified = replacorExtremus(data, oldStr, newStr);

	// write modified data to a 'a[1].replace' file
	std::ofstream newFile;
	newFile.open(std::string(filename).append(".replace"), std::ios_base::out | std::ios_base::trunc);
	if (newFile.fail()) {
		std::cerr << "could not create/open " << std::string(filename).append(".replace") << std::endl;
		return (1);
	}
	newFile << dataModified;
	if (newFile.fail()) {
		std::cerr << "error writing to the new file\n";
		return (1);
	}
	newFile.close();

	return (0);
}
