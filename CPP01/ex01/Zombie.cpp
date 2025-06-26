#include "Zombie.hpp"
#include <iostream>

// Default constructor
Zombie::Zombie(void) {
    std::cout << "A nameless zombie is created" << std::endl;
}

// Named constructor
Zombie::Zombie(std::string name) : name(name) {
    std::cout << "Zombie " << this->name << " is created" << std::endl;
}

// Destructor
Zombie::~Zombie(void) {
    std::cout << "Zombie " << this->name << " is destroyed" << std::endl;
}

// Announce function
void Zombie::announce(void) {
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

// Setter for name
void Zombie::setName(std::string name) {
    this->name = name;
}
