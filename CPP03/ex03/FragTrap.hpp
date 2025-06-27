#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
public:
    // Orthodox Canonical Form
    FragTrap(void);                         // Default constructor
    FragTrap(const std::string& name);      // Parameterized constructor
    FragTrap(const FragTrap& src);          // Copy constructor
    ~FragTrap(void);                        // Destructor
    FragTrap& operator=(const FragTrap& rhs); // Copy assignment operator

    // Member functions
    void highFivesGuys(void);               // Special ability
};

#endif
