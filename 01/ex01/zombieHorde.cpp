#include "Zombie.hpp"
#include <sstream>

Zombie* zombieHorde(int N, std::string name){
	Zombie	*zombies = new Zombie[N];

	for (int i = 0; i < N; i++) {
		std::ostringstream	number;
		number << "_" << i + 1;
		zombies[i].naming(name + number.str());
	}
	return zombies;
}
