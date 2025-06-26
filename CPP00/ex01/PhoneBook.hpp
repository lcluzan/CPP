#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <string>

class PhoneBook {
private:
    static const int MAX_CONTACTS = 8;
    Contact contacts[MAX_CONTACTS];
    int currentIndex;
    int totalContacts;

    // Helper functions
    std::string truncateString(const std::string &str) const;
    void displayContactDetails(int index) const;
    bool isValidIndex(const std::string &input) const;

public:
    PhoneBook();
    void addContact(const Contact &contact);
    void searchContact() const;
};

#endif
