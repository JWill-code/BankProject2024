#include <iostream>
#include <iomanip>

#include "Manager.h"
#include "User.h"
#include "Account.h"

Manager::Manager(int id, std::string userName, std::string password, std::string firstName, std::string lastName, double balance, int type)
    : Account(id, userName, password, firstName, lastName, balance, type) 
{
    // Set this account's data members to the provided information
}

Manager::Manager(const Account& other) : Account(other) 
{
    // Copy data members of the other account to this new one
}

void Manager::printAccountSummary() const
{
    // Set console output to round to two decimal places
    std::cout << std::fixed << std::setprecision(2);

    // Print account information
    std::cout << "Account Summary for " << getUsername() << " [ID = " << getID() << "] [Manager]:\n"
        << "Name: " << getFirstName() << " " << getLastName() << "\n"
        << "Balance: $" << getBalance() << "\n" << "Account type: " << getAccountType() <<std::endl;

    // List transaction history
    std::cout << "Transaction history from this session:" << std::endl;

    if (transactions.empty()) {

        std::cout << "[No transactions completed]" << std::endl;
    }
    
    for (Transaction t : transactions)
    {
        std::cout << t.getTransactionText() << std::endl;
    }
}
