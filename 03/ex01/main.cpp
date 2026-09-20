#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
    std::cout << "===== ClapTrap alone =====" << std::endl;
    ClapTrap clap("42tokyo");
    clap.attack("enemy");

    std::cout << "\n===== ScavTrap construction chaining =====" << std::endl;
    ScavTrap scav("habe");

    std::cout << "\n===== Attack (ScavTrap message) =====" << std::endl;
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

    std::cout << "\n===== Out of energy (inner scope) =====" << std::endl;
    {
        ScavTrap tired("tired");
        for (int i = 0; i < 50; i++)
            tired.attack("enemy");
        tired.attack("enemy");
        tired.beRepaired(10);
        tired.guardGate();
        std::cout << "--- leaving the inner scope ---" << std::endl;
    }

    std::cout << "\n===== Lethal damage (inner scope) =====" << std::endl;
    {
        ScavTrap victim("victim");
        victim.takeDamage(40);
        victim.takeDamage(100);
        victim.attack("enemy");
        victim.beRepaired(50);
        victim.takeDamage(10);
        victim.guardGate();
        std::cout << "--- leaving the inner scope ---" << std::endl;
    }

    std::cout << "\n===== Destruction chaining =====" << std::endl;
    return (0);
}
