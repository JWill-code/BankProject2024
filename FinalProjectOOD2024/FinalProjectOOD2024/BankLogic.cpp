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

void BankLogic::setCurrentUser(Account u) {

	// If the current user is not null, delete it
	if (currentUser) {

		delete currentUser;
	}

	currentUser = new Account(u);
}