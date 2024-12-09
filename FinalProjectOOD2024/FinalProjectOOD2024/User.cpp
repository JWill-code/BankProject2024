#include <iostream>

#include "User.h"
#include "Account.h"

User::User(int id, std::string userName, std::string password, std::string firstName, std::string lastName, double balance, int type) 
    : Account(id, userName, password, firstName, lastName, balance, type) 
{
    // Set this account's data members to the provided information
    //possible array.
    //userInfo[] = new string[5];
    //vector<string> v = { firstName, lastName, id, userName, password };
    //Use getFirstName instead of 
    //this->firstName = firstName;
}

User::User(const Account& other) : Account(other) 
{
    // Copy data members of the other account to this new one
    //Use getFirstName instead of 
    //this->firstName = other.firstName;
}

void User::printAccountSummary() 
{
    // Print account information
    std::cout << "Account Summary for " << getUsername() << " [ID = " << getID() << "]:\n"
        << "Name: " << getFirstName() << " " << getLastName() << "\n"
        << "Balance: $" << getBalance() << "\n" << "Account type: " << getAccountType() << std::endl;

    // List transaction history
    std::cout << "Transaction history from this session:" << std::endl;

    for (Transaction t : transactions)
    {
        std::cout << t.getTransactionText() << std::endl;
    }
}
