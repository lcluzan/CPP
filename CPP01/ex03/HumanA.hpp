#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include "Weapon.hpp"

class HumanA {
private:
    std::string name;
    Weapon& weapon;  // Reference to weapon (must be initialized)

public:
    // Constructor
    HumanA(std::string name, Weapon& weapon);

    // Member function
    void attack() const;
};

#endif
