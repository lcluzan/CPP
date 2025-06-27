#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

// Cat class inheriting from Animal
class Cat : public Animal {
public:
    // Orthodox Canonical Form requirements
    Cat();                      // Default constructor
    Cat(const Cat& other);      // Copy constructor
    Cat& operator=(const Cat& other);  // Copy assignment operator
    virtual ~Cat();             // Destructor

    // Override base class virtual function
    virtual void makeSound() const override;  // Cat specific sound
};
