#include "ClapTrap.hpp"
#include <iostream>

int main(void)
{
    // Test constructors
    std::cout << "\n=== Testing Constructors ===" << std::endl;
    ClapTrap defaultTrap;
    ClapTrap bob("Bob");
    ClapTrap bobCopy(bob);

    // Test assignment operator
    std::cout << "\n=== Testing Assignment ===" << std::endl;
    ClapTrap alice("Alice");
    alice = bob;

    // Test attack and damage
    std::cout << "\n=== Testing Attack and Damage ===" << std::endl;
    bob.attack("Enemy");
    bob.takeDamage(5);
    bob.attack("Enemy");
    bob.takeDamage(10);
    bob.attack("Enemy"); // Should fail - dead

    // Test repair
    std::cout << "\n=== Testing Repair ===" << std::endl;
    ClapTrap charlie("Charlie");
    charlie.beRepaired(5);
    charlie.takeDamage(7);
    charlie.beRepaired(3);

    // Test energy points depletion
    std::cout << "\n=== Testing Energy Points Depletion ===" << std::endl;
    ClapTrap dave("Dave");
    for (int i = 0; i < 11; i++)
    {
        std::cout << "Attack " << i + 1 << ": ";
        dave.attack("Target");
    }

    // Test repair with no energy
    std::cout << "\n=== Testing Repair with No Energy ===" << std::endl;
    dave.beRepaired(5);

    std::cout << "\n=== End of Tests ===" << std::endl;
    return 0;
}
