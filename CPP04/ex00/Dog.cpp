#include "Dog.hpp"

// Default constructor
Dog::Dog() {
    type = "Dog";  // Set the type specific to Dog
    std::cout << "Dog default constructor called" << std::endl;
}

// Copy constructor
Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << "Dog copy constructor called" << std::endl;
}

// Copy assignment operator
Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
    }
    return *this;
}

// Destructor
Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
}

// Dog specific sound implementation
void Dog::makeSound() const {
    std::cout << "Woof! Woof!" << std::endl;
}
