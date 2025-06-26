#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {
private:
    std::string name;

public:
    // Constructors
    Zombie(void);                    // Default constructor
    Zombie(std::string name);        // Named constructor
    // Destructor
    ~Zombie(void);

    // Member functions
    void announce(void);
    void setName(std::string name);  // Setter for name
};

// Function declarations
Zombie* zombieHorde(int N, std::string name);

#endif
