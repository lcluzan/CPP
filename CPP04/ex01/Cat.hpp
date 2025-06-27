#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
private:
    Brain* brain;  // Each Cat has its own Brain

public:
    // Orthodox Canonical Form requirements
    Cat();                      // Default constructor
    Cat(const Cat& other);      // Copy constructor - must perform deep copy
    Cat& operator=(const Cat& other);  // Copy assignment operator - must perform deep copy
    virtual ~Cat();             // Destructor - must delete brain

    // Override base class virtual function
    virtual void makeSound() const override;

    // Brain related functions
    void setIdea(int index, const std::string& idea);
    std::string getIdea(int index) const;
};
