#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::~Zombie() {
	std::cout << this->name << ": is destroyed.\n";
}

void	Zombie::announce(void) {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ...\n";
}

void	Zombie::naming(const std::string& name) {
	this->name = name;
}
