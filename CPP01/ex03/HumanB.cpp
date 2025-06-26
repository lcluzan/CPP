#include "HumanB.hpp"
#include <iostream>

// Constructor - initializes name and sets weapon to NULL
HumanB::HumanB(std::string name) : name(name), weapon(NULL) {
}

// Set weapon function
void HumanB::setWeapon(Weapon& weapon) {
    this->weapon = &weapon;
}

// Attack function
void HumanB::attack() const {
    if (this->weapon) {
        std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
    } else {
        std::cout << this->name << " has no weapon to attack with" << std::endl;
    }
}
