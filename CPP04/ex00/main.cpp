#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {
    std::cout << "=== Testing Animal, Dog, and Cat classes ===" << std::endl;

    // Test required by the subject
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << "\nTesting getType():" << std::endl;
    std::cout << "j->getType(): " << j->getType() << std::endl;
    std::cout << "i->getType(): " << i->getType() << std::endl;

    std::cout << "\nTesting makeSound():" << std::endl;
    std::cout << "i->makeSound(): ";
    i->makeSound();
    std::cout << "j->makeSound(): ";
    j->makeSound();
    std::cout << "meta->makeSound(): ";
    meta->makeSound();

    // Cleanup
    delete meta;
    delete j;
    delete i;

    std::cout << "\n=== Testing WrongAnimal and WrongCat classes ===" << std::endl;

    // Test wrong animal implementation
    const WrongAnimal* wrong_meta = new WrongAnimal();
    const WrongAnimal* wrong_cat = new WrongCat();

    std::cout << "\nTesting getType():" << std::endl;
    std::cout << "wrong_cat->getType(): " << wrong_cat->getType() << std::endl;

    std::cout << "\nTesting makeSound():" << std::endl;
    std::cout << "wrong_cat->makeSound(): ";
    wrong_cat->makeSound();  // This will call WrongAnimal's makeSound!
    std::cout << "wrong_meta->makeSound(): ";
    wrong_meta->makeSound();

    // Additional test with direct WrongCat object
    std::cout << "\nTesting direct WrongCat object:" << std::endl;
    WrongCat direct_wrong_cat;
    std::cout << "direct_wrong_cat.makeSound(): ";
    direct_wrong_cat.makeSound();  // This will call WrongCat's makeSound

    // Cleanup
    delete wrong_meta;
    delete wrong_cat;

    return 0;
}
