#include "DiamondTrap.hpp"
#include <iostream>

// Default constructor
DiamondTrap::DiamondTrap(void) :
    ClapTrap("unnamed_clap_name"),
    ScavTrap("unnamed_clap_name"),
    FragTrap("unnamed_clap_name"),
    name("unnamed")
{
    this->hitPoints = FragTrap::hitPoints;        // 100 HP from FragTrap
    this->energyPoints = ScavTrap::energyPoints;  // 50 EP from ScavTrap
    this->attackDamage = FragTrap::attackDamage;  // 30 AD from FragTrap
    std::cout << "DiamondTrap default constructor called" << std::endl;
}

// Parameterized constructor
DiamondTrap::DiamondTrap(const std::string& name) :
    ClapTrap(name + "_clap_name"),
    ScavTrap(name + "_clap_name"),
    FragTrap(name + "_clap_name"),
    name(name)
{
    this->hitPoints = FragTrap::hitPoints;        // 100 HP from FragTrap
    this->energyPoints = ScavTrap::energyPoints;  // 50 EP from ScavTrap
    this->attackDamage = FragTrap::attackDamage;  // 30 AD from FragTrap
    std::cout << "DiamondTrap " << name << " constructor called" << std::endl;
}

// Copy constructor
DiamondTrap::DiamondTrap(const DiamondTrap& src) :
    ClapTrap(src),
    ScavTrap(src),
    FragTrap(src),
    name(src.name)
{
    std::cout << "DiamondTrap copy constructor called" << std::endl;
    *this = src;
}

// Destructor
DiamondTrap::~DiamondTrap(void)
{
    std::cout << "DiamondTrap " << this->name << " destructor called" << std::endl;
}

// Copy assignment operator
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& rhs)
{
    std::cout << "DiamondTrap copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        ClapTrap::operator=(rhs);
        this->name = rhs.name;
    }
    return *this;
}

// Special ability
void DiamondTrap::whoAmI(void)
{
    std::cout << "I am DiamondTrap " << this->name
              << ", also known as ClapTrap " << ClapTrap::name << std::endl;
}
