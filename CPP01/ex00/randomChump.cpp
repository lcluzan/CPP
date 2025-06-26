#include "Zombie.hpp"

// Creates a zombie on the stack and makes it announce itself
void randomChump(std::string name) {
    Zombie zombie(name);
    zombie.announce();
}
