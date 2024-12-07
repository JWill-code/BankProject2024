#pragma once

#include "Account.h" //for create account

class User : public Account
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
    User(int id, std::string userName, std::string password, std::string firstName, std::string lastName); //contains User info and variables
    User(const User& other);

    // Override for pure virtual function
    void printAccountSummary() override;
    
};

