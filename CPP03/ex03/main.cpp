#include "DiamondTrap.hpp"
#include <iostream>

int main(void)
{
    // Test constructors
    std::cout << "\n=== Testing Constructors ===" << std::endl;
    DiamondTrap defaultTrap;
    DiamondTrap hero("Hero");
    DiamondTrap heroCopy(hero);

    // Test assignment operator
    std::cout << "\n=== Testing Assignment ===" << std::endl;
    DiamondTrap warrior("Warrior");
    warrior = hero;

    // Test inherited ScavTrap attack
    std::cout << "\n=== Testing ScavTrap's Attack ===" << std::endl;
    hero.attack("Enemy");  // Should use ScavTrap's attack

    // Test FragTrap's high HP and attack damage
    std::cout << "\n=== Testing FragTrap Stats ===" << std::endl;
    hero.takeDamage(50);   // Should have 50 HP remaining (from 100)
    hero.attack("Enemy");  // Should do 30 damage
    hero.beRepaired(30);   // Should heal to 80 HP

    // Test ScavTrap's special ability
    std::cout << "\n=== Testing ScavTrap's Guard Gate ===" << std::endl;
    hero.guardGate();

    // Test FragTrap's special ability
    std::cout << "\n=== Testing FragTrap's High Fives ===" << std::endl;
    hero.highFivesGuys();

    // Test DiamondTrap's special ability
    std::cout << "\n=== Testing DiamondTrap's Who Am I ===" << std::endl;
    hero.whoAmI();

    // Test durability
    std::cout << "\n=== Testing Durability ===" << std::endl;
    hero.takeDamage(70);   // Should have 10 HP remaining
    hero.attack("Enemy");  // Should still work
    hero.takeDamage(20);   // Should die
    hero.attack("Enemy");  // Should fail - dead

    // Test energy points
    std::cout << "\n=== Testing Energy Points ===" << std::endl;
    DiamondTrap energyTester("EnergyTester");
    // DiamondTrap has 50 energy points (from ScavTrap)
    for (int i = 0; i < 25; i++)
    {
        std::cout << "Attack " << i + 1 << ": ";
        energyTester.attack("Target");
        std::cout << "Repair " << i + 1 << ": ";
        energyTester.beRepaired(1);
    }
    // Should be out of energy
    energyTester.attack("Target");
    energyTester.beRepaired(1);

    // Special abilities should still work without energy
    std::cout << "\n=== Testing Special Abilities Without Energy ===" << std::endl;
    energyTester.guardGate();
    energyTester.highFivesGuys();
    energyTester.whoAmI();

    std::cout << "\n=== End of Tests ===" << std::endl;
    return 0;
}
