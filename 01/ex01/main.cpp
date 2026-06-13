#include "Zombie.hpp"

// test function
static void	announceZombies(Zombie* zombies, int N) {
	for (int i = 0; i < N; i++) {
		zombies[i].announce();
	}
}

int	main() {
	int	N = 5;
	Zombie	*zombies = zombieHorde(N, "Habe");
	announceZombies(zombies, N);
	delete[] zombies;
	return 0;
}
