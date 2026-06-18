#include <iostream>
#include <fstream>

static std::string	Conversion(std::string line, const std::string& s1, const std::string& s2) {
	std::string	tmp;
	size_t	pos = 0;
	size_t	prevPos = 0;

	while ((pos = line.find(s1, prevPos)) != std::string::npos) {
		tmp += line.substr(prevPos, pos - prevPos);
		tmp += s2;
		prevPos = pos + s1.length();
	}
	tmp += line.substr(prevPos);
	return tmp;
}

static bool isValid(const std::string& fileName, const std::string& s1) {
	if (fileName.empty() || s1.empty()) {
		std::cerr << "Error: All arguments must be non-empty." << std::endl;
		return false;
	}
	return true;
}

int	main(int argc, char* argv[]) {
	if (argc != 4) {
		std::cerr << "Usage: " << argv[0] << " <fileName> <s1> <s2>" << std::endl;
		return 1;
	}
	std::string	fileName = argv[1];
	std::string	s1 = argv[2];
	std::string	s2 = argv[3];
	if (!isValid(fileName, s1)) {
		std::cerr << "Error: Invalid arguments." << std::endl;
		return 1;
	}
	std::ifstream	file(fileName);
	if (!file.is_open()) {
		std::cerr << "Error: Could not open file " << fileName << std::endl;
		return 1;
	}
	std::ofstream	outFile(fileName + ".replace");
	if (!outFile.is_open()) {
		std::cerr << "Error: Could not create output file " << fileName + ".replace" << std::endl;
		return 1;
	}
	std::string	line;
	while (getline(file, line)) {
		line = Conversion(line, s1, s2);
		outFile << line << std::endl;
	}
	file.close();
	outFile.close();
	return 0;
}
