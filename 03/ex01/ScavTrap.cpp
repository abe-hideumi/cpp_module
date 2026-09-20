#include "ScavTrap.hpp"
#include <iostream>

static const unsigned int   initHitPoint = 100;
static const unsigned int   initEnergyPoint = 50;
static const unsigned int   initAttackDamage = 20;

ScavTrap::ScavTrap() : ClapTrap() {
    this->_hitPoint = initHitPoint;
    this->_energyPoint = initEnergyPoint;
    this->_attackDamage = initAttackDamage;
    std::cout << "ScavTrap " << this->_name
              << " is created by the default constructor" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
    this->_hitPoint = initHitPoint;
    this->_energyPoint = initEnergyPoint;
    this->_attackDamage = initAttackDamage;
    std::cout << "ScavTrap " << this->_name
              << " is created by the name constructor" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
    std::cout << "ScavTrap " << this->_name
              << " is created by the copy constructor" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
    ClapTrap::operator=(other);
    std::cout << "ScavTrap " << this->_name
              << " is assigned by the copy assignment operator" << std::endl;
    return (*this);
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << this->_name << " is destroyed" << std::endl;
}

void ScavTrap::attack(const std::string &target) {
    if (!this->canAct("attack"))
        return ;
    this->_energyPoint--;
    std::cout << "ScavTrap " << this->_name
              << " attacks " << target
              << ", causing " << this->_attackDamage
              << " points of damage!"
              << " (" << this->_energyPoint << " energy points left)" << std::endl;
}

void ScavTrap::guardGate(void) {
    std::cout << "ScavTrap " << this->_name
              << " is now in Gate keeper mode." << std::endl;
}
