#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

// WrongCat class inheriting from WrongAnimal - demonstrates non-polymorphic behavior
class WrongCat : public WrongAnimal {
public:
    // Orthodox Canonical Form requirements
    WrongCat();
    WrongCat(const WrongCat& other);
    WrongCat& operator=(const WrongCat& other);
    ~WrongCat();

    // Non-virtual function - won't be called through base class pointer
    void makeSound() const;
};
