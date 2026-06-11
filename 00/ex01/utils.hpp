#ifndef UTILS_HPP
# define UTILS_HPP

# include <string>
# include <cstdlib>
# include <iostream>

# define MAX_CHAR 10

void		ExitProgram(void);
std::string	InputWaiting(const std::string &msg);
bool		ValidName(const std::string &input);
bool		ValidNumber(const std::string &input);
std::string	Truncate(const std::string &str);

#endif
