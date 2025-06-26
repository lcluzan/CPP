#include "HumanA.hpp"
#include <iostream>

// Constructor - initializes name and weapon reference
HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon) {
}

// Attack function
void HumanA::attack() const {
    std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}
