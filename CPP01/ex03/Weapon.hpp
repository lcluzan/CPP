#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
private:
    std::string type;

public:
    // Constructor
    Weapon(std::string type);

    // Member functions
    const std::string& getType() const;  // Returns a const reference to type
    void setType(std::string newType);   // Sets a new type
};

#endif
