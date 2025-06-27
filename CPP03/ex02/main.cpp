#include "FragTrap.hpp"
#include <iostream>

int main(void)
{
    // Test constructors
    std::cout << "\n=== Testing Constructors ===" << std::endl;
    FragTrap defaultTrap;
    FragTrap warrior("Warrior");
    FragTrap warriorCopy(warrior);

    // Test assignment operator
    std::cout << "\n=== Testing Assignment ===" << std::endl;
    FragTrap champion("Champion");
    champion = warrior;

    // Test combat with high stats
    std::cout << "\n=== Testing Combat Functions ===" << std::endl;
    warrior.attack("Enemy");  // Should do 30 damage
    warrior.takeDamage(50);   // Should have 50 HP remaining
    warrior.beRepaired(30);   // Should heal to 80 HP

    // Test special ability
    std::cout << "\n=== Testing High Fives Guys ===" << std::endl;
    warrior.highFivesGuys();

    // Test durability
    std::cout << "\n=== Testing Durability ===" << std::endl;
    warrior.takeDamage(70);   // Should have 10 HP remaining
    warrior.attack("Enemy");  // Should still work
    warrior.takeDamage(20);   // Should die
    warrior.attack("Enemy");  // Should fail - dead
    warrior.highFivesGuys();  // Should still work even when dead

    // Test energy points
    std::cout << "\n=== Testing Energy Points ===" << std::endl;
    FragTrap energyTester("EnergyTester");
    // FragTrap has 100 energy points, let's use them all
    for (int i = 0; i < 50; i++)
    {
        std::cout << "Attack " << i + 1 << ": ";
        energyTester.attack("Target");
        std::cout << "Repair " << i + 1 << ": ";
        energyTester.beRepaired(1);
    }
    // Should be out of energy
    energyTester.attack("Target");
    energyTester.beRepaired(1);
    // Special ability should still work without energy
    energyTester.highFivesGuys();

    std::cout << "\n=== End of Tests ===" << std::endl;
    return 0;
}
