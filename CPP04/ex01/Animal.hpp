#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

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
    virtual void makeSound() const;    // Virtual function for polymorphic behavior
};
