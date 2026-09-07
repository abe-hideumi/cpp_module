#include "FragTrap.hpp"
#include <iostream>

int main(void)
{
    std::cout << "===== FragTrap test =====" << std::endl;

    FragTrap frag("habe");

    std::cout << "\n===== Attack =====" << std::endl;
    frag.attack("enemy");

    std::cout << "\n===== Take Damage =====" << std::endl;
    frag.takeDamage(30);

    std::cout << "\n===== Repair =====" << std::endl;
    frag.beRepaired(20);

    std::cout << "\n===== High Five =====" << std::endl;
    frag.highFivesGuys();

    std::cout << "\n===== Destruction =====" << std::endl;

    return (0);
}
