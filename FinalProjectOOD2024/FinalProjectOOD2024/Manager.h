#pragma once

#include "Account.h"

class Manager : Account
{
private:
    string firstName;
    string lastName;
    int id;

public:
    Manager(std::string firstName, std::string lastName, int id);
    Manager(const Manager& other);
};

