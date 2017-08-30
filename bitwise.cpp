/******************************************************************
 *
 * Description: functions that use bitwise operators to perform the following operations:
 * reverse an unsigned char, reverse an unsigned int and negate a float
 *
 * Input: none
 *
 * Output: argument and return value for each respective function
 *
 ******************************************************************/


#include <iostream>
#include <climits>
#include <cfloat>
using namespace std;

unsigned char reverse(unsigned char);
unsigned int reverse(unsigned int);
void printBits(unsigned char);
void printBits(unsigned int);
float negateFloat(float);

int main () {
    unsigned char reverseme = 0x5B;
    unsigned char reversed;
    unsigned int reverseInt = 12;
    unsigned int reversedInt;
    
    cout << "1. Reversing an unsigned char" << endl;
    reversed = reverse(reverseme);
    printf("Hex: %x reversed is %x\n", reverseme, reversed);
    cout << "Binary: ";
    printBits(reverseme);
    cout << " reversed is ";
    printBits(reversed);
    cout << endl << endl;
    
    cout << "2. Reversing and unsigned int" << endl;
    reversedInt = reverse(reverseInt);
    cout << reverseInt << " reversed is ";
    printf("%d\n", reversedInt);
    cout << "Binary: ";
    printBits(reverseInt);
    cout << " reversed is ";
    printBits(reversedInt);
    cout << endl << endl;
    
    cout << "3. Negating a number" << endl;
    float negateme = -FLT_MAX;
    cout << "Original number: ";
    printf("%f\n", negateFloat(negateme));
    cout << "Negated number: ";
    negateme = FLT_MAX;
    printf("%f\n", negateFloat(negateme));
}

unsigned char reverse(unsigned char reverseme) {
    int shift;
    unsigned char reversed = 0;
    for (shift = 0; shift < CHAR_BIT; shift++) {
        if(reverseme & (0x01 << shift)) {
            reversed |= (0x80 >> shift);
        }
    }
    return reversed;
}

unsigned int reverse(unsigned int reverseme) {
    int shift;
    unsigned int reversed = 0;
    for (shift = 0; shift < sizeof(unsigned int)*CHAR_BIT; shift++) {
        if(reverseme & (0x01 << shift)) {
            reversed |= (0x80000000 >> shift);
        }
    }
    return reversed;
}

void printBits(unsigned char printme) {
    int shift;
    for (shift = CHAR_BIT - 1; shift >= 0; shift--) {
        if(printme & (0x01 << shift)) {
            cout << "1";
        }
        else {
            cout << "0";
        }
    }
}

void printBits(unsigned int printme) {
    int shift;
    for (shift = sizeof(unsigned int)*CHAR_BIT - 1; shift >= 0; shift--) {
        if(printme & (0x01 << shift)) {
            cout << "1";
        }
        else {
            cout << "0";
        }
    }
}

float negateFloat(float negateMe) {
    int *bitmap = (int *) &negateMe;
    
    if (*bitmap & (0x01 << 31)) {  //negative number, so turn off the sign bit
        *bitmap &= ~(0x01 << 31);
    }
    else { //positive number, so turn on the sign bit
        *bitmap |= (0x01 << 31);
    }
    return negateMe;
}
