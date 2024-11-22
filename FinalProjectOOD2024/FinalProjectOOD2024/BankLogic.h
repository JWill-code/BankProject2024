#pragma once

#include "Account.h"

class BankLogic
{
private:
	Account currentuser;

public:

	//* Getters and Setters *//
	Account getCurrentUser();
	void setCurrentUser(Account u);
};

