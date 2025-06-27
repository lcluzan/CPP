#include "Cat.hpp"

Cat::Cat() {
    type = "Cat";
    brain = new Brain();
}

Cat::Cat(const Cat& other) : Animal(other) {
    brain = new Brain(*other.brain);
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Cat::~Cat() {
    delete brain;
}

void Cat::makeSound() const {
    std::cout << "Meow!" << std::endl;
}

void Cat::setIdea(int index, const std::string& idea) {
    brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const {
    return brain->getIdea(index);
}
