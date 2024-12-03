#pragma once

#include <string>

#include "BankLogic.h"
#include "User.h"
#include "Manager.h"

// Forward-declaration allows BankLogic to be referenced despite not yet being initialized
class BankLogic;

class BankStorage
{
private:

	/* References to other classes */

	BankLogic *bankLogic;

public:

	/* Constructor */

	BankStorage(BankLogic *bankLogic);

	/* User Data Functions */

	User loginUser(std::string uName, std::string pswd) const;
	bool createUser(User u);
	bool deleteUser(int id);
	bool saveUser(User u);
	User loadUser(int id);

	/* Manager Data Functions */

	Manager loginManager(std::string uName, std::string pswd) const;
	bool saveManager(Manager m);
	Manager loadManager(int id);
};

