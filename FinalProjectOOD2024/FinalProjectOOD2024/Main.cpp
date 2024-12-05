#include <iostream>
#include <fstream>
#include "BankLogic.h"

// Entry point of the program
int main() {

    // Create and open a text file
    ofstream MyFile("Manager.txt");
    // Write to the file
    MyFile << "Content for User information";
    // Close the file
    MyFile.close();
    // Create and open a text file
    ofstream MyFile("Manager.txt");
    // Write to the file
    MyFile << "Content for Manager Information";
    // Close the file
    MyFile.close();
	// Error handling controls sudden system crashes
	try {

		// Create a new instance of the bank logic application
		BankLogic bankLogic;
	}
	catch (int exception) {

		std::cout << exception;
	}
}