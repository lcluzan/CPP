#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

int main() {
    // Required test from the subject
    std::cout << "=== Required Test ===" << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");
    AMateria* tmp;

    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);

    // Additional tests
    std::cout << "\n=== Additional Tests ===" << std::endl;

    // Test inventory limits
    std::cout << "\nTesting inventory limits:" << std::endl;
    for (int i = 0; i < 3; i++) {
        tmp = src->createMateria("ice");
        me->equip(tmp);
    }
    // This one should fail silently (inventory full)
    tmp = src->createMateria("ice");
    me->equip(tmp);
    delete tmp;  // Clean up the materia that couldn't be equipped

    // Test unequip and reequip
    std::cout << "\nTesting unequip and reequip:" << std::endl;
    me->unequip(1);  // Unequip the cure
    tmp = src->createMateria("ice");
    me->equip(tmp);  // Should equip in slot 1

    // Test deep copy of Character
    std::cout << "\nTesting Character deep copy:" << std::endl;
    Character* original = new Character("original");
    tmp = src->createMateria("ice");
    original->equip(tmp);

    Character* clone = new Character(*original);
    original->use(0, *bob);
    clone->use(0, *bob);

    // Clean up
    delete bob;
    delete me;
    delete src;
    delete original;
    delete clone;

    return 0;
}
