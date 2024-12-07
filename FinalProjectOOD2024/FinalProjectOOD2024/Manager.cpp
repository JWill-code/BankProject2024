#include "Manager.h"
#include "User.h"

Manager::Manager(std::string firstName, std::string lastName, int id,
    std::string password) {
    // Set this account's data members to the provided information
    //object
    this->firstName = firstName;
    this->lastName = lastName;
    this->id = id;
    this->password = password; //initialize
}
Manager::Manager(const Manager& other) {
    // Copy data members of the other account to this new one
    //
    this->firstName = other.firstName;
    this->lastName = other.lastName;
    this->id = other.id;
    this->password = other.password;
}