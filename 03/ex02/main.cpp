#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main(void)
{
    std::cout << "===== ClapTrap construction =====" << std::endl;
    ClapTrap clap("42");

    std::cout << "\n===== ScavTrap construction chaining =====" << std::endl;
    ScavTrap scav("tokyo");

    std::cout << "\n===== FragTrap construction chaining =====" << std::endl;
    FragTrap frag("habe");

    std::cout << "\n===== Three different attack messages =====" << std::endl;
    clap.attack("enemy");
    scav.attack("enemy");
    frag.attack("enemy");

    std::cout << "\n===== Special abilities =====" << std::endl;
    scav.guardGate();
    frag.highFivesGuys();

    std::cout << "\n===== TakeDamage / Repair =====" << std::endl;
    frag.takeDamage(40);
    frag.beRepaired(20);

    std::cout << "\n===== Copy constructor =====" << std::endl;
    FragTrap copy(frag);
    copy.attack("enemy");

    std::cout << "\n===== Copy assignment =====" << std::endl;
    FragTrap other("other");
    other = frag;
    other.attack("enemy");

    std::cout << "\n===== Destruction chaining =====" << std::endl;
    return (0);
}
