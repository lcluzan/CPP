#include "Brain.hpp"

// Default constructor
Brain::Brain() {
    std::cout << "Brain default constructor called" << std::endl;
    // Initialize all ideas with default values
    for (int i = 0; i < 100; i++) {
        ideas[i] = "Empty thought";
    }
}

// Copy constructor - Deep copy
Brain::Brain(const Brain& other) {
    std::cout << "Brain copy constructor called" << std::endl;
    // Copy all ideas
    for (int i = 0; i < 100; i++) {
        ideas[i] = other.ideas[i];
    }
}

// Copy assignment operator - Deep copy
Brain& Brain::operator=(const Brain& other) {
    std::cout << "Brain copy assignment operator called" << std::endl;
    if (this != &other) {
        // Copy all ideas
        for (int i = 0; i < 100; i++) {
            ideas[i] = other.ideas[i];
        }
    }
    return *this;
}

// Destructor
Brain::~Brain() {
    std::cout << "Brain destructor called" << std::endl;
}

// Setter for idea
void Brain::setIdea(int index, const std::string& idea) {
    if (index >= 0 && index < 100) {
        ideas[index] = idea;
    }
}

// Getter for idea
std::string Brain::getIdea(int index) const {
    if (index >= 0 && index < 100) {
        return ideas[index];
    }
    return "Invalid idea index";
}
