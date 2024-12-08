#include <iostream>

#include "Manager.h"
#include "User.h"
#include "Account.h"

Manager::Manager(int id, std::string userName, std::string password, std::string firstName, std::string lastName, double balance)
    : Account(id, userName, password, firstName, lastName, balance) 
{
    // Set this account's data members to the provided information
    //object
    //when I am trying to debug this it says that the private member cannot be accessed by
    //account::firstName, etc. 
    //Use getFirstName instead.
    this->firstName = firstName;
    this->lastName = lastName;
    this->id = id;
    this->password = password; //initialize
}

Manager::Manager(const Account& other) : Account(other) 
{
    // Copy data members of the other account to this new one
    this->firstName = other.firstName;
    this->lastName = other.lastName;
    this->id = other.id;
    this->password = other.password; //initialize
}

void Manager::printAccountSummary() 
{

    std::cout << "Account Summary for " << getUsername() << " [ID = " << getID() << "] [Manager]:\n"
        << "Name: " << getFirstName() << " " << getLastName() << "\n"
        << "Balance: $" << getBalance() << std::endl;
}