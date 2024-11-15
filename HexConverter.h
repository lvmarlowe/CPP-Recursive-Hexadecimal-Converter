/*  LV Marlowe
    SDEV-345: Data Structures & Algorithms
    Week 8: Assignment
    19 Oct 2024
    This header file defines the HexConverter class,
    which converts decimal integers to hexadecimal 
    using recursion.
-------------------------------------------------- */

#ifndef HEX_CONVERTER_H
#define HEX_CONVERTER_H

#include <string>

using namespace std;

class HexConverter {
public:
    string convertToHex(long long number);

private:
    char hexDigit(int digit);
};

#endif // HEX_CONVERTER_H