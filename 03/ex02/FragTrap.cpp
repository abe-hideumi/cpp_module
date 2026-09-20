#include "FragTrap.hpp"
#include <iostream>

static const unsigned int   initHitPoint = 100;
static const unsigned int   initEnergyPoint = 100;
static const unsigned int   initAttackDamage = 30;

FragTrap::FragTrap() : ClapTrap() {
    this->_hitPoint = initHitPoint;
    this->_energyPoint = initEnergyPoint;
    this->_attackDamage = initAttackDamage;
    std::cout << "FragTrap " << this->_name
              << " is created by the default constructor" << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
    this->_hitPoint = initHitPoint;
    this->_energyPoint = initEnergyPoint;
    this->_attackDamage = initAttackDamage;
    std::cout << "FragTrap " << this->_name
              << " is created by the name constructor" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
    std::cout << "FragTrap " << this->_name
              << " is created by the copy constructor" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
    ClapTrap::operator=(other);
    std::cout << "FragTrap " << this->_name
              << " is assigned by the copy assignment operator" << std::endl;
    return (*this);
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << this->_name << " is destroyed" << std::endl;
}

void FragTrap::attack(const std::string &target) {
    if (!this->canAct("attack"))
        return ;
    this->_energyPoint--;
    std::cout << "FragTrap " << this->_name
              << " attacks " << target
              << ", causing " << this->_attackDamage
              << " points of damage!"
              << " (" << this->_energyPoint << " energy points left)" << std::endl;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << this->_name
              << " requests a high five!" << std::endl;
}
