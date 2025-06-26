#ifndef HARL_HPP
#define HARL_HPP

#include <string>

class Harl {
private:
    // Private member functions for different complaint levels
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);

    // Function pointer type definition
    typedef void (Harl::*ComplaintFunction)(void);

    // Array of complaint levels and corresponding member functions
    static const std::string levels[4];
    static const ComplaintFunction functions[4];

    // Helper function to get level index
    int getLevelIndex(std::string level) const;

public:
    // Constructor and Destructor
    Harl(void);
    ~Harl(void);

    // Public member function to complain with filter
    void complain(std::string level);
};

#endif
