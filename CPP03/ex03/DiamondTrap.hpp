#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
private:
    std::string name;

public:
    // Orthodox Canonical Form
    DiamondTrap(void);                           // Default constructor
    DiamondTrap(const std::string& name);        // Parameterized constructor
    DiamondTrap(const DiamondTrap& src);         // Copy constructor
    ~DiamondTrap(void);                          // Destructor
    DiamondTrap& operator=(const DiamondTrap& rhs); // Copy assignment operator

    // Member functions
    void whoAmI(void);                           // Special ability
    using ScavTrap::attack;                      // Use ScavTrap's attack
};

#endif
