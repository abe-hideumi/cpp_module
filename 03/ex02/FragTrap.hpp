#ifndef FragTrap_HPP
# define FragTrap_HPP

# include "ClapTrap.hpp"
#include <string>

class FragTrap : public ClapTrap {
    public:
        FragTrap(const std::string &namne);
        ~FragTrap();

        void    attack(const std::string &target);
        void    highFivesGuys(void);
};

#endif
