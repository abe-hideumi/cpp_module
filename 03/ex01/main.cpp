#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
    std::cout << "===== ClapTrap construction =====" << std::endl;
    ClapTrap clap("42");

    std::cout << "\n===== ScavTrap construction chaining =====" << std::endl;
    ScavTrap scav("tokyo");

    std::cout << "\n===== Two different attack messages =====" << std::endl;
    clap.attack("enemy");
    scav.attack("enemy");

    std::cout << "\n===== Guard gate =====" << std::endl;
    scav.guardGate();

    std::cout << "\n===== TakeDamage / Repair =====" << std::endl;
    scav.takeDamage(30);
    scav.beRepaired(20);

    std::cout << "\n===== Copy constructor =====" << std::endl;
    ScavTrap copy(scav);
    copy.attack("enemy");

    std::cout << "\n===== Copy assignment =====" << std::endl;
    ScavTrap other("other");
    other = scav;
    other.attack("enemy");

    std::cout << "\n===== Destruction chaining =====" << std::endl;
    return (0);
}
