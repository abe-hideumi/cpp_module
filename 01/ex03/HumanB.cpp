#include "HumanB.hpp"

HumanB::HumanB(const std::string& n) : name(n), weapon(NULL) {}

void	HumanB::setWeapon(Weapon& weapon) {
	this->weapon = &weapon;
}

void	HumanB::attack() {
	if (!weapon) {
		std::cout << name << " has no weapon." << std::endl;
		return ;
	}
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}
