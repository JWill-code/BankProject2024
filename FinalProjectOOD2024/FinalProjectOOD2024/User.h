#pragma once

#include "Account.h" //for create account

class User : public Account
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
    User(int id, std::string userName, std::string password, std::string firstName, std::string lastName, double balance,int type); //contains User info and variables
    User(const Account& other);

    // Override for pure virtual function
    void printAccountSummary() override;
    
};

