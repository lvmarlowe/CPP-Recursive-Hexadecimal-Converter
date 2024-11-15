/*  LV Marlowe
    SDEV-345: Data Structures & Algorithms
    Week 8: Assignment
    19 Oct 2024
    This file implements the HexConverter class,
    which converts decimal integers to hexadecimal 
    using recursion. It requires HexConverter.h to
    run. Based on code from:
    https://www.geeksforgeeks.org/convert-decimal-to-hexadecimal-in-cpp/
-------------------------------------------------- */

#include "HexConverter.h"

using namespace std;

// Convert decimal to hexadecimal
string HexConverter::convertToHex(long long number) {

    // Handle negative numbers
    if (number < 0) {
        return "-" + convertToHex(-number);
    }

    // Base case: if number is less than 16, return its hex representation
    if (number < 16) {
        return string(1, hexDigit(number));
    }

    // Recursive case: convert the quotient and append the remainder
    return convertToHex(number / 16) + hexDigit(number % 16);
}

// Find corresponding hexadecimal digit
char HexConverter::hexDigit(int digit) {
    if (digit < 10) {
        return '0' + digit;
    }
    else {
        return 'A' + (digit - 10);
    }
}