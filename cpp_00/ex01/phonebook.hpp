#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
# include <iostream>
# include <iomanip>
# include "contact.hpp"
# include "utils.hpp"

const int	MAX_CONTACTS = 8;

class Phonebook {
	private:
		int			pbSize;
		int			inputIndex;
		Contact		contacts[MAX_CONTACTS];
		void		allDisplay();
		void		detailDisplay(const Contact &c);
		int			validIndex(const std::string &input);
		bool		fillFromInput();

	public:
		Phonebook() : pbSize(0), inputIndex(0) {}
		bool		phonebookAdd();
		void		phonebookSearch();
};

#endif
