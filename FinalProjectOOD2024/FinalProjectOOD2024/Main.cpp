#include <iostream>

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
}