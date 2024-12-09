#pragma once

#include <string>

class Transaction
{
private:
    // Text to display for deposits and withdrawals
    static std::string depositText;
    static std::string withdrawalText;
    static std::string unknownTypeText;

    // The type of transaction and amount of money involved
    int transactionType;
    int amount;

public:

    /* Constructor */

    Transaction(int type, int amount);

    /* Getters and Setters */
    int getTransactionType();
    std::string getTransactionText();
};

