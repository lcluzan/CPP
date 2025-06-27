#include "ClapTrap.hpp"
#include <iostream>

// Default constructor
ClapTrap::ClapTrap(void) :
    name("unnamed"),
    hitPoints(10),
    energyPoints(10),
    attackDamage(0)
{
    std::cout << "ClapTrap default constructor called" << std::endl;
}

// Parameterized constructor
ClapTrap::ClapTrap(const std::string& name) :
    name(name),
    hitPoints(10),
    energyPoints(10),
    attackDamage(0)
{
    std::cout << "ClapTrap parameterized constructor called for " << name << std::endl;
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap& src)
{
    std::cout << "ClapTrap copy constructor called" << std::endl;
    *this = src;
}

// Destructor
ClapTrap::~ClapTrap(void)
{
    std::cout << "ClapTrap destructor called for " << this->name << std::endl;
}

// Copy assignment operator
ClapTrap& ClapTrap::operator=(const ClapTrap& rhs)
{
    std::cout << "ClapTrap copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        this->name = rhs.name;
        this->hitPoints = rhs.hitPoints;
        this->energyPoints = rhs.energyPoints;
        this->attackDamage = rhs.attackDamage;
    }
    return *this;
}

// Member functions
void ClapTrap::attack(const std::string& target)
{
    if (this->energyPoints == 0)
    {
        std::cout << "ClapTrap " << this->name << " has no energy points left to attack!" << std::endl;
        return;
    }
    if (this->hitPoints == 0)
    {
        std::cout << "ClapTrap " << this->name << " is dead and cannot attack!" << std::endl;
        return;
    }

    std::cout << "ClapTrap " << this->name << " attacks " << target
              << ", causing " << this->attackDamage << " points of damage!" << std::endl;
    this->energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->hitPoints == 0)
    {
        std::cout << "ClapTrap " << this->name << " is already dead!" << std::endl;
        return;
    }

    if (amount >= this->hitPoints)
    {
        this->hitPoints = 0;
        std::cout << "ClapTrap " << this->name << " takes " << amount
                  << " points of damage and dies!" << std::endl;
    }
    else
    {
        this->hitPoints -= amount;
        std::cout << "ClapTrap " << this->name << " takes " << amount
                  << " points of damage! " << this->hitPoints << " HP remaining." << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->energyPoints == 0)
    {
        std::cout << "ClapTrap " << this->name << " has no energy points left to repair!" << std::endl;
        return;
    }
    if (this->hitPoints == 0)
    {
        std::cout << "ClapTrap " << this->name << " is dead and cannot be repaired!" << std::endl;
        return;
    }

    this->hitPoints += amount;
    this->energyPoints--;
    std::cout << "ClapTrap " << this->name << " repairs itself for " << amount
              << " points! Now has " << this->hitPoints << " HP." << std::endl;
}

// Getters
std::string ClapTrap::getName(void) const
{
    return this->name;
}

unsigned int ClapTrap::getHitPoints(void) const
{
    return this->hitPoints;
}

unsigned int ClapTrap::getEnergyPoints(void) const
{
    return this->energyPoints;
}

unsigned int ClapTrap::getAttackDamage(void) const
{
    return this->attackDamage;
}
