#pragma once

#include "Account.h"

class User : Account
{
private:
    string firstName;
    string lastName;
    int id;
public:
    User(std::string firstName, std::string lastName, int id); //contains User info and variables
    User(const User& other);
    //constructors
};

