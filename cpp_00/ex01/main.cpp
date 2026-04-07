#include "phonebook.hpp"

int	main(int ac, char **av) {
	Command cmd;
	Phonebook pb;
	std::string	line;

	if (ac != 1 && av[1] != NULL)
		return (std::cout << "Usage: ./phonebook" << std::endl, 1);
	pb.count = -1;
	while (1)
	{
		std::cout << "phonebook: ";
		std::getline(std::cin, line);
		if (line == "EXIT")
		{
			cmd.EXIT();
			break ;
		}
		else if (line == "ADD")
		{
			if (pb.count < 7)
				pb.count++;
			if (cmd.ADD(&pb.contacts[pb.count]) == false)
			{
				std::cout << "cannot be empty. Contact not added." << std::endl;
				if (pb.count != -1 && pb.count == 7)
					pb.count--;
			}
		}
		else if (line == "SEARCH")
			cmd.SEARCH(&pb);
		else
			continue ;
	}
	return (0);
}
