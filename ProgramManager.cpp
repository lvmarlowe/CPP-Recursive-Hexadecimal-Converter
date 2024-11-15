/*  LV Marlowe
    SDEV-345: Data Structures & Algorithms
    Week 8: Assignment
    19 Oct 2024
    This file implements the ProgramManager class,
    which controls the flow of the program. It 
    requires ProgramManager.h to run.
-------------------------------------------------- */

#include "ProgramManager.h"
#include <iostream>
#include <limits>
#include <iomanip>
#include <string>

using namespace std;

// Constants for formatting and messages
const string BORDER = "-------------------------------------------";
const int WIDTH = 43;  // Total width including '|' characters
const string PROMPT = "Enter an integer to convert to hexadecimal: ";
const string ERROR_MSG = "Invalid input. Please enter an integer: ";
const string RANGE_ERROR_MSG = "Number out of range. Please enter a smaller number: ";

// Run the program
void ProgramManager::run() {
    displayWelcome();

    char continueChoice;
    do {

        // Get user input and convert to hexadecimal
        long long number = getUserInput();
        string hexRepresentation = hexConverter.convertToHex(number);
        displayResult(number, hexRepresentation);

        // Ask user if they want to continue
        continueChoice = getContinueChoice();
    } while (continueChoice == 'y' || continueChoice == 'Y');

    displayExit();
}

// Display welcome message and program description
void ProgramManager::displayWelcome() {

    cout << BORDER << endl;
    cout << "|" << setw(WIDTH - 1) << left << " Welcome to Hexadecimal Converter" << "|" << endl;
    cout << BORDER << endl;
    cout << "|" << setw(WIDTH - 1) << left << " This program converts decimal integers" << "|" << endl;
    cout << "|" << setw(WIDTH - 1) << left << " to their hexadecimal representation." << "|" << endl;
    cout << BORDER << endl << endl;
}

// Convert and validate user input
long long ProgramManager::getUserInput() {
    long long number;
    string input;
    bool validInput = false;

    cout << PROMPT; 
    do {
        getline(cin, input);

        // Attempt to convert string input to long long
        // (https://cplusplus.com/reference/string/stoll/)
        try {
            number = stoll(input);  
            validInput = true;
        }

        // Handle noninteger input
        // (https://cplusplus.com/reference/stdexcept/invalid_argument/)
        catch (const invalid_argument& ia) {
            cout << ERROR_MSG;
        }

        // Handle numbers too large for long long
        // (https://cplusplus.com/reference/stdexcept/out_of_range/)
        catch (const out_of_range& oor) {
            cout << RANGE_ERROR_MSG;
        }
    } while (!validInput);

    return number;
}

// Display the original decimal and the hexadecimal conversion
void ProgramManager::displayResult(long long number, const string& hexRepresentation) {
    cout << "\n" << BORDER << endl;
    cout << "|" << setw(WIDTH - 1) << left << " Hexadecimal Converter" << "|" << endl;
    cout << BORDER << endl;
    cout << "| Decimal: " << setw(WIDTH - 11) << left << number << "|" << endl;
    cout << "| Hexadecimal: 0x" << setw(WIDTH - 17) << left << hexRepresentation << "|" << endl;
    cout << BORDER << endl;
}

// Loop through program until user chooses to exit program
char ProgramManager::getContinueChoice() {
    char choice;
    bool validInput = false;
    do {
        cout << "\nDo you want to convert another number? (y/n): ";
        string input;
        getline(cin, input);

        if (input.length() == 1) {
            choice = tolower(input[0]);
            if (choice == 'y' || choice == 'n') {
                validInput = true;
            }
        }

        if (!validInput) {
            cout << "Invalid input. Please enter 'y' or 'n'." << endl;
        }
    } while (!validInput);
    return choice;
}

// Display exit message
void ProgramManager::displayExit() {
    cout << "\n" << BORDER << endl;
    cout << "|" << setw(WIDTH - 1) << left << " Thank you for using Hexadecimal Converter" << "|" << endl;
    cout << BORDER << endl;
    cout << "|" << setw(WIDTH - 1) << left << " Goodbye!" << "|" << endl;
    cout << BORDER << endl;
}