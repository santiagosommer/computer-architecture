#include <stdio.h>
/* 
Write an algorithm to add two-digit unsigned integers,
represented as packed Binary-Coded Decimal (BCD).
The result should also be represented in packed BCD.
e.g.: 
15 = 0001 0101
10 = 0001 0000
10 + 15 = 25 = 0000 0000 0000 0000 
*/
short sumaBCD(char num1, char num2) {

    printf("Numbers: %X %X\n", num1, num2);

    // Extract least significant BCD digit (lower nibble)
    char num1_low = num1 & 0x0F;
    char num2_low = num2 & 0x0F;

    // Add least significant digits
    char low_result = num1_low + num2_low;

    // Extract most significant BCD digit (upper nibble)
    char num1_high = (num1 >> 4) & 0x0F;
    char num2_high = (num2 >> 4) & 0x0F;

    char carry = 0x00;
    if (low_result > 9) {
        low_result -= 10;     // adjust to valid BCD
        carry = 0x01;         // propagate carry
    }

    // Add most significant digits, including carry
    char high_result = num1_high + num2_high + carry;

    short final_result = 0;
    if (high_result > 9) {
        printf("Overflow: %d %d\n", high_result, low_result);
    } else {
        printf("Sum result: %d %d\n", high_result, low_result);
        // Repack the digits into a single BCD value
        short packed_result = (high_result << 4) | low_result;
        final_result = packed_result;
        printf("Result %X\n", final_result);
    }

    return final_result;
}


int main()
{
    // First test: 00 + 00 = 00
    char num1 = 0x00; // binary: 0000 0000
    char num2 = 0x00; // binary: 0000 0000
    sumaBCD(num1, num2);

    // Second test: 61 + 23 = 84
    num1 = 0x61; // binary: 0110 0001
    num2 = 0x23; // binary: 0010 0011
    sumaBCD(num1, num2);
 
    // Third test: 98 + 01 = 99
    num1 = 0x98; // binary: 1001 1000
    num2 = 0x01; // binary: 0000 0001
    sumaBCD(num1, num2);
    
    // Overflow test: 99 + 01 -> overflow
    num1 = 0x99; // binary: 1001 1001
    num2 = 0x01; // binary: 0000 0001
    sumaBCD(num1, num2);

    return 0;
}