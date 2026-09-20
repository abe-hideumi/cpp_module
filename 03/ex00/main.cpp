#include "ClapTrap.hpp"
#include <iostream>

int main(void)
{
    std::cout << "===== Constructors =====" << std::endl;
    ClapTrap clap("habe");
    ClapTrap nameless;

    std::cout << "\n===== Attack =====" << std::endl;
    clap.attack("enemy");
    clap.attack("enemy");
    clap.attack("enemy");

    std::cout << "\n===== TakeDamage =====" << std::endl;
    clap.takeDamage(5);
    clap.takeDamage(3);

    std::cout << "\n===== Repair =====" << std::endl;
    clap.beRepaired(4);
    clap.beRepaired(2);

    std::cout << "\n===== Out of energy =====" << std::endl;
    for (int i = 0; i < 6; i++)
        clap.attack("enemy");
    clap.beRepaired(10);

    std::cout << "\n===== Copy constructor =====" << std::endl;
    ClapTrap copy(clap);
    copy.attack("enemy");

    std::cout << "\n===== Copy assignment =====" << std::endl;
    nameless = clap;
    nameless.attack("enemy");

    std::cout << "\n===== Lethal damage =====" << std::endl;
    ClapTrap victim("victim");
    victim.takeDamage(100);

    std::cout << "\n===== Action with 0 hit points =====" << std::endl;
    victim.attack("enemy");
    victim.beRepaired(5);
    victim.takeDamage(1);

    std::cout << "\n===== Destructors =====" << std::endl;
    return (0);
}
