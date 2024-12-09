#pragma once

#include "Account.h"

class Manager : public Account
{
private:
    // Data embers inherited from Account class
    // int id
    // string userName;
    // string password;
    // string firstName;
    // string lastName;
    // int balance;

public:
    /* Constructors */
    Manager(int id, std::string userName, std::string password, std::string firstName, std::string lastName, double balance,int type);
    Manager(const Account& other);

    // Override for pure virtual function
    void printAccountSummary() override;
};

