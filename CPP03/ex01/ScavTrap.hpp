#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
    // Orthodox Canonical Form
    ScavTrap(void);                         // Default constructor
    ScavTrap(const std::string& name);      // Parameterized constructor
    ScavTrap(const ScavTrap& src);          // Copy constructor
    ~ScavTrap(void);                        // Destructor
    ScavTrap& operator=(const ScavTrap& rhs); // Copy assignment operator

    // Member functions
    void attack(const std::string& target);  // Override ClapTrap's attack
    void guardGate(void);                    // New function
};

#endif
