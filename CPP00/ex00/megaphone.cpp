#include <iostream>
#include <cctype>
#include <string>

/*
** This program takes command line arguments and converts them to uppercase.
** If no arguments are provided, it outputs a default message.
*/

int main(int argc, char **argv)
{
    // If no arguments provided, output default message
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }

    // Process each argument starting from index 1 (argv[0] is program name)
    for (int i = 1; i < argc; i++)
    {
        std::string str = argv[i];
        // Convert each character to uppercase
        for (size_t j = 0; j < str.length(); j++)
        {
            std::cout << (char)std::toupper(str[j]);
        }
    }
    std::cout << std::endl;
    return 0;
}
