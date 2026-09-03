#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>

static std::string FtReplace(const std::string& line, const std::string& s1, const std::string& s2) {
	size_t	prevPos = 0;
	std::string	tmp;
	size_t	pos = line.find(s1);

	while (pos  != std::string::npos) {
		tmp += line.substr(prevPos, pos - prevPos) + s2;
		prevPos = pos + s1.length();
		pos = line.find(s1, prevPos);
	}
	tmp += line.substr(prevPos);
	return tmp;
}

int	main(int ac, char **av) {
	if (ac != 4) {
		std::cerr << "Usage: ./ex04 <fileName> <s1> <s2>" << std::endl;
		return 1;
	}
	std::string fileName = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];

	std::ifstream	file(fileName.c_str());
	if (!file.is_open()) {
		std::cerr << "Error: Could not open file " << fileName << std::endl;
		return 1;
	}
	if (s1.empty()) {
		std::cerr << "Error: s1 cannot be empty" << std::endl;
		return 1;
	}
	fileName += ".replace";
	std::ofstream	outFile(fileName.c_str());
	std::string	line;
	while (getline(file, line)) {
		line = FtReplace(line, s1, s2);
		outFile << line << std::endl;
	}
	file.close();
	outFile.close();
	return 0;
}
