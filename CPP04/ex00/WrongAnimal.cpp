#include "WrongAnimal.hpp"

// Default constructor
WrongAnimal::WrongAnimal() : type("Wrong Generic Animal") {
    std::cout << "WrongAnimal default constructor called" << std::endl;
}

// Copy constructor
WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type) {
    std::cout << "WrongAnimal copy constructor called" << std::endl;
}

// Copy assignment operator
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    std::cout << "WrongAnimal copy assignment operator called" << std::endl;
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

// Destructor
WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor called" << std::endl;
}

// Getter for type
std::string WrongAnimal::getType() const {
    return type;
}

// Non-virtual sound implementation
void WrongAnimal::makeSound() const {
    std::cout << "* Wrong generic animal sound *" << std::endl;
}
