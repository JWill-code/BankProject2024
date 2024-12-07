#pragma once

#include "Account.h"

class Manager : public Account
{
private:
    string firstName;
    string lastName;
    string password;
    
    int id;

public:
    Manager(std::string firstName, std::string lastName, int id, std::string password);
    Manager(const Manager& other);
};

