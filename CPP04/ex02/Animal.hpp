#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

// Abstract base class Animal - Cannot be instantiated
class Animal {
protected:
    std::string type;

public:
    // Orthodox Canonical Form requirements
    Animal();                         // Default constructor
    Animal(const Animal& other);      // Copy constructor
    Animal& operator=(const Animal& other);  // Copy assignment operator
    virtual ~Animal();                // Virtual destructor for proper cleanup

    // Member functions
    std::string getType() const;      // Getter for type

    // Pure virtual function - makes the class abstract
    virtual void makeSound() const = 0;    // Pure virtual function
};
