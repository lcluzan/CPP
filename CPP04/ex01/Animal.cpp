#include "Animal.hpp"

// Default constructor
Animal::Animal() : type("Generic Animal") {
    std::cout << "Animal default constructor called" << std::endl;
}

// Copy constructor
Animal::Animal(const Animal& other) : type(other.type) {
    std::cout << "Animal copy constructor called" << std::endl;
}

// Copy assignment operator
Animal& Animal::operator=(const Animal& other) {
    std::cout << "Animal copy assignment operator called" << std::endl;
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

// Destructor
Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}

// Getter for type
std::string Animal::getType() const {
    return type;
}

// Base class sound implementation
void Animal::makeSound() const {
    std::cout << "* Generic animal sound *" << std::endl;
}
