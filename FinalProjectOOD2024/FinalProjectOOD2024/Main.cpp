#include <iostream>

#include "BankLogic.h"

int main() {

	try {

		BankLogic bankLogic;
	}
	catch (int exception) {

		std::cout << exception;
	}
}