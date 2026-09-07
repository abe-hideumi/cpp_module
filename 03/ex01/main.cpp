#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
    std::cout << "===== ScavTrap test =====" << std::endl;

    ScavTrap scav("habe");

    std::cout << "\n===== Attack =====" << std::endl;
    scav.attack("enemy");

    std::cout << "\n===== Guard Gate =====" << std::endl;
    scav.guardGate();

    std::cout << "\n===== Take Damage =====" << std::endl;
    scav.takeDamage(30);

    std::cout << "\n===== Repair =====" << std::endl;
    scav.beRepaired(20);

    std::cout << "\n===== Destruction =====" << std::endl;

    return (0);
}
