#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name){
    _hitPoint = 100;
    _energyPoint = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap constructor\n";
}

ScavTrap::~ScavTrap(){
    std::cout << "deleted the ScavTrap with this " << this->_name << std::endl;
}

void    ScavTrap::attack(const std::string &target){
    if (checkPoint())
        return;
    std::cout << "ScavTrap " << this->_name
                << " attacks " << target
                << ", causing " << this->_attackDamage
                << " points of Damage!\n";
    this->_energyPoint--;
}

void    ScavTrap::guardGate(void){
    std::cout << " ScavTrap is now in Gatekeeper mode.\n";
}
