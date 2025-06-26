#include "Weapon.hpp"

// Constructor
Weapon::Weapon(std::string type) : type(type) {
}

// Get the weapon type (returns a const reference)
const std::string& Weapon::getType() const {
    return this->type;
}

// Set a new weapon type
void Weapon::setType(std::string newType) {
    this->type = newType;
}
