#include "phonebook.hpp"

void	handleCommand(Phonebook &pb, const std::string &line)
{
	if (line == "ADD")
		pb.phonebookAdd();
	else if (line == "SEARCH")
		pb.phonebookSearch();
	else if (line == "EXIT")
		exitProgram();
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
			exitProgram();
		handleCommand(pb, line);
	}
	return (0);
}
