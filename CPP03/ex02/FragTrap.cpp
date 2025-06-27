#include "FragTrap.hpp"
#include <iostream>

// Default constructor
FragTrap::FragTrap(void) : ClapTrap()
{
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
    std::cout << "FragTrap default constructor called" << std::endl;
}

// Parameterized constructor
FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
    std::cout << "FragTrap " << name << " constructor called" << std::endl;
}

// Copy constructor
FragTrap::FragTrap(const FragTrap& src) : ClapTrap(src)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
    *this = src;
}

// Destructor
FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap " << this->name << " destructor called" << std::endl;
}

// Copy assignment operator
FragTrap& FragTrap::operator=(const FragTrap& rhs)
{
    std::cout << "FragTrap copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        ClapTrap::operator=(rhs);
    }
    return *this;
}

// Special ability
void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << this->name << " requests a positive high five! ✋" << std::endl;
}
