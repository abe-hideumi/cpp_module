#include "ClapTrap.hpp"
#include <iostream>

int main(void)
{
    std::cout << "===== Constructor =====" << std::endl;
    ClapTrap clap("habe");

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

    std::cout << "\n===== Lethal damage =====" << std::endl;
    clap.takeDamage(100);

    std::cout << "\n===== Action with 0 HP =====" << std::endl;
    clap.attack("enemy");
    clap.beRepaired(5);

    std::cout << "\n===== Destructor =====" << std::endl;

    return (0);
}
