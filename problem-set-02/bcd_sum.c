/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
// Escribir un algoritmo que permita sumar dos enteros de hasta 2 dígitos, 
// representados como
// enteros sin signo empaquetado (BCD). El resultado se expresa también en BCD
// empaquetado
// Number example:
// 15 = 0000 0001 0000 0101
short sumaBCD(char num1, char num2) {
    
    printf("Numbers: %X %X\n", num1, num2);
    
    // Extract second digits
    char num1_second_digit = num1 & 0x0F;
    char num2_second_digit = num2 & 0x0F;

    // Sum second digits
    char second_digit_result = num1_second_digit + num2_second_digit;

    // Extract first digits
    char num1_first_digit = num1 >> 4 & 0x0F;
    char num2_first_digit = num2 >> 4 & 0x0F;

    char carry = 0x00;
    if (second_digit_result > 9) {
        second_digit_result = second_digit_result - 10;
        carry = 0x01;    
    };
    
    // Sum first digits
    char first_digit_result = num1_first_digit + num2_first_digit + carry;

    short final_result = 0;
    if (first_digit_result > 9) {
        printf("Overflow: %d %d\n", first_digit_result, second_digit_result);
    } else {
        printf("Sum result: %d %d\n", first_digit_result, second_digit_result);
        // Correct representation
        short corrected_first_digit = first_digit_result << 4;
        final_result = corrected_first_digit | second_digit_result;
        printf("Result %x\n", final_result);
    };
    
    
    
    return final_result;
}


int main()
{
    // First test
    char num1 = 0x00; // 0000 0000
    char num2 = 0x00; // 0000 0000
    sumaBCD(num1, num2);

    // Second test
    num1 = 0x61; // 0000 0000
    num2 = 0x23; // 0000 0000
    sumaBCD(num1, num2);
 
    // Third test
    num1 = 0x98; // 0000 0000
    num2 = 0x01; // 0000 0000
    sumaBCD(num1, num2);
    
    // Overflow test
    num1 = 0x99; // 0000 0000
    num2 = 0x99; // 0000 0000
    sumaBCD(num1, num2);

    return 0;
}