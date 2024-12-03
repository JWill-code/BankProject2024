#pragma once

#include "Account.h"

class BankLogic
{
private:
	Account currentUser;

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

