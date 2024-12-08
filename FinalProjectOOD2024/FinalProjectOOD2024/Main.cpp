#include <iostream>
#include <fstream>
#include "BankLogic.h"

// Entry point of the program
int main() {

	// Error handling controls sudden system crashes
	try {

		// Create a new instance of the bank logic application
		BankLogic bankLogic;
	}
	catch (int exception) {

		std::cout << exception;
	}
    //
    int functNum;
    std::cout << "Type integer for associated function" << std::endl;
    std::cout << "1. User Login" << std::endl;
    std::cout << "2. Create Account" << std::endl;
    std::cout << "3. Manager Login" << std::endl;
    std::cout << "4. Exit " << std::endl;
    std::cin >> functNum;
}