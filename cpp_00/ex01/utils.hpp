#ifndef UTILS_HPP
# define UTILS_HPP

# include <string>
# include <cstdlib>
# include <iostream>

void		exitProgram(void);
std::string	inputWaiting(const std::string &msg);
bool		validName(const std::string &input);
bool		validNumber(const std::string &input);
std::string	truncate(const std::string &str);

#endif
