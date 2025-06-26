#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {
private:
    std::string name;

public:
    // Constructor
    Zombie(std::string name);
    // Destructor
    ~Zombie(void);

    // Member function to announce zombie
    void announce(void);
};

// Functions declarations
Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif
