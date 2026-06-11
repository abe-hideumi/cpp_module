#include "utils.hpp"
#include <cctype>

void	ExitProgram() {
	std::cout << "The Program quits and the contacts are lost forever!" << std::endl;
	exit(0);
}

std::string	InputWaiting(const std::string &msg) {
	std::string	input;

	std::cout << msg;
	std::getline(std::cin, input);
	if (std::cin.eof())
		ExitProgram();
	return input;
}

std::string	Truncate(const std::string &str) {
	if (str.length() >= MAX_CHAR)
		return str.substr(0, MAX_CHAR - 1) + ".";
	return str;
}

bool	ValidName(const std::string &input) {
	bool	hasAlpha = false;

	if (input.empty())
		return false;
	for (size_t i = 0; i < input.length(); i++)
	{
		bool	alpha = std::isalpha((unsigned char)input[i]);
		if (!alpha && !std::isspace((unsigned char)input[i]))
			return false;
		if (alpha)
			hasAlpha = true;
	}
	return hasAlpha;
}

bool	ValidNumber(const std::string &input) {
	bool	hasDigit = false;

	if (input.empty())
		return false;
	for (size_t i = 0; i < input.length(); i++)
	{
		bool	digit = std::isdigit((unsigned char)input[i]);
			if (!digit && !std::isspace((unsigned char)input[i])
				&& input[i] != '+' && input[i] != '-'
				&& input[i] != '(' && input[i] != ')')
			return false;
		if (digit)
			hasDigit = true;
	}
	return hasDigit;
}
