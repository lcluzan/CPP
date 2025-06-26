#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

PhoneBook::PhoneBook() : currentIndex(0), totalContacts(0) {}

void PhoneBook::addContact(const Contact &contact) {
    contacts[currentIndex] = contact;
    currentIndex = (currentIndex + 1) % MAX_CONTACTS;
    if (totalContacts < MAX_CONTACTS)
        totalContacts++;
}

std::string PhoneBook::truncateString(const std::string &str) const {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

bool PhoneBook::isValidIndex(const std::string &input) const {
    if (input.empty())
        return false;

    for (size_t i = 0; i < input.length(); i++) {
        if (!std::isdigit(input[i]))
            return false;
    }

    std::istringstream iss(input);
    int index;
    iss >> index;

    return index >= 0 && index < totalContacts;
}

void PhoneBook::displayContactDetails(int index) const {
    std::cout << "\nContact Details:" << std::endl;
    std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
    std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
    std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
}

void PhoneBook::searchContact() const {
    if (totalContacts == 0) {
        std::cout << "Phonebook is empty!" << std::endl;
        return;
    }

    // Display header
    std::cout << std::setw(10) << "Index" << "|";
    std::cout << std::setw(10) << "First Name" << "|";
    std::cout << std::setw(10) << "Last Name" << "|";
    std::cout << std::setw(10) << "Nickname" << std::endl;

    // Display contacts
    for (int i = 0; i < totalContacts; i++) {
        std::cout << std::setw(10) << i << "|";
        std::cout << std::setw(10) << truncateString(contacts[i].getFirstName()) << "|";
        std::cout << std::setw(10) << truncateString(contacts[i].getLastName()) << "|";
        std::cout << std::setw(10) << truncateString(contacts[i].getNickname()) << std::endl;
    }

    // Get user input for index
    std::string input;
    std::cout << "\nEnter index to display details: ";
    std::getline(std::cin, input);

    if (isValidIndex(input)) {
        std::istringstream iss(input);
        int index;
        iss >> index;
        displayContactDetails(index);
    } else {
        std::cout << "Invalid index!" << std::endl;
    }
}
