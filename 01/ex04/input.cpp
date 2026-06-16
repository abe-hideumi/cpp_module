#include "input.hpp"

static std::string	waitInput(std::string msg) {
	std::string	input;

	std::cout << msg;
	std::getline(std::cin, input);
	if (std::cin.eof())
		exit(0);
	return input;
}

Input::Input() {
	fileName = waitInput("fileName: ");
	s1 = waitInput("s1: ");
	s2 = waitInput("s2: ");
}

const std::string&	Input::getFileName() const {
	return fileName;
}

const std::string&	Input::getS1() const {
	return s1;
}

const std::string&	Input::getS2() const {
	return s2;
}
