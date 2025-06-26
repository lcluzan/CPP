#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include "Weapon.hpp"

class HumanB {
private:
    std::string name;
    Weapon* weapon;  // Pointer to weapon (can be NULL)

public:
    // Constructor
    HumanB(std::string name);

    // Member functions
    void setWeapon(Weapon& weapon);
    void attack() const;
};

#endif
