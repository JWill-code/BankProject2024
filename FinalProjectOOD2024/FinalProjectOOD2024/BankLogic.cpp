#include "BankLogic.h"

// Constructor of the main bank application
BankLogic::BankLogic() {

	bankStorage = new BankStorage(this);
    bankStorage->loadUsersFromFile();
}

void BankLogic::displayBankMenu() {


}

void BankLogic::displayUserMenu() {


}

void BankLogic::displayManagerMenu() {


}

/* Getters and Setters */

Account* BankLogic::getCurrentUser() {

	return currentUser;
}

void BankLogic::setCurrentUser(Account* a) {

	// If the current user is not null, delete it
	if (currentUser != NULL) {

		delete currentUser;
	}

    if (typeid(a) == typeid(User)) {

        currentUser = new User(*a);
    }
    else {

        currentUser = new Manager(*a);
    }
}