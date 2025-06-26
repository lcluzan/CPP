#include "Harl.hpp"
#include <iostream>

// Initialize static member arrays
const std::string Harl::levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
const Harl::ComplaintFunction Harl::functions[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

// Constructor
Harl::Harl(void) {
}

// Destructor
Harl::~Harl(void) {
}

// Debug level complaint
void Harl::debug(void) {
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl;
    std::cout << "I really do!" << std::endl;
}

// Info level complaint
void Harl::info(void) {
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
    std::cout << "You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

// Warning level complaint
void Harl::warning(void) {
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
    std::cout << "I've been coming for years whereas you started working here since last month." << std::endl;
}

// Error level complaint
void Harl::error(void) {
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

// Public interface to complain at a specific level
void Harl::complain(std::string level) {
    // Look for the matching level and call corresponding function
    for (int i = 0; i < 4; i++) {
        if (level == levels[i]) {
            (this->*functions[i])();
            return;
        }
    }
    // If level not found
    std::cout << "[ Invalid complaint level ]" << std::endl;
}
