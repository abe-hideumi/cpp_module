#include "Harl.hpp"

// colors
static const std::string RED = "\033[31m";
static const std::string YELLOW = "\033[33m";
static const std::string BLUE = "\033[34m";
static const std::string GREEN = "\033[32m";
static const std::string RESET = "\033[0m";

// messages
static const std::string DebugMsg = "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!";
static const std::string InfoMsg = "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!";
static const std::string WarningMsg = "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month.";
static const std::string ErrorMsg = "This is unacceptable! I want to speak to the manager now.";

// functions
void	Harl::debug(void) {
	std::cout << GREEN << "[DEBUG] " << RESET  << DebugMsg << std::endl;
}

void	Harl::info(void) {
	std::cout << BLUE << "[INFO] " << RESET << InfoMsg << std::endl;
}

void	Harl::warning(void) {
	std::cout << YELLOW << "[WARNING] " << RESET << WarningMsg << std::endl;
}

void	Harl::error(void) {
	std::cout << RED << "[ERROR] " << RESET << ErrorMsg << std::endl;
}

void	Harl::complain(std::string level) {
	static const std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	static void	(Harl::*funcs[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i = 0; i < 4; i++) {
		if (level == levels[i]) {
			(this->*funcs[i])();
			return ;
		}
	}
}
