#include "Transaction.h"

// Static variables
std::string Transaction::depositText = "Deposit: +$";
std::string Transaction::withdrawalText = "Withdrawal: -$";
std::string Transaction::unknownTypeText = "Unknown Transaction";

/* Constructor */

Transaction::Transaction(int type, double amount) 
{
    if (type == 1 || type == 2) 
    {

        this->transactionType = type;
    }
    else 
    {

        // Default to deposit type if an invalid type is provided
        this->transactionType = -1;
    }
    
    this->amount = amount;
}

int Transaction::getTransactionType() const
{
    return this->transactionType;
}

std::string Transaction::getTransactionText() const
{   
    // Return different text depending on the type of transaction
    switch (this->transactionType)
    {
    case 1:
        // Deposit
        return Transaction::depositText + std::to_string(this->amount);

    case 2:
        // Withdrawal
        return Transaction::withdrawalText + std::to_string(this->amount);

    }

    return Transaction::unknownTypeText;
}