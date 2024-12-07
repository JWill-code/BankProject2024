#include <iostream>

#include "Manager.h"
#include "User.h"

Manager::Manager(int id, std::string userName, std::string password, std::string firstName, std::string lastName, int balance)
    : Account(id, userName, password, firstName, lastName, balance) 
{
    // Set this account's data members to the provided information
    //object
}

Manager::Manager(const Manager& other) : Account(other) 
{
    // Copy data members of the other account to this new one
}

void Manager::printAccountSummary() {

    std::cout << "Manager data: ";
}