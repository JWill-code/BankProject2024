#pragma once

#include "BankStorage.h"
#include "Account.h"
#include "User.h"
#include "Manager.h"

class BankStorage;

class BankLogic
{
private:

    bool isRunning;

	/* References to other classes */
	BankStorage* bankStorage;
	Account* currentUser;

	void displayBankMenu();
	void displayUserMenu();
	void displayManagerMenu();

public:

	/* Constructor */

	BankLogic();

	/* Getters and Setters */

	Account* getCurrentUser() const;
	void setCurrentUser(User* u);
    void setCurrentUser(Manager* m);
};

