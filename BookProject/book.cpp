#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Structure to store contact information
struct Contact
{
    std::string name;
    std::string phone;
    std::string email;
};

// Function to add a new contact to the list
void addContact(std::vector<Contact>& contacts)
{
    Contact newContact;
    std::cout << "Enter name: ";
    std::cin >> newContact.name;
    std::cout << "Enter phone: ";
    std::cin >> newContact.phone;
    std::cout << "Enter email: ";
    std::cin >> newContact.email;
    contacts.push_back(newContact);
    std::cout << "Contact added." << std::endl;
}

// Function to display all contacts in the list
void displayContacts(const std::vector<Contact>& contacts)
{
    for (const auto& contact : contacts)
    {
        std::cout << "Name: " << contact.name << ", Phone: "
            << contact.phone << ", Email: " << contact.email << std::endl;
    }
}

// Function to search for a contact by name
void searchContact(const std::vector<Contact>& contacts)
{
    std::string searchTerm;
    std::cout << "Enter name to search: ";
    std::cin >> searchTerm;

    bool found = false;
    for (const auto& contact : contacts)
    {
        if (contact.name == searchTerm)
        {
            std::cout << "Name: " << contact.name << ", Phone: "
                << contact.phone << ", Email: " << contact.email << std::endl;
            found = true;
            break;
        }
    }

    if (!found)
    {
        std::cout << "Contact not found." << std::endl;
    }
}

// Function to delete a contact by name
void deleteContact(std::vector<Contact>& contacts)
{
    std::string nameToDelete;
    std::cout << "Enter name of contact to delete: ";
    std::cin >> nameToDelete;

    auto it = std::remove_if(contacts.begin(), contacts.end(), [&](const Contact& contact)
        { return contact.name == nameToDelete; });

    if (it != contacts.end())
    {
        contacts.erase(it, contacts.end());
        std::cout << "Contact deleted." << std::endl;
    }
    else
    {
        std::cout << "Contact not found." << std::endl;
    }
}

// Main function: provides menu and handles user choices
int main()
{
    std::vector<Contact> contacts;
    int choice;

    do
    {
        std::cout << "\n1. Add Contact" << std::endl;
        std::cout << "2. Display Contacts" << std::endl;
        std::cout << "3. Search Contact" << std::endl;
        std::cout << "4. Delete Contact" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            addContact(contacts);
            break;
        case 2:
            displayContacts(contacts);
            break;
        case 3:
            searchContact(contacts);
            break;
        case 4:
            deleteContact(contacts);
            break;
        case 5:
            break;
        default:
            std::cout << "Invalid choice." << std::endl;
        }
    } while (choice != 5);

    return 0;
}
