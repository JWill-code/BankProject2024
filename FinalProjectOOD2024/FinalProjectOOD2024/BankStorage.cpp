#include <iostream>
#include <sstream>

#include "BankStorage.h"
#include "User.h"
#include "Manager.h"

// Static variable declaration
std::string BankStorage::folderName;
std::string BankStorage::usersFileName;
std::string BankStorage::managersFileName;

// Constructor of the BankStorage class
// Handles file I/O for user and manager accounts
BankStorage::BankStorage(BankLogic *bankLogic) 
{

    folderName = "data/";
    usersFileName = "users.txt";
    managersFileName = "managers.txt";

	this->bankLogic = bankLogic;
}

/* User Data Functions */

bool BankStorage::loginUser(std::string uName, std::string pswd) const 
{

    for (User existing : userList) 
    {

        if (uName.compare(existing.getUsername()) == 0 && existing.checkPassword(pswd)) 
        {

            bankLogic->setCurrentUser(&existing);

            return true;
        }
    }

    return false;
}

bool BankStorage::addUser(User u) 
{

    // Check that the user is not already in the user list
	for (User existing : userList) 
    {

        // Compare existing usernames
        if (u.getUsername().compare(existing.getUsername()) == 0) 
        {

            return false;
        }
    }

    // Add 1 to the static accountNum variable
    u.add();

    userList.push_back(u);
    
    return true;
}

bool BankStorage::removeUser(int id) 
{

    // Iterator loops over the list and can be dereferenced to get the user object
    for (auto i = userList.begin(); i < userList.end(); i++) 
    {

        // If the user is found in the list, remove it
        if ((*i).getID() == id) 
        {

            // Subtract 1 from the static accountNum variable
            (*i).remove();

            // Remove the user from the list
            userList.erase(i);
            return true;
        }
    }

    return false;
}

User* BankStorage::getUser(int id) 
{

    // Iterator loops over the list and can be dereferenced to get the user object
    for (auto i = userList.begin(); i < userList.end(); i++) 
    {

        // If the user is found in the list, return it
        if ((*i).getID() == id) 
        {

            return &(*i);
        }
    }

    // Return null if no user could be found with the given ID
    return NULL;
}

bool BankStorage::saveUser(User u) 
{

    // Check that the user already exists in the system, otherwise the user cannot be saved
    for (int i = 0; i < userList.size(); i++) 
    {

        if (userList[i].getID() == u.getID()) 
        {

            userList[i] = u;
            return true;
        }
    }

    return false;
}

bool BankStorage::saveUsersToFile(std::string fileName) 
{

    std::ofstream outputStream(fileName);

    std::string text;

    if (outputStream.is_open()) 
    {
        
        // Write each user's data to the text file
        for (User u : userList) 
        {

            std::string userDataString = std::to_string(u.getID()) + "\t" + u.getUsername() +
                "\t" + u.getPassword() + "\t" + u.getFirstName() + "\t" + u.getLastName() +
                "\t" + std::to_string(u.getBalance()) + "\t" + std::to_string(u.getAccountTypeNum()) + "\n";
            outputStream << userDataString;
        }

        outputStream.close();

        return true;
    }

    return false;
}

bool BankStorage::loadUsersFromFile(std::string fileName) 
{

    std::ifstream inputStream(fileName);

    std::string text;

    if (inputStream.is_open()) 
    {

        // Process a user from each line of the text file
        while (std::getline(inputStream, text)) 
        {

            // Vetor to hold data of the user being read from the file
            std::vector<std::string> userData;

            // String stream holds the current line to be read and tokenized
            std::stringstream strStream(text);

            // String capable of holding individual tokens 
            std::string token;

            // Loop over the stringstream to get each tab-separated value
            while (std::getline(strStream, token, '\t')) 
            {

                // Add the current token to the user data vector
                userData.push_back(token);
            }

            // Validate each token
            if (userData.size() == 7) 
            {

                try 
                {

                    int id = std::stoi(userData[0]);
                    std::string userName = userData[1];
                    std::string password = userData[2];
                    std::string firstName = userData[3];
                    std::string lastName = userData[4];
                    double balance = std::stod(userData[5]);
                    int type = std::stoi(userData[6]);

                    // Attempt to create a new user given the information and add it to the user list
                    User u(id, userName, password, firstName, lastName, balance, type);
                    addUser(u);

                    u.printAccountSummary();
                }
                catch (std::exception ex) 
                {

                }
            }
            else 
            {

                
            }
        }

        // Close the input stream
        inputStream.close();

        return true;
    }

    return false;
}


/* Manager Data Functions */

bool BankStorage::loginManager(std::string uName, std::string pswd) const 
{

    for (Manager existing : managerList) 
    {

        if (uName.compare(existing.getUsername()) == 0 && existing.checkPassword(pswd)) 
        {

            bankLogic->setCurrentUser(&existing);

            return true;
        }
    }

    return false;
}

bool BankStorage::saveManager(Manager m) 
{

    for (int i = 0; i < managerList.size(); i++) 
    {

        if (managerList[i].getID() == m.getID()) 
        {

            managerList[i] = m;
            return true;
        }
    }

    return false;
}

bool BankStorage::saveManagersToFile(std::string fileName) 
{

    std::ofstream outputStream(fileName);

    std::string text;

    if (outputStream.is_open()) 
    {

        // Write each user's data to the text file
        for (Manager m : managerList) 
        {

            std::string managerDataString = std::to_string(m.getID()) + "\t" + m.getUsername() +
                "\t" + m.getPassword() + "\t" + m.getFirstName() + "\t" + m.getLastName() +
                "\t" + std::to_string(m.getBalance()) + "\t" + std::to_string(m.getAccountTypeNum()) + "\n";
            outputStream << managerDataString;
        }

        outputStream.close();

        return true;
    }

    return false;
}

bool BankStorage::loadManagersFromFile(std::string fileName) 
{

    std::ifstream inputStream(fileName);

    std::string text;

    if (inputStream.is_open()) 
    {

        // Process a manager from each line of the text file
        while (std::getline(inputStream, text)) 
        {
            // Vetor to hold data of the user being read from the file
            std::vector<std::string> managerData;

            // String stream holds the current line to be read and tokenized
            std::stringstream strStream(text);

            // String capable of holding individual tokens 
            std::string token;

            // Loop over the stringstream to get each tab-separated value
            while (std::getline(strStream, token, '\t')) 
            {

                // Add the current token to the manager data vector
                managerData.push_back(token);
            }

            // Validate each token
            if (managerData.size() == 7) 
            {

                try 
                {

                    int id = std::stoi(managerData[0]);
                    std::string userName = managerData[1];
                    std::string password = managerData[2];
                    std::string firstName = managerData[3];
                    std::string lastName = managerData[4];
                    double balance = std::stod(managerData[5]);
                    int type = std::stoi(managerData[6]);

                    // Attempt to create a new manager given the information and add it to the manager list
                    Manager m(id, userName, password, firstName, lastName, balance, type);
                    managerList.push_back(m);

                    m.printAccountSummary();
                }
                catch (std::exception ex) 
                {

                    
                }
            }
            else 
            {

                
            }
        }

        // Close the input stream
        inputStream.close();

        return true;
    }

    return false;
}

/* Static Data for File Storage Information */

std::string BankStorage::getUserFilePath() 
{

    return folderName + usersFileName;
}

std::string BankStorage::getManagerFilePath() 
{

    return folderName + managersFileName;
}