#pragma once

#include "BankStorage.h"
#include "Account.h"

class BankStorage;

class BankLogic
{
private:

	/* References to other classes */
	BankStorage *bankStorage;
	Account *currentUser;

	void displayBankMenu();
	void displayUserMenu();
	void displayManagerMenu();

public:

	/* Constructor */

	BankLogic();

	/* Getters and Setters */

	Account getCurrentUser();
	void setCurrentUser(Account u);
};
