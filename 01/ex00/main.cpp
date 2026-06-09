#include "Zombie.hpp"

int	main() {
	Zombie	*z1 = newZombie("Habe");
	randomChump("42tokyo");
	z1->announce();
	delete z1;
	return 0;
}
