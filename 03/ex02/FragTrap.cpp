#include "FragTrap.hpp"
#include <iostream>
#include <string>

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
    _hitPoint = 100;
    _energyPoint = 100;
    _attackDamage = 30;
    std::cout << "FragTrap constructor\n";
}

FragTrap::~FragTrap() {
    std::cout << "deleted the FragTrap with this " << this->_name << std::endl;
}

void    FragTrap::attack(const std::string &target) {
    if (checkPoint())
        return ;
    std::cout << "FragTrap " << this->_name
                << " attacks " << target
                << ", causing " << this->_attackDamage
                << " points of Damage!\n";
    this->_energyPoint--;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << this->_name
              << " requests a high five!" << std::endl;
}
