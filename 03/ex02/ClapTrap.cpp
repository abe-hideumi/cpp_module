#include "ClapTrap.hpp"
#include <iostream>

static const int initHitPoint = 10;
static const int initEnergyPoint = 10;
static const int initAttackDamage = 0;

bool ClapTrap::checkPoint(void) {
    if (this->_hitPoint <= 0)
        return (std::cout << "Your hitPoints are 0\n", true);
    if (this->_energyPoint <= 0)
        return (std::cout << "Your energyPoints are 0\n", true);
    return(false);
}

ClapTrap::~ClapTrap() {
    std::cout << "deleted the ClapTrap with this " << this->_name << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) {
    this->_hitPoint = initHitPoint;
    this->_energyPoint = initEnergyPoint;
    this->_attackDamage = initAttackDamage;
    this->_name = name;   
    std::cout << "created a ClapTrap with this " << this->_name << std::endl;  
}

void ClapTrap::attack(const std::string& target) {
    if (checkPoint())
        return ;
    std::cout << "ClapTrap " << this->_name
          << " attacks " << target
          << ", causing " << this->_attackDamage
          << " points of Damage!\n";
    this->_energyPoint--;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if ((unsigned int)this->_hitPoint <= amount)
        this->_hitPoint = 0;
    else
        this->_hitPoint -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (checkPoint())
        return ;
    std::cout << "ClapTrap " << this->_name
          << " repaired hitPoints " << amount << std::endl;
    this->_hitPoint += amount;
    this->_energyPoint--;
}
