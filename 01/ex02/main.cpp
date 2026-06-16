#include <iostream>
#include <string>
#include <iomanip>

const int MAX_CHAR = 10;

int	main() {
	std::string	src = "HI THIS IS BRAIN";
	std::string	*stringPTR = &src;
	std::string	&stringREF = src;

	std::cout << "--Memory address--\n";
	std::cout << std::setw(MAX_CHAR) << "src" << ": " << &src << std::endl;
	std::cout << std::setw(MAX_CHAR) << "stringPTR" << ": " << stringPTR << std::endl;
	std::cout << std::setw(MAX_CHAR) << "stringREF" << ": " << &stringREF << std::endl;
	std::cout << "\n--Value--\n";
	std::cout << std::setw(MAX_CHAR) << "src" << ": " << src << std::endl;
	std::cout << std::setw(MAX_CHAR) << "stringPTR" << ": " << *stringPTR << std::endl;
	std::cout << std::setw(MAX_CHAR) << "stringREF" << ": " << stringREF << std::endl;
	return 0;
}
