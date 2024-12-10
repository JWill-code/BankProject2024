#pragma once

#include <string>
#include <fstream>
#include <vector>

#include "BankLogic.h"
#include "User.h"
#include "Manager.h"

// Forward-declaration allows BankLogic to be referenced despite not yet being initialized
class BankLogic;

class BankStorage
{
private:

    /* Static file path information */
    static std::string folderName;
    static std::string usersFileName;
    static std::string managersFileName;

	/* References to other classes */

	BankLogic *bankLogic;

    // List of users loaded from users.txt
    std::vector<User> userList;
    std::vector<Manager> managerList;

public:

    /* Static Data for File Storage Information */

    static std::string getUserFilePath();
    static std::string getManagerFilePath();

	/* Constructor */

	BankStorage(BankLogic *bankLogic);

	/* User Data Functions */

	bool loginUser(std::string uName, std::string pswd) const;
	bool addUser(User u);
	bool removeUser(int id);
	User* getUser(int id);
    bool saveUser(User u);

    bool saveUsersToFile(std::string fileName = getUserFilePath());
    bool loadUsersFromFile(std::string fileName = getUserFilePath());

    void printUserData() const;

	/* Manager Data Functions */

	bool loginManager(std::string uName, std::string pswd) const;
    bool saveManager(Manager m);

	bool saveManagersToFile(std::string fileName = getManagerFilePath());
	bool loadManagersFromFile(std::string fileName = getManagerFilePath());
};

