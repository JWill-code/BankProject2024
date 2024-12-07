#include <iostream>

#include "User.h"
#include "Account.h"

User::User(int id, std::string userName, std::string password, std::string firstName, std::string lastName) 
: Account(id, userName, password, firstName, lastName) 
{
    // Set this account's data members to the provided information

}

User::User(const User& other) : Account(other) 
{
    // Copy data members of the other account to this new one
}

void User::printAccountSummary() {

    std::cout << "User data: ";
}