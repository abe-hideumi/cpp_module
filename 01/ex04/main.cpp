#include <iostream>
#include <fstream>
#include "input.hpp"

static std::string	ft_replace(std::string line, const std::string& s1, const std::string& s2) {
	std::string	tmp = "";
	size_t	pos = 0;

	while ((pos = line.find(s1, pos)) != std::string::npos) {
		tmp += line.substr(0, pos) + s2;
		pos += s1.length();
	}
	return tmp;
}

int	main() {
	Input	input;
	std::cout << input.getFileName() << std::endl;
	std::cout << input.getS1() << std::endl;
	std::cout << input.getS2() << std::endl;

	std::ifstream	file(input.getFileName());
	if (!file.is_open()) {
		std::cerr << "Error: Could not open file " << input.getFileName() << std::endl;
		return 1;
	}
	std::string	line;
	while (getline(file, line)) {
		line = ft_replace(line, input.getS1(), input.getS2());
		std::cout << line << std::endl;
	}
	file.close();
	return 0;
}
