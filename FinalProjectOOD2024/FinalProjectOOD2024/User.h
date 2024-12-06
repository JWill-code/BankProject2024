#pragma once

#include "Account.h" //for create account

class User : public Account
{
private:
    string firstName;
    string lastName;
    string userName;
    string password;
    int id;
public:
    User(std::string firstName, std::string lastName, int id, std::string userName, std::string password); //contains User info and variables
    User(const User& other);
    //constructors
};

