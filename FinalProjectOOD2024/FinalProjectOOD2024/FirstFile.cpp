#include <iostream>
#include <fstream> // Required for file operations
#include <string>

using namespace std;

int main() {

	// Writing to a text file
	ofstream outputFile("example.txt", ofstream::app); // Create or open

	//a file for writing
	if (outputFile.is_open()) { // Check if the file is successfully

		//opened
		outputFile << "Account#: 11111" << endl;
		outputFile << "Login info: " << endl;
		outputFile << "Name: First Last." << endl;

		// Close the file after writing
		outputFile.close();
		cout << "Data written to the file successfully." << endl;
	}
	else {

		cout << "Unable to open the file for writing." << endl;
	}

	// Reading from the text file
	ifstream inputFile("example.txt"); // Open the file for reading

	if (inputFile.is_open()) { // Check if the file is successfully

		//opened
		cout << "Reading data from the file:" << endl;

		// Read and display each line from the file
		string line;

		while (getline(inputFile, line)) {

			cout << line << endl;
		}

		// Close the file after reading
		inputFile.close();
	}
	else {

		cout << "Unable to open the file for reading." << endl;
	}

	return 0;
}