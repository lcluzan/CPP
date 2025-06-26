#include "Zombie.hpp"

int main() {
    int N = 5;  // Number of zombies to create

    // Create a horde of zombies
    Zombie* horde = zombieHorde(N, "Walker");

    // Make each zombie announce itself
    for (int i = 0; i < N; i++) {
        std::cout << "Zombie " << i + 1 << ": ";
        horde[i].announce();
    }

    // Clean up the horde
    delete[] horde;

    return 0;
}
