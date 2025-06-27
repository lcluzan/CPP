#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>
#include <iostream>

// WrongAnimal class - demonstrates what happens without virtual functions
class WrongAnimal {
protected:
    std::string type;

public:
    // Orthodox Canonical Form requirements
    WrongAnimal();
    WrongAnimal(const WrongAnimal& other);
    WrongAnimal& operator=(const WrongAnimal& other);
    ~WrongAnimal();  // Note: No virtual destructor

    // Member functions
    std::string getType() const;
    void makeSound() const;  // Note: Not virtual - will not be polymorphic
};
