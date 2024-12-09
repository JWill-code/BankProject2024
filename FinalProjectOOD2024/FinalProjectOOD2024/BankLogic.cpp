#include <iostream>

#include "BankLogic.h"

// Constructor of the main bank application
BankLogic::BankLogic() {

    // Fix Visual Studio warning about uninitialized member variable
    currentUser = NULL;

    // Initialize the bank storage to get user and manager data
	bankStorage = new BankStorage(this);
    bankStorage->loadUsersFromFile();
    bankStorage->loadManagersFromFile();


}

void BankLogic::displayBankMenu() 
{
    

    //copy stuff from main.cpp concept, use while loop added to control whether it displays
    //type 1 or 2 for account type; checking or savings
    int functNum;
    std::cout << "Type integer for associated function" << std::endl;
    std::cout << "1. User Login" << std::endl;
    std::cout << "2. Create Account" << std::endl;
    std::cout << "3. Manager Login" << std::endl;
    std::cout << "4. Exit " << std::endl;
    std::cin >> functNum;

}

void BankLogic::displayUserMenu() 
{

    //type 1 or 2 for account type; checking or savings
}

void BankLogic::displayManagerMenu() 
{

    
}

/* Getters and Setters */

Account* BankLogic::getCurrentUser() 
{

	return currentUser;
}

void BankLogic::setCurrentUser(User* u) 
{

	// If the current user is not null, delete it
	if (currentUser != NULL) 
    {

		delete currentUser;
	}

    currentUser = new User(*u);
}

void BankLogic::setCurrentUser(Manager* m)
{

    // If the current user is not null, delete it
    if (currentUser != NULL)
    {

        delete currentUser;
    }

    currentUser = new Manager(*m);
}