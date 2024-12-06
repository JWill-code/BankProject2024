#include "Account.h"
#include "User.h"
/* Constructors */
int Account::numAccounts=0;

Account::Account(int id, std::string userName, std::string firstName, std::string lastName, std::string password) {
numAccounts++;
this->id = id;
this->userName = userName;
this->firstName = firstName;
this->lastName = lastName;
this->password = password;
this->balance=0;
	// Set this account's data members to the provided information
}

Account::Account(const Account& other) {
this->id = other.id;
this->userName = other.userName;
this->firstName = other.firstName;
this->lastName = other.lastName;
this->password = other.password;
	// Copy data members of the other account to this new one
}
int Account::getNumAccounts()const{
return numAccounts;
}
int Account::getID()const{
return this->id;
}
bool Account::withdraw(double amount){
if(amount>this->balance||amount<0){
return false;
    }
balance-=amount;
return true;

}
bool Account::deposit(double amount){
if(amount<0){
return false;
    }
balance+=deposit;
return true;
}
