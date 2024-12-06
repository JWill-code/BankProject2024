#include "BankLogic.h"

// Constructor of the main bank application
BankLogic::BankLogic() {

	bankStorage = new BankStorage(this);
}

void BankLogic::displayBankMenu() {


}

void BankLogic::displayUserMenu() {


}

void BankLogic::displayManagerMenu() {


}

/* Getters and Setters */

Account BankLogic::getCurrentUser() {

	return *currentUser;
}

void BankLogic::setCurrentUser(User u) {

	// If the current user is not null, delete it
	if (currentUser != NULL) {

		delete currentUser;
	}

    currentUser = new User(u);
}

void BankLogic::setCurrentUser(Manager m) {

    // If the current user is not null, delete it
    if (currentUser != NULL) {

        delete currentUser;
    }

    currentUser = new Manager(m);
}