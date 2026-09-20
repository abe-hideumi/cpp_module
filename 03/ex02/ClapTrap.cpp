#include "ClapTrap.hpp"
#include <iostream>
#include <limits>

static const unsigned int   initHitPoint = 10;
static const unsigned int   initEnergyPoint = 10;
static const unsigned int   initAttackDamage = 0;

ClapTrap::ClapTrap() :
    _name("default"),
    _hitPoint(initHitPoint),
    _energyPoint(initEnergyPoint),
    _attackDamage(initAttackDamage) {
    std::cout << "ClapTrap " << this->_name
              << " is created by the default constructor" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) :
    _name(name),
    _hitPoint(initHitPoint),
    _energyPoint(initEnergyPoint),
    _attackDamage(initAttackDamage) {
    std::cout << "ClapTrap " << this->_name
              << " is created by the name constructor" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) :
    _name(other._name),
    _hitPoint(other._hitPoint),
    _energyPoint(other._energyPoint),
    _attackDamage(other._attackDamage) {
    std::cout << "ClapTrap " << this->_name
              << " is created by the copy constructor" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
    if (this != &other) {
        this->_name = other._name;
        this->_hitPoint = other._hitPoint;
        this->_energyPoint = other._energyPoint;
        this->_attackDamage = other._attackDamage;
    }
    std::cout << "ClapTrap " << this->_name
              << " is assigned by the copy assignment operator" << std::endl;
    return (*this);
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << this->_name << " is destroyed" << std::endl;
}

bool ClapTrap::canAct(const std::string &action) {
    if (this->_hitPoint == 0) {
        std::cout << "ClapTrap " << this->_name << " can't " << action
                  << ": it has no hit points left!" << std::endl;
        return (false);
    }
    if (this->_energyPoint == 0) {
        std::cout << "ClapTrap " << this->_name << " can't " << action
                  << ": it has no energy points left!" << std::endl;
        return (false);
    }
    return (true);
}

void ClapTrap::attack(const std::string &target) {
    if (!this->canAct("attack"))
        return ;
    this->_energyPoint--;
    std::cout << "ClapTrap " << this->_name
              << " attacks " << target
              << ", causing " << this->_attackDamage
              << " points of damage!"
              << " (" << this->_energyPoint << " energy points left)" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (this->_hitPoint == 0) {
        std::cout << "ClapTrap " << this->_name
                  << " takes no damage: it is already destroyed!" << std::endl;
        return ;
    }
    if (amount >= this->_hitPoint)
        this->_hitPoint = 0;
    else
        this->_hitPoint -= amount;
    std::cout << "ClapTrap " << this->_name
              << " takes " << amount << " points of damage!"
              << " (" << this->_hitPoint << " hit points left)" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (!this->canAct("be repaired"))
        return ;
    this->_energyPoint--;
    if (amount > std::numeric_limits<unsigned int>::max() - this->_hitPoint)
        this->_hitPoint = std::numeric_limits<unsigned int>::max();
    else
        this->_hitPoint += amount;
    std::cout << "ClapTrap " << this->_name
              << " is repaired by " << amount << " hit points!"
              << " (" << this->_hitPoint << " hit points left)" << std::endl;
}
