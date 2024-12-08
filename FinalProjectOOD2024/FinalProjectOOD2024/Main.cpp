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
    cout << "Type integer for associated function" << endl;
    cout << "1. User Login" << endl;
    cout << "2. Create Account" << endl;
    cout << "3. Manager Login" << endl;
    cout << "4. Exit " << endl;
    cin >> functNum;
}