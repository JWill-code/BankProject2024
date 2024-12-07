#include "BankStorage.h"
#include "User.h"
#include "Manager.h"
#include <iostream>
#include <cstring>

// Constructor of the BankStorage class
// Handles file I/O for user and manager accounts
BankStorage::BankStorage(BankLogic *bankLogic) {

    folderName = "data/";
    usersFileName = "users.txt";
    managersFileName = "managers.txt";

	this->bankLogic = bankLogic;
}

/* User Data Functions */

User BankStorage::loginUser(std::string uName, std::string pswd) const {

    for (User existing : userList) {

        if (uName.compare(existing.getUsername()) == 0 && existing.checkPassword(pswd)) {

            bankLogic->setCurrentUser(existing);
        }
    }
}

bool BankStorage::addUser(User u) {

    // Check that the user is not already in the user list
	for (User existing : userList) {

        // Compare existing usernames
        if (u.getUsername().compare(existing.getUsername()) == 0) {

            return false;
        }
    }

    // Add 1 to the static accountNum variable
    u.add();

    userList.push_back(u);
    
    return true;
}

bool BankStorage::removeUser(int id) {

    // Iterator loops over the list and can be dereferenced to get the user object
    for (auto i = userList.begin(); i < userList.end(); i++) {

        // If the user is found in the list, remove it
        if ((*i).getID() == id) {

            // Subtract 1 from the static accountNum variable
            (*i).remove();

            // Remove the user from the list
            userList.erase(i);
            return true;
        }
    }

    return false;
}

User BankStorage::getUser(int id) {

    // Iterator loops over the list and can be dereferenced to get the user object
    for (auto i = userList.begin(); i < userList.end(); i++) {

        // If the user is found in the list, return it
        if ((*i).getID() == id) {

            return *i;
        }
    }

    // TODO: handle case where user doesn't exist
}

bool BankStorage::saveUser(User u) {

    // Check that the user already exists in the system, otherwise the user cannot be saved
    for (int i = 0; i < userList.size(); i++) {

        if (userList[i].getID() == u.getID()) {

            userList[i] = u;
            return true;
        }
    }

    return false;
}

bool BankStorage::saveUsersToFile(std::string fileName = getUserFilePath()) {

    std::ofstream outputStream(fileName);

    std::string text;

    if (outputStream.is_open()) {
        
        // Write each user's data to the text file
        for (User u : userList) {

            std::string userDataString = std::to_string(u.getID()) + "\t" + u.getUsername() +
                "\t" + u.getPassword() + "\t" + u.getFirstName() + "\t" + u.getLastName();
            outputStream << userDataString;
        }

        outputStream.close();

        return true;
    }

    return false;
}

bool BankStorage::loadUsersFromFile(std::string fileName = getUserFilePath()) {

    std::ifstream inputStream(fileName);

    std::string text;

    if (inputStream.is_open()) {

        // Process a user from each line of the text file
        while (std::getline(inputStream, text)) {

            // Vetor to hold data of the user being read from the file
            std::vector<std::string> userData;

            // Debug print to console
            std::cout << "Read line: " << text << std::endl;

            // Convert text to character array
            char* text_as_chars = new char[text.size()];
            for (int i = 0; i < text.size(); i++) {

                text_as_chars[i] = text[i];
            }

            // Tokenize the read text given the tab character as the delimiter
            char* token = strtok(text_as_chars, "\t");

            // add each token to the user data vector
            userData.push_back(token);

            // Repeat tokenization for the rest of the character array
            while (token != NULL) {

                token = strtok(NULL, "\t");
                userData.push_back(token);
            }

            // Delete pointer data if it is still allocated
            if (text_as_chars != NULL)
                delete[] text_as_chars;
            if (token != NULL) 
                delete token;

            // Validate each token
            if (userData.size() == 6) {

                try {

                    int id = std::stoi(userData[0]);
                    std::string userName = userData[1];
                    std::string password = userData[2];
                    std::string firstName = userData[3];
                    std::string lastName = userData[4];
                    double balance = std::stod(userData[5]);

                    // Attempt to create a new user given the information and add it to the user list
                    User u(id, userName, password, firstName, lastName, balance);
                    addUser(u);
                }
                catch(std::exception ex) {

                    std::cout << "Failed to read in user";
                }
            }
        }

        // Close the input stream
        inputStream.close();

        return true;
    }

    return false;
}


/* Manager Data Functions */

Manager BankStorage::loginManager(std::string uName, std::string pswd) const {

    for (Manager existing : managerList) {

        if (uName.compare(existing.getUsername()) == 0 && pswd.compare(existing.getPassword()) == 0) {

            bankLogic->setCurrentUser(existing);
        }
    }
}

bool BankStorage::saveManager(Manager m) {

    for (int i = 0; i < managerList.size(); i++) {

        if (managerList[i].getID() == m.getID()) {

            managerList[i] = m;
            return true;
        }
    }

    return false;
}

bool BankStorage::saveManagersToFile(std::string fileName = getManagerFilePath()) {

    std::ofstream outputStream(fileName);

    std::string text;

    if (outputStream.is_open()) {

        // Write each user's data to the text file
        for (Manager m : managerList) {

            std::string managerDataString = std::to_string(m.getID()) + "\t" + m.getUsername() +
                "\t" + m.getPassword() + "\t" + m.getFirstName() + "\t" + m.getLastName();
            outputStream << managerDataString;
        }

        outputStream.close();

        return true;
    }

    return false;
}

bool BankStorage::loadManagersFromFile(std::string fileName = getManagerFilePath()) {

    std::ifstream inputStream(fileName);

    std::string text;

    if (inputStream.is_open()) {

        // Process a manager from each line of the text file
        while (std::getline(inputStream, text)) {

            // Vetor to hold data of the manager being read from the file
            std::vector<std::string> managerData;

            // Debug print to console
            std::cout << "Read line: " << text << std::endl;

            // Convert text to character array
            char* text_as_chars = new char[text.size()];
            for (int i = 0; i < text.size(); i++) {

                text_as_chars[i] = text[i];
            }

            // Tokenize the read text given the tab character as the delimiter
            char* token = strtok(text_as_chars, "\t");

            // add each token to the manager data vector
            managerData.push_back(token);

            // Repeat tokenization for the rest of the character array
            while (token != NULL) {

                token = strtok(NULL, "\t");
                managerData.push_back(token);
            }

            // Delete pointer data if it is still allocated
            if (text_as_chars != NULL)
                delete[] text_as_chars;
            if (token != NULL)
                delete token;
        }

        // Close the input stream
        inputStream.close();

        return true;
    }

    return false;
}

/* Static Data for File Storage Information */

std::string BankStorage::getUserFilePath() {

    return folderName + usersFileName;
}

std::string BankStorage::getManagerFilePath() {

    return folderName + managersFileName;
}