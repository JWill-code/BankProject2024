#include <iostream>

#include "Account.h"
#include "User.h"

// Static variable
int Account::numAccounts = 0;

/* Constructors */

Account::Account(int id, std::string userName, std::string password, std::string firstName, std::string lastName, double balance, int type)
{
    if (type != 1 && type != 2)
    {
        std::cout << "Invalid account type -- Checking account created." << std::endl;
        type = 1;
    }

    // Set this account's data members to the provided information
    this->id = id;
    this->userName = userName;
    this->firstName = firstName;
    this->lastName = lastName;
    this->password = password;
    this->balance = balance;
    this->type = type;
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

    // Copy over transaction information of this user
    for (Transaction t : other.transactions) {

        this->transactions.push_back(t);
    }
}

/* Account Validation */

bool Account::checkPassword(std::string inputted_password) const
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
    if (amount > this->balance || amount <= 0)
    {
        return false;
    }

    this->balance -= amount;

    // Add transaction record (withdrawal)
    this->transactions.push_back(Transaction(2, amount));

    std::cout << "Withdrew $" << amount << std::endl;

    return true;
}

bool Account::deposit(double amount)
{
    if (amount <= 0)
    {
        return false;
    }

    this->balance += amount;

    // Add transaction record (deposit)
    this->transactions.push_back(Transaction(1, amount));

    std::cout << "Deposited $" << amount << std::endl;

    return true;
}

/* Getters and Setters */

int Account::getNumAccounts()
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

        return "Checking";
    }

    return "Savings";
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
