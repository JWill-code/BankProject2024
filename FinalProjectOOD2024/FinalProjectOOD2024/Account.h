#pragma once

#include <string>

class Account
{
private:
static int numAccounts;
int id;
double balance;
std::string userName;
std::string firstName;
std::string lastName;
std::string password;


public:

int getNumAccounts()const;
int getID()const;
bool withdraw(double amount);
bool deposit(double amount);
virtual void printAccountSummary()=0;
	/* Constructors */
	
	Account(int id, std::string userName, std::string firstName, std::string lastName, std::string password);
	Account(const Account &other);
};
