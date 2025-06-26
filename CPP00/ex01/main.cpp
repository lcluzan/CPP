#include "PhoneBook.hpp"
#include <iostream>
#include <string>

/*
** This program implements a simple phonebook that can store up to 8 contacts.
** It supports three commands: ADD, SEARCH, and EXIT.
*/

// Function to get non-empty input from user
std::string getInput(const std::string &prompt) {
    std::string input;
    do {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (std::cin.eof()) {
            std::cout << "\nExiting program..." << std::endl;
            exit(0);
        }
    } while (input.empty());
    return input;
}

int main() {
    PhoneBook phoneBook;
    std::string command;

    std::cout << "Welcome to My Awesome PhoneBook!" << std::endl;

    while (true) {
        command = getInput("\nEnter command (ADD, SEARCH, EXIT): ");

        if (command == "EXIT") {
            std::cout << "Goodbye!" << std::endl;
            break;
        }
        else if (command == "ADD") {
            Contact newContact;
            newContact.setFirstName(getInput("Enter first name: "));
            newContact.setLastName(getInput("Enter last name: "));
            newContact.setNickname(getInput("Enter nickname: "));
            newContact.setPhoneNumber(getInput("Enter phone number: "));
            newContact.setDarkestSecret(getInput("Enter darkest secret: "));
            phoneBook.addContact(newContact);
            std::cout << "Contact added successfully!" << std::endl;
        }
        else if (command == "SEARCH") {
            phoneBook.searchContact();
        }
        else {
            std::cout << "Invalid command!" << std::endl;
        }
    }
    return 0;
}
