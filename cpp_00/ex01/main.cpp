#include "phonebook.hpp"

void	handle_command(Phonebook &pb, const std::string &line)
{
	if (line == "ADD")
		pb.phonebook_add();
	else if (line == "SEARCH")
		pb.phonebook_search();
	else if (line == "EXIT")
		exit_program();
	return ;
}

int	main(int ac, char *av[]) {
	Phonebook	pb;
	std::string	line;

	(void)av;
	if (ac != 1)
		return (std::cout << "Usage: ./phonebook" << std::endl, 1);
	while (1)
	{
		std::cout << "phonebook: ";
		std::getline(std::cin, line);
		if (std::cin.eof() == true)
			exit_program();
		handle_command(pb, line);
	}
	return (0);
}
