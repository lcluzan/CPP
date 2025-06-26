#include "Zombie.hpp"

// Creates N zombies with the given name and returns a pointer to the first zombie
Zombie* zombieHorde(int N, std::string name) {
    if (N <= 0)
        return NULL;

    // Allocate array of N zombies
    Zombie* horde = new Zombie[N];

    // Set names for all zombies
    for (int i = 0; i < N; i++) {
        horde[i].setName(name);
    }

    return horde;
}
