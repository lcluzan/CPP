#include "Cat.hpp"

// Default constructor
Cat::Cat() {
    type = "Cat";  // Set the type specific to Cat
    std::cout << "Cat default constructor called" << std::endl;
}

// Copy constructor
Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << "Cat copy constructor called" << std::endl;
}

// Copy assignment operator
Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat copy assignment operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
    }
    return *this;
}

// Destructor
Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
}

// Cat specific sound implementation
void Cat::makeSound() const {
    std::cout << "Meow! Meow!" << std::endl;
}
