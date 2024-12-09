#pragma once

#include <string>

class Account
{
private:
    static int numAccounts;
    int type;
    int id;
    std::string userName;
    std::string password;
    std::string firstName;
    std::string lastName;
    double balance;

public:
    /* Constructors */
    Account(int id, std::string userName, std::string firstName, std::string lastName, std::string password, double balance, int type);
    Account(const Account &other);

    /* Account Validation */
    bool checkPassword(std::string inputted_password);

    /* Transaction Methods */
    bool withdraw(double amount);
    bool deposit(double amount);

    /* Getters and Setters */
    int getNumAccounts() const;
    int getID() const;
    std::string getAccountType();
    std::string getUsername();
    std::string getPassword();
    std::string getFirstName();
    std::string getLastName();
    void setAccountType();
    double getBalance();

    // Add/Subtract 1 from the total number of accounts
    void add();
    void remove();

    // Pure virtual function, overridden in User and Manager classes
    virtual void printAccountSummary() = 0;
};
