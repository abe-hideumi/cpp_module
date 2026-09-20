#include "ClapTrap.hpp"
#include <iostream>

int main(void)
{
    std::cout << "===== Constructors =====" << std::endl;
    ClapTrap clap("42");
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

    std::cout << "\n===== Copy constructor =====" << std::endl;
    ClapTrap copy(clap);
    copy.attack("enemy");

    std::cout << "\n===== Copy assignment =====" << std::endl;
    nameless = clap;
    nameless.attack("enemy");

    std::cout << "\n===== Destructors =====" << std::endl;
    return (0);
}
