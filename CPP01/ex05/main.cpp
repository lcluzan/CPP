#include "Harl.hpp"

int main() {
    Harl harl;

    // Test all complaint levels
    harl.complain("DEBUG");
    std::cout << std::endl;

    harl.complain("INFO");
    std::cout << std::endl;

    harl.complain("WARNING");
    std::cout << std::endl;

    harl.complain("ERROR");
    std::cout << std::endl;

    // Test invalid level
    harl.complain("INVALID");

    return 0;
}
