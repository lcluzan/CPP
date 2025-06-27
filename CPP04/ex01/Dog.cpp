#include "Dog.hpp"

// Default constructor
Dog::Dog() : Animal() {
    std::cout << "Dog default constructor called" << std::endl;
    type = "Dog";
    brain = new Brain();  // Create new Brain
}

// Copy constructor - Deep copy
Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << "Dog copy constructor called" << std::endl;
    brain = new Brain(*other.brain);  // Create new Brain as a copy
}

// Copy assignment operator - Deep copy
Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);  // Handle base class assignment
        delete brain;              // Delete old brain
        brain = new Brain(*other.brain);  // Create new Brain as a copy
    }
    return *this;
}

// Destructor
Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
    delete brain;  // Clean up Brain
}

// Dog specific sound implementation
void Dog::makeSound() const {
    std::cout << "Woof! Woof!" << std::endl;
}

// Brain related functions
void Dog::setIdea(int index, const std::string& idea) {
    brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const {
    return brain->getIdea(index);
}
