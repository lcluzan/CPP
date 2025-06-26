#include "Zombie.hpp"
#include <iostream>

// Constructor implementation
Zombie::Zombie(std::string name) : name(name) {
    std::cout << "Zombie " << this->name << " is created" << std::endl;
}

// Destructor implementation
Zombie::~Zombie(void) {
    std::cout << "Zombie " << this->name << " is destroyed" << std::endl;
}

// Announce function implementation
void Zombie::announce(void) {
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
