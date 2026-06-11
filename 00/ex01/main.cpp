#include "phonebook.hpp"

void	HandleCommand(Phonebook &pb, const std::string &line)
{
	if (line == "ADD")
		pb.PhoneBookAdd();
	else if (line == "SEARCH")
		pb.PhoneBookSearch();
	else if (line == "EXIT")
		ExitProgram();
	return ;
}

int	main(int ac, char **) {
	Phonebook	pb;
	std::string	line;

	if (ac != 1)
		return (std::cout << "Usage: ./phonebook" << std::endl, 1);
	while (1)
	{
		std::cout << "phonebook: ";
		std::getline(std::cin, line);
		if (std::cin.eof() == true)
			ExitProgram();
		HandleCommand(pb, line);
	}
	return (0);
}
