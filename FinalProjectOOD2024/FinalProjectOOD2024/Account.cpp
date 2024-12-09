#include "Account.h"
#include <iostream>
#include "User.h"
/* Constructors */
int Account::numAccounts = 0;

Account::Account(int id, std::string userName, std::string password, std::string firstName, std::string lastName, double balance, int type)
{
    if (type !=1 && type != 2)
    {
        std::cout<<"invalid account type, checking account created"<<std::endl;
        type =1;
    }

    this->id = id;
    this->userName = userName;
    this->firstName = firstName;
    this->lastName = lastName;
    this->password = password;
    this->balance = balance;
    this->type = type;
    // Set this account's data members to the provided information
}

Account::Account(const Account &other)
{
    // Copy data members of the other account to this new one
    this->id = other.id;
    this->userName = other.userName;
    this->firstName = other.firstName;
    this->lastName = other.lastName;
    this->password = other.password;
    this->balance = other.balance;
    this->type = other.type;
}

/* Account Validation */

bool Account::checkPassword(std::string inputted_password) 
{
    // Check that the inputted password matches the account's password
    if (this->password.compare(inputted_password) == 0) 
    {
        return true;
    }

    return false;
}

/* Transaction Methods */

bool Account::withdraw(double amount)
{
    if (amount > this->balance || amount < 0)
    {
        return false;
    }

    this->balance -= amount;
    return true;
}

bool Account::deposit(double amount)
{
    if (amount < 0)
    {
        return false;
    }

    this->balance += amount;
    return true;
}

/* Getters and Setters */

int Account::getNumAccounts() const
{
    return numAccounts;
}

int Account::getID() const
{
    return this->id;
}

std::string Account::getAccountType() const
{
    if (this->type == 1 )
    {

        return "checking";
    }

    return "savings";
}

int Account::getAccountTypeNum() 
{
    return this->type;
}

std::string Account::getUsername() const 
{
    return this->userName;
}

std::string Account::getPassword() const
{
    return this->password;
}

std::string Account::getFirstName() const
{
    return this->firstName;
}

std::string Account::getLastName() const
{
    return this->lastName;
}

double Account::getBalance() const
{
    return this->balance;
}

bool Account::setAccountType(int type)
{
    if (this->type == 1 || this->type == 2)
    {
        
        this->type=type;
        return true;
    }
    
    return false;
}


void Account::add() 
{
    this->numAccounts++;
}

void Account::remove() 
{
    this->numAccounts--;
}
