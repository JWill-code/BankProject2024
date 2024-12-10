#include <iostream>
#include <iomanip>

#include "BankStorage.h"
#include "BankLogic.h"
#include "Account.h"

// Constructor of the main bank application
BankLogic::BankLogic() 
{
    // Set console output to round to two decimal places
    std::cout << std::fixed << std::setprecision(2);

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

    std::cout << std::endl << "Thank you for choosing our bank! Saving and exiting..." << std::endl;

    bankStorage->saveUsersToFile();
    bankStorage->saveManagersToFile();
}

void BankLogic::displayBankMenu() 
{
    // User input
    int functNum;
    
    std::cout << std::endl << "Please Select an Option: " << std::endl;
    std::cout << "1. User Login" << std::endl;
    std::cout << "2. Create Account" << std::endl;
    std::cout << "3. Manager Login" << std::endl;
    std::cout << "4. Exit " << std::endl;

    // Get selected option from user
    // If an invalid value was entered, cancel and clear the console buffer
    if (!(std::cin >> functNum)) {

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << std::endl << "Error: Bad input value" << std::endl;

        return;
    }

    // Possible inputs used in switch function
    std::string enteredUsername;
    std::string enteredPassword;
    std::string enteredFirstName;
    std::string enteredLastName;
    int enteredAccountType = -2;

    // Placeholder to get unique account ID
    int uniqueID = Account::getNumAccounts() + 1;

    switch (functNum)
    {
        
    case 1: // User Login

        // Get user input
        std::cout << std::endl << "Enter login information (or type \"cancel\" to exit)" << std::endl;

        std::cout << "Username: ";
        std::cin >> enteredUsername;

        if (enteredUsername.compare("cancel") == 0)
        {
            break;
        }

        std::cout << "Password: ";
        std::cin >> enteredPassword;

        if (enteredPassword.compare("cancel") == 0)
        {
            break;
        }

        // Attempt to log in the user with the given input
        if (bankStorage->loginUser(enteredUsername, enteredPassword))
        {
            displayUserMenu();
        }
        else
        {
            std::cout << "Invalid username or password." << std::endl;
        }

        break;
    
        
    case 2: // Create Account

        std::cout << std::endl << "Provide the following information to create a new account: " << std::endl;

        std::cout << "Username (or type \"cancel\" to exit): ";
        std::cin >> enteredUsername;

        // If blank, cancel
        if (enteredUsername.compare("cancel") == 0)
        {
            break;
        }

        std::cout << "Password (or type \"cancel\" to exit): ";
        std::cin >> enteredPassword;

        // If blank, cancel
        if (enteredUsername.compare("cancel") == 0)
        {
            break;
        }

        std::cout << "First Name (or type \"cancel\" to exit): ";
        std::cin >> enteredFirstName;

        // If blank, cancel
        if (enteredFirstName.compare("cancel") == 0) {

            break;
        }

        std::cout << "Last Name (or type \"cancel\" to exit): ";
        std::cin >> enteredLastName;

        // If blank, cancel
        if (enteredLastName.compare("cancel") == 0) {

            break;
        }

        std::cout << "Account type (enter 1 for Checking, 2 for Savings, or -1 to cancel): ";

        // Validate account number
        while (enteredAccountType == -2)
        {
            // Check if the inputted value is a number
            if (std::cin >> enteredAccountType)
            {
                // Cancel if -1 is entered
                if (enteredAccountType == -1)
                {
                    break;
                }
                // Continue loop if the user does not select a valid option
                else if (enteredAccountType != 1 && enteredAccountType != 2)
                {
                    std::cout << "Please enter a valid account type" << std::endl;
                    enteredAccountType = -2;
                }
            }
        }
        
        // Validate account type input
        if (enteredAccountType == 1 || enteredAccountType == 2) {

            // Generate a new unique ID for the user
            while (bankStorage->getUser(uniqueID)) 
            {
                uniqueID++;
            }

            // Create a new user with the provided information
            User newUser(uniqueID, enteredUsername, enteredPassword, enteredFirstName, enteredLastName, 0, enteredAccountType);
            
            if (!bankStorage->addUser(newUser)) {

                std::cout << "Unable to add user: A user with this username already exists!" << std::endl;
            }
        }

        break;

    case 3: // Manager Login

        std::cout << std::endl << "Enter login information (or type \"cancel\" to exit)" << std::endl;

        std::cout << "Username: ";
        std::cin >> enteredUsername;

        if (enteredUsername.compare("cancel") == 0)
        {
            break;
        }

        std::cout << "Password: ";
        std::cin >> enteredPassword;

        if (enteredPassword.compare("cancel") == 0)
        {
            break;
        }

        // Attempt to log in the manager with the given input
        if (bankStorage->loginManager(enteredUsername, enteredPassword))
        {
            displayManagerMenu();
        }
        else
        {
            std::cout << "Invalid username or password." << std::endl;
        }
        
        break;
 
    case 4: // Exit
        isRunning = false;
        break;
    }
}

void BankLogic::displayUserMenu() 
{  
    // Keep the user in their menu until they log out
    bool isInUserMenu = true;

    while (isInUserMenu) {

        // User input
        int functNum;

        std::cout << std::endl << "Hello, " << currentUser->getFirstName() << std::endl;
        std::cout << "Please Select an Option: " << std::endl;
        std::cout << "1. Cash Deposit" << std::endl;
        std::cout << "2. Cash Withdraw" << std::endl;
        std::cout << "3. Account Summary" << std::endl;
        std::cout << "4. Log Out" << std::endl;
        std::cout << "5. Exit " << std::endl;

        // Get selected option from user
        // If an invalid value was entered, cancel and clear the console buffer
        if (!(std::cin >> functNum)) {

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << std::endl << "Error: Bad input value" << std::endl;

            continue;
        }

        // Possible inputs used in switch function
        double amount;

        switch (functNum) {
        case 1: // Deposit

            std::cout << std::endl << "Enter deposit amount, or -1 to cancel: $";

            // If an invalid value was entered, cancel and clear the console buffer
            if (!(std::cin >> amount)) {

                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::cout << "Error: Bad input value" << std::endl;

                break;
            }

            if (amount == -1)
            {
                break;
            }

            if (!currentUser->deposit(amount)) {

                std::cout << "Error: Could not complete the deposit." << std::endl;
            }

            break;

        case 2: // Withdrawal

            std::cout << std::endl << "Enter withdrawal amount, or -1 to cancel: $";
            
            // If an invalid value was entered, cancel and clear the console buffer
            if (!(std::cin >> amount)) {

                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::cout << "Error: Bad input value" << std::endl;

                break;
            }

            if (amount == -1)
            {
                break;
            }

            if (!currentUser->withdraw(amount)) {

                std::cout << "Error: Could not complete the withdrawal. There may not be enough money in this account." << std::endl;
            }

            break;
        case 3: // Account Summary

            currentUser->printAccountSummary();
            break;

        case 4: // Log Out

            std::cout << std::endl << "Logging out..." << std::endl;

            // Save the current user and log them out
            if (!bankStorage->saveUser(*currentUser)) {

                std::cout << "Error saving account changes!" << std::endl;
            }

            currentUser = NULL;

            isInUserMenu = false;
            break;

        case 5: // Exit

            // Save the current user and log them out
            if (!bankStorage->saveUser(*currentUser)) {

                std::cout << std::endl << "Error saving account changes!" << std::endl;
            }

            currentUser = NULL;

            isInUserMenu = false;
            isRunning = false;
            break;
        }
    }
}

void BankLogic::displayManagerMenu() 
{
    bool isInManagerMenu = true;

    while (isInManagerMenu) {

        // User input
        int functNum;

        std::cout << std::endl << "Hello, " << currentUser->getFirstName() << " (Logged In as Manager)" << std::endl;
        std::cout << "Please Select an Option: " << std::endl;
        std::cout << "1. Cash Deposit:" << std::endl;
        std::cout << "2. Cash Withdraw:" << std::endl;
        std::cout << "3. Account Summary" << std::endl;
        std::cout << "4. List User Accounts" << std::endl;
        std::cout << "5. Examine Another Account" << std::endl;
        std::cout << "6. Delete An Account" << std::endl;
        std::cout << "7. Log Out" << std::endl;
        std::cout << "8. Exit " << std::endl;
        
        // Get selected option from user
        // If an invalid value was entered, cancel and clear the console buffer
        if (!(std::cin >> functNum)) {

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << std::endl << "Error: Bad input value" << std::endl;

            continue;
        }

        // Possible inputs used in switch function
        User* selectedUser;
        int accountID;
        double amount;

        switch (functNum)
        {
        case 1: // Deposit

            std::cout << std::endl << "Enter deposit amount, or -1 to cancel: $";
            
            // If an invalid value was entered, cancel and clear the console buffer
            if (!(std::cin >> amount)) {

                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::cout << "Error: Bad input value" << std::endl;

                break;
            }

            if (amount == -1)
            {
                break;
            }

            if (!currentUser->deposit(amount)) {

                std::cout << "Error: Could not complete the deposit." << std::endl;
            }

            break;

        case 2: // Withdrawal

            std::cout << std::endl << "Enter withdrawal amount, or -1 to cancel: $";
            
            // If an invalid value was entered, cancel and clear the console buffer
            if (!(std::cin >> amount)) {

                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::cout << "Error: Bad input value" << std::endl;

                break;
            }

            if (amount == -1) 
            {
                break;
            }

            if (!currentUser->withdraw(amount)) {

                std::cout << "Error: Could not complete the withdrawal. You may not have enough money in this account." << std::endl;
            }

            break;

        case 3: // Print Account Summary

            currentUser->printAccountSummary();
            break;

        case 4: // List User Accounts

            bankStorage->printUserData();
            break;

        case 5: // Examine Another User's account

            // Request account ID
            std::cout << std::endl << "Enter the ID of the account you wish to examine, or -1 to cancel: " << std::endl;
            std::cin >> accountID;

            if (accountID == -1)
            {
                break;
            }

            // Attempt to get the user
            selectedUser = bankStorage->getUser(accountID);

            // Check that a user was returned before printing their summary
            if (selectedUser)
            {
                selectedUser->printAccountSummary();
            }
            else
            {
                std::cout << "A user with this ID could not be found." << std::endl;
            }
            
            break;

        case 6: // Remove a user from the system

            // Request account ID
            std::cout << std::endl << "Enter the ID of the account you wish to remove, or -1 to cancel: " << std::endl;

            if (!std::cin >> accountID || accountID == -1)
            {
                break;
            }

            // Attempt to remove the user
            if (!bankStorage->removeUser(accountID))
            {
                std::cout << "An account with this ID was not found or could not be removed." << std::endl;
            }

            break;

        case 7: // Log Out

            std::cout << std::endl << "Logging out..." << std::endl;

            // Save the current user and log them out
            if (!bankStorage->saveManager(*currentUser)) 
            {
                std::cout << "Error saving account changes!" << std::endl;
            }

            currentUser = NULL;

            isInManagerMenu = false;
            break;

        case 8: // Exit

            // Save the current user and log them out
            if (!bankStorage->saveManager(*currentUser))
            {
                std::cout << std::endl << "Error saving account changes!" << std::endl;
            }

            currentUser = NULL;

            isInManagerMenu = false;
            isRunning = false;
            break;
        }

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