#include "phonebook.hpp"
#include <cerrno>
#include <climits>

void	exit_program() {
	std::cout << "The Program quits and the contacts are lost forever!" << std::endl;
	exit(0);
}

std::string	input_waiting(const std::string &msg) {
	std::string	input;

	std::cout << msg;
	std::getline(std::cin, input);
	if (std::cin.eof())
		exit_program();
	return (input);
}

bool	valid_string(const std::string &input) {
	bool	has_alpha = false;

	if (input.empty())
		return false;
	for (size_t i = 0; i < input.length(); i++)
	{
		if (std::isalpha((unsigned char)input[i]) == false
				&& std::isspace((unsigned char)input[i]) == false)
			return false;
		if (std::isalpha((unsigned char)input[i]))
			has_alpha = true;
	}
	return has_alpha;
}

bool	valid_number(const std::string &input) {
	if (input.empty())
		return false;
	for (size_t i = 0; i < input.length(); i++)
	{
		if (std::isdigit((unsigned char)input[i]) == false)
			return false;
	}
	return true;
}

int	valid_index(int pb_size, const std::string &input) {
	size_t	length = input.length();
	int		index;

	if (input.empty() == true || length > 2)
		return -1;
	for (size_t i = 0; i < length; i++)
	{
		if (std::isdigit((unsigned char)input[i]) == false)
			return -1;
	}
	index = std::atoi(input.c_str());
	if (index < 1 || index > pb_size)
		return -1;
	return index;
}
