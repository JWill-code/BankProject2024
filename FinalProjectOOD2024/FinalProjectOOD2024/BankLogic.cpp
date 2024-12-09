#include <iostream>
#include "BankStorage.h"
#include "BankLogic.h"
#include "Account.h"

// Constructor of the main bank application
BankLogic::BankLogic() 
{

    isRunning = true;

    // Fix Visual Studio warning about uninitialized member variable
    currentUser = NULL;

    // Initialize the bank storage to get user and manager data
	bankStorage = new BankStorage(this);
    bankStorage->loadUsersFromFile();
    bankStorage->loadManagersFromFile();

    while (isRunning) {

        displayBankMenu();
    }

    bankStorage->saveUsersToFile();
    bankStorage->saveManagersToFile();
}

void BankLogic::displayBankMenu() 
{

    //copy stuff from main.cpp concept, use while loop added to control whether it displays
    //type 1 or 2 for account type; checking or savings
    int functNum;
    std::cout << "Type integer for associated function: " << std::endl;
    std::cout << "1. User Login" << std::endl;
    std::cout << "2. Create Account" << std::endl;
    std::cout << "3. Manager Login" << std::endl;
    std::cout << "4. Exit " << std::endl;
    std::cin >> functNum;
    switch (functNum) //can't initialize apparently
    {
    case 1: {
        //loginUser(); //string, string
        //string enteredUsername = "";
        std::cout << "enter username: " << std::endl;
        //std::cin >> User.username;

        std::string enteredUsername;
        std::getline(std::cin, enteredUsername);
        std::cout << "enter password: " << std::endl;
        //std::cin >> User.password;
        std::string enteredPassword;
        std::getline(std::cin, enteredPassword);
        bankStorage->loginUser(enteredUsername, enteredPassword);
        //sets user
        //->setCurrentUser();
        displayUserMenu();
        break;
    }
        case 2:
            //create account
            std::cout << "enter account information so we can create one: " << std::endl;
            currentUser->add();
            break;
        case 3: {
            //manager login
            std::cout << "enter username: " << std::endl;
            //std::cin >> Manager.username;
            std::string mEnteredUsername;
            std::getline(std::cin, mEnteredUsername);
            std::cout << "enter password: " << std::endl;
            //std::cin >> Manager.password;
            std::string mEnteredPassword;
            std::getline(std::cin, mEnteredPassword);
            bankStorage->loginManager(mEnteredUsername, mEnteredPassword);
            
            //setCurrentUser(); //manager setCurrentUser
            displayManagerMenu();
            break;
        }
        case 4:
            isRunning = false;
            break;
    }
}

void BankLogic::displayUserMenu() 
{
    int functNum2;
    std::cout << "Type integer for associated function by user: " << std::endl;
    std::cout << "1. Deposit Money" << std::endl;
    std::cout << "2. Withdraw Money" << std::endl;
    std::cout << "3. Print Account Summary" << std::endl;
    std::cout << "4. Exit " << std::endl;
    std::cin >> functNum2;
    //type 1 or 2 for account type; checking or savings
    switch (functNum2) {
    case 1:
        //deposit
        double depositAmount;
        std::cout << "enter quantity of money you want to deposit: " << std::endl;
        std::cin >> depositAmount;
        currentUser->deposit(depositAmount);
        break;
    case 2:
        //withdraw
        double withdrawAmount;
        std::cout << "enter quantity of money you want to withdraw: " << std::endl;
        std::cin >> withdrawAmount;
        currentUser->withdraw(withdrawAmount);
        break;
    case 3:
        //print account summary
        currentUser->printAccountSummary();
        break;
    case 4:
        //exit??
        bankStorage->saveUsersToFile();
        bankStorage->saveManagersToFile();
        isRunning = false;
        break;
    }
}

void BankLogic::displayManagerMenu() 
{
    int functNum3;
    std::cout << "Type integer for associated Manager function: " << std::endl;
    std::cout << "1. Deposit Money in Account:" << std::endl;
    std::cout << "2. Withdraw from Account:" << std::endl;
    std::cout << "3. print account summary of a given account number" << std::endl;
    std::cout << "4. print summary of own account: " << std::endl;
    std::cout << "5. Exit " << std::endl;
    std::cin >> functNum3;
    switch (functNum3) 
    {
    case 1:
        //something

        break;
    case 2:
        //something
        break;
    case 3: {
        //print account summary of given account number
        std::cout << "enter number of account you want a summary of: " << std::endl;
        //std::cin >> Account.id;
        std::string enteredAccountNumber;
        std::getline(std::cin, enteredAccountNumber);
        //loop through account list probably
        //int numAcc = getNumAccounts();
        /*for (int i =0; i<numAcc; i++) {
        
        }*/
        
        //this account is attached to the id number
        //Manager->printAccountSummary();
        //need manager title
        break;
    }
    case 4:
        
        //print account owned by manager
        currentUser->printAccountSummary();
    case 5:
        //make while loop at top stop
        bankStorage->saveUsersToFile();
        bankStorage->saveManagersToFile();
        isRunning = false;
        break;
    }
    
}

/* Getters and Setters */

Account* BankLogic::getCurrentUser() const
{

	return currentUser;
}

void BankLogic::setCurrentUser(User* u) 
{

	// If the current user is not null, delete it
	if (currentUser != NULL) 
    {

		delete currentUser;
	}

    currentUser = new User(*u);
}

void BankLogic::setCurrentUser(Manager* m)
{

    // If the current user is not null, delete it
    if (currentUser != NULL)
    {

        delete currentUser;
    }

    currentUser = new Manager(*m);
}