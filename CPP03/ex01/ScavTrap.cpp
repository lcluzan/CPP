#include "ScavTrap.hpp"
#include <iostream>

// Default constructor
ScavTrap::ScavTrap(void) : ClapTrap()
{
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << "ScavTrap default constructor called" << std::endl;
}

// Parameterized constructor
ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << "ScavTrap parameterized constructor called for " << name << std::endl;
}

// Copy constructor
ScavTrap::ScavTrap(const ScavTrap& src) : ClapTrap(src)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

// Destructor
ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap destructor called for " << this->getName() << std::endl;
}

// Copy assignment operator
ScavTrap& ScavTrap::operator=(const ScavTrap& rhs)
{
    std::cout << "ScavTrap copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        ClapTrap::operator=(rhs);
    }
    return *this;
}

// Member functions
void ScavTrap::attack(const std::string& target)
{
    if (this->getEnergyPoints() == 0)
    {
        std::cout << "ScavTrap " << this->getName() << " has no energy points left to attack!" << std::endl;
        return;
    }
    if (this->getHitPoints() == 0)
    {
        std::cout << "ScavTrap " << this->getName() << " is dead and cannot attack!" << std::endl;
        return;
    }

    std::cout << "ScavTrap " << this->getName() << " attacks " << target
              << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
    this->energyPoints--;
}

void ScavTrap::guardGate(void)
{
    std::cout << "ScavTrap " << this->getName() << " is now in Gate keeper mode" << std::endl;
}
