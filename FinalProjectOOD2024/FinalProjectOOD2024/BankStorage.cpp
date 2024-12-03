#include "BankStorage.h"
#include "User.h"
#include "Manager.h"
#include <iostream>

// Constructor of the BankStorage class
// Handles file I/O for user and manager accounts
BankStorage::BankStorage(BankLogic *bankLogic) {

	this->bankLogic = bankLogic;
}

/* User Data Functions */

User BankStorage::loginUser(std::string uName, std::string pswd) const {


}

bool BankStorage::createUser(User u) {

	std::cout << "User created!";
	return false;
}

bool BankStorage::deleteUser(int id) {


}

bool BankStorage::saveUser(User u) {


}

User BankStorage::loadUser(int id) {


}

/* Manager Data Functions */

Manager BankStorage::loginManager(std::string uName, std::string pswd) const {


}

bool BankStorage::saveManager(Manager m) {


}

Manager BankStorage::loadManager(int id) {


}