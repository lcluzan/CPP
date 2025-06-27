#include "Character.hpp"
#include <iostream>

Character::Character(std::string const & name) : name(name) {
    for (int i = 0; i < inventorySize; i++) {
        inventory[i] = NULL;
    }
}

Character::Character(const Character& other) : name(other.name) {
    for (int i = 0; i < inventorySize; i++) {
        if (other.inventory[i])
            inventory[i] = other.inventory[i]->clone();
        else
            inventory[i] = NULL;
    }
}

Character& Character::operator=(const Character& other) {
    if (this != &other) {
        name = other.name;
        // Delete current inventory
        for (int i = 0; i < inventorySize; i++) {
            delete inventory[i];
            if (other.inventory[i])
                inventory[i] = other.inventory[i]->clone();
            else
                inventory[i] = NULL;
        }
    }
    return *this;
}

Character::~Character() {
    for (int i = 0; i < inventorySize; i++) {
        delete inventory[i];
    }
}

std::string const & Character::getName() const {
    return name;
}

void Character::equip(AMateria* m) {
    if (!m) return;

    for (int i = 0; i < inventorySize; i++) {
        if (!inventory[i]) {
            inventory[i] = m;
            return;
        }
    }
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx < inventorySize) {
        inventory[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter& target) {
    if (idx >= 0 && idx < inventorySize && inventory[idx]) {
        inventory[idx]->use(target);
    }
}
