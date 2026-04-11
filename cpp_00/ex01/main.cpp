#include "phonebook.hpp"

bool	handle_command(Phonebook &pb, const std::string &line, int &i)
{
	if (line == "ADD")
	{
		if (pb.contacts[i].ADD() == true)
		{
			if (pb.count < MAX_CONTACTS)
				pb.count++;
			return true;
		}
		else
			std::cout << "Failed to add contact. Please try again." << std::endl;
	}
	else if (line == "SEARCH")
		pb.SEARCH();
	else if (line == "EXIT")
		EXIT();
	else
		std::cout << "Invalid command. Please enter ADD, SEARCH, or EXIT." << std::endl;
	return false;
}

int	main(int ac, char **av) {
	Phonebook	pb;
	std::string	line;
	int			i;

	if (ac != 1 && av[1] != NULL)
		return (std::cout << "Usage: ./phonebook" << std::endl, 1);
	pb.count = -1;
	i = -1;
	while (1)
	{
		if (i == MAX_CONTACTS)
			i = OLD_CONTACT;
		std::cout << "phonebook: ";
		std::getline(std::cin, line);
		handle_command(pb, line, i);
	}
	return (0);
}
