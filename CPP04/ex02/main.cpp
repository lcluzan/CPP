#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

#define ARRAY_SIZE 4  // Must be even for half dogs and half cats

int main() {
    std::cout << "=== Testing Abstract Animal Class ===" << std::endl;

    // The following line would not compile because Animal is abstract:
    // const Animal* meta = new Animal();

    // But we can still create arrays of Animal pointers
    std::cout << "\n=== Testing Basic Animal Array ===" << std::endl;
    Animal* animals[ARRAY_SIZE];

    // Fill array with half dogs and half cats
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (i < ARRAY_SIZE / 2) {
            animals[i] = new Dog();
        } else {
            animals[i] = new Cat();
        }
    }

    // Test some functionality
    for (int i = 0; i < ARRAY_SIZE; i++) {
        std::cout << "\nAnimal " << i << " is a " << animals[i]->getType() << std::endl;
        animals[i]->makeSound();
    }

    // Clean up array
    for (int i = 0; i < ARRAY_SIZE; i++) {
        delete animals[i];
    }

    std::cout << "\n=== Testing Deep Copy ===" << std::endl;

    // Test deep copy of Dog
    std::cout << "\nTesting Dog deep copy:" << std::endl;
    Dog* originalDog = new Dog();
    originalDog->setIdea(0, "I love bones!");
    originalDog->setIdea(1, "I want to chase cats!");

    Dog* copyDog = new Dog(*originalDog);  // Use copy constructor

    // Modify original dog's ideas
    originalDog->setIdea(0, "I love sleeping!");

    // Compare ideas
    std::cout << "Original Dog's first idea: " << originalDog->getIdea(0) << std::endl;
    std::cout << "Copy Dog's first idea: " << copyDog->getIdea(0) << std::endl;
    std::cout << "Original Dog's second idea: " << originalDog->getIdea(1) << std::endl;
    std::cout << "Copy Dog's second idea: " << copyDog->getIdea(1) << std::endl;

    // Clean up dogs
    delete originalDog;
    delete copyDog;

    // Test deep copy of Cat
    std::cout << "\nTesting Cat deep copy:" << std::endl;
    Cat* originalCat = new Cat();
    originalCat->setIdea(0, "I love fish!");
    originalCat->setIdea(1, "I want to sleep!");

    Cat* copyCat = new Cat(*originalCat);  // Use copy constructor

    // Modify original cat's ideas
    originalCat->setIdea(0, "I love milk!");

    // Compare ideas
    std::cout << "Original Cat's first idea: " << originalCat->getIdea(0) << std::endl;
    std::cout << "Copy Cat's first idea: " << copyCat->getIdea(0) << std::endl;
    std::cout << "Original Cat's second idea: " << originalCat->getIdea(1) << std::endl;
    std::cout << "Copy Cat's second idea: " << copyCat->getIdea(1) << std::endl;

    // Clean up cats
    delete originalCat;
    delete copyCat;

    std::cout << "\n=== Testing Required Main ===" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j;
    delete i;

    return 0;
}
