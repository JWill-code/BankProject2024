#include <iostream>

#include "User.h"
#include "Account.h"

User::User(int id, std::string userName, std::string password, std::string firstName, std::string lastName, double balance) 
: Account(id, userName, password, firstName, lastName, balance) 
{
    // Set this account's data members to the provided information
    //possible array.
    //userInfo[] = new string[5];
    //vector<string> v = { firstName, lastName, id, userName, password };
}

User::User(const Account& other) : Account(other) 
{
    // Copy data members of the other account to this new one
}

void User::printAccountSummary() {

    std::cout << "Account Summary for " << getUsername() << " [ID = " << getID() << "]:\n"
        << "Name: " << getFirstName() << " " << getLastName() << "\n"
        << "Balance: $" << getBalance() << std::endl;
}