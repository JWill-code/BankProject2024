#pragma once

#include <string>

class Account
{
private:

public:

	/* Constructors */
	
	Account(int id, std::string userName, std::string firstName, std::string lastName, std::string password);
	Account(const Account &other);
};