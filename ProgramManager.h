/*  LV Marlowe
    SDEV-345: Data Structures & Algorithms
    Week 8: Assignment
    19 Oct 2024
    This header file defines the ProgramManager class,
    which controls the flow of the program. It 
    requires HexConverter.h to run.
-------------------------------------------------- */

#ifndef PROGRAM_MANAGER_H
#define PROGRAM_MANAGER_H

#include "HexConverter.h"
#include <string>

using namespace std;

class ProgramManager {
public:
    void run();

private:
    HexConverter hexConverter;
    void displayWelcome();
    long long getUserInput();
    void displayResult(long long number, const string& hexRepresentation);
    char getContinueChoice();
    void displayExit();
};

#endif // PROGRAM_MANAGER_H