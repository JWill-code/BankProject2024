#pragma once

#include "Account.h"

class Manager : public Account
{
private:
    // Data embers inherited from Account class
    // string firstName;
    // string lastName;
    // string userName;
    // string password;
    // int id;

public:
    /* Constructors */
    Manager(int id, std::string userName, std::string password, std::string firstName, std::string lastName);
    Manager(const Manager& other);

    // Override for pure virtual function
    void printAccountSummary() override;
};

