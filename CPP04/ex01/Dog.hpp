#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
private:
    Brain* brain;  // Each Dog has its own Brain

public:
    // Orthodox Canonical Form requirements
    Dog();                      // Default constructor
    Dog(const Dog& other);      // Copy constructor - must perform deep copy
    Dog& operator=(const Dog& other);  // Copy assignment operator - must perform deep copy
    virtual ~Dog();             // Destructor - must delete brain

    // Override base class virtual function
    virtual void makeSound() const override;

    // Brain related functions
    void setIdea(int index, const std::string& idea);
    std::string getIdea(int index) const;
};
