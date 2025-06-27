#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
    // Test constructors
    std::cout << "\n=== Testing Constructors ===" << std::endl;
    ScavTrap defaultTrap;
    ScavTrap guardian("Guardian");
    ScavTrap guardianCopy(guardian);

    // Test assignment operator
    std::cout << "\n=== Testing Assignment ===" << std::endl;
    ScavTrap defender("Defender");
    defender = guardian;

    // Test inherited functionality with new stats
    std::cout << "\n=== Testing Combat Functions ===" << std::endl;
    guardian.attack("Enemy");  // Should use ScavTrap's attack
    guardian.takeDamage(30);
    guardian.beRepaired(20);

    // Test unique ScavTrap function
    std::cout << "\n=== Testing Guard Gate Mode ===" << std::endl;
    guardian.guardGate();

    // Test durability with high damage
    std::cout << "\n=== Testing Durability ===" << std::endl;
    guardian.takeDamage(95);  // Should be close to death
    guardian.attack("Enemy"); // Should still work
    guardian.takeDamage(10);  // Should die
    guardian.attack("Enemy"); // Should fail - dead

    // Test energy points depletion
    std::cout << "\n=== Testing Energy Points Depletion ===" << std::endl;
    ScavTrap sentinel("Sentinel");
    for (int i = 0; i < 51; i++) // ScavTrap has 50 energy points
    {
        std::cout << "Attack " << i + 1 << ": ";
        sentinel.attack("Target");
    }

    // Test repair with no energy
    std::cout << "\n=== Testing Repair with No Energy ===" << std::endl;
    sentinel.beRepaired(5);
    sentinel.guardGate();  // Should still work even without energy

    std::cout << "\n=== End of Tests ===" << std::endl;
    return 0;
}
