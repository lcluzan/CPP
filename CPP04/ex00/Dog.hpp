#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

// Dog class inheriting from Animal
class Dog : public Animal {
public:
    // Orthodox Canonical Form requirements
    Dog();                      // Default constructor
    Dog(const Dog& other);      // Copy constructor
    Dog& operator=(const Dog& other);  // Copy assignment operator
    virtual ~Dog();             // Destructor

    // Override base class virtual function
    virtual void makeSound() const override;  // Dog specific sound
};
