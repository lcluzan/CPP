#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap {
protected:
    std::string name;
    unsigned int hitPoints;
    unsigned int energyPoints;
    unsigned int attackDamage;

public:
    // Orthodox Canonical Form
    ClapTrap(void);                         // Default constructor
    ClapTrap(const std::string& name);      // Parameterized constructor
    ClapTrap(const ClapTrap& src);          // Copy constructor
    virtual ~ClapTrap(void);                // Virtual destructor
    ClapTrap& operator=(const ClapTrap& rhs); // Copy assignment operator

    // Member functions
    virtual void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    // Getters
    std::string getName(void) const;
    unsigned int getHitPoints(void) const;
    unsigned int getEnergyPoints(void) const;
    unsigned int getAttackDamage(void) const;
};

#endif
