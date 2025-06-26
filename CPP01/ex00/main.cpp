#include "Zombie.hpp"

int main() {
    // Create a zombie on the heap
    Zombie* heapZombie = newZombie("Heap Walker");

    // Make the heap zombie announce
    heapZombie->announce();

    // Create a zombie on the stack through randomChump
    randomChump("Stack Crawler");

    // Clean up the heap zombie
    delete heapZombie;

    return 0;
}
