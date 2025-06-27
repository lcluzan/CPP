#include "Cat.hpp"

// Default constructor
Cat::Cat() : Animal() {
    std::cout << "Cat default constructor called" << std::endl;
    type = "Cat";
    brain = new Brain();  // Create new Brain
}

// Copy constructor - Deep copy
Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << "Cat copy constructor called" << std::endl;
    brain = new Brain(*other.brain);  // Create new Brain as a copy
}

// Copy assignment operator - Deep copy
Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat copy assignment operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);  // Handle base class assignment
        delete brain;              // Delete old brain
        brain = new Brain(*other.brain);  // Create new Brain as a copy
    }
    return *this;
}

// Destructor
Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
    delete brain;  // Clean up Brain
}

// Cat specific sound implementation
void Cat::makeSound() const {
    std::cout << "Meow! Meow!" << std::endl;
}

// Brain related functions
void Cat::setIdea(int index, const std::string& idea) {
    brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const {
    return brain->getIdea(index);
}
