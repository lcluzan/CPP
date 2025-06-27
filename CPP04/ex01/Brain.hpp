#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain {
private:
    std::string ideas[100];  // Array of 100 ideas

public:
    // Orthodox Canonical Form requirements
    Brain();                         // Default constructor
    Brain(const Brain& other);       // Copy constructor
    Brain& operator=(const Brain& other);  // Copy assignment operator
    ~Brain();                        // Destructor

    // Member functions
    void setIdea(int index, const std::string& idea);
    std::string getIdea(int index) const;
};
