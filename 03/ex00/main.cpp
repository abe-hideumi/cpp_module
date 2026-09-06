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

    std::cout << "\n===== TakeDamege =====" << std::endl;
    clap.takeDamege(5);
    clap.takeDamege(3);

    std::cout << "\n===== Repair =====" << std::endl;
    clap.beRepaired(4);
    clap.beRepaired(2);

    std::cout << "\n===== Lethal damege =====" << std::endl;
    clap.takeDamege(100);

    std::cout << "\n===== Action with 0 HP =====" << std::endl;
    clap.attack("enemy");
    clap.beRepaired(5);

    std::cout << "\n===== Destructor test =====" << std::endl;

    return (0);
}
