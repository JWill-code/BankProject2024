#include <iostream>

#include "BankLogic.h"

// Constructor of the main bank application
BankLogic::BankLogic() {

    isRunning = true;

    // Fix Visual Studio warning about uninitialized member variable
    currentUser = NULL;

    // Initialize the bank storage to get user and manager data
	bankStorage = new BankStorage(this);
    bankStorage->loadUsersFromFile();
    bankStorage->loadManagersFromFile();

    while (isRunning) {

        displayBankMenu();
    }
}

void BankLogic::displayBankMenu() 
{


}

void BankLogic::displayUserMenu() 
{


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