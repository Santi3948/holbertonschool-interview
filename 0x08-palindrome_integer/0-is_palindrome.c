#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "palindrome.h"

/**
 * is_palindrome - checks whether or not a given unsigned integer is a palindrome
 *
 * @n: the number to be checked
 *
 * Return: 1 if n is a palindrome, and 0 otherwise
 */
int is_palindrome(unsigned long n)
{
    char mystr[20];
    size_t i, j;

    itoa(n, mystr, 10);
    j = strlen(mystr) - 1;

    for (i = 0; i <strlen(mystr)/2; i++)
    {
        if (mystr[i] != mystr[j])
            return (0);
        j--;
    }
    return (1);
}
/**
 * itoa - pass int to string
 * @value: the integer
 * @result: the base of the number
 * @base: the base
 * Return: the string
 * */
char* itoa(int value, char* result, int base) 
{
    // check that the base if valid
    if (base < 2 || base > 36) { *result = '\0'; return result; }

    char* ptr = result, *ptr1 = result, tmp_char;
    int tmp_value;

    do {
        tmp_value = value;
        value /= base;
        *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
    } while ( value );

    // Apply negative sign
    if (tmp_value < 0) *ptr++ = '-';
    *ptr-- = '\0';
    while(ptr1 < ptr) {
        tmp_char = *ptr;
        *ptr--= *ptr1;
        *ptr1++ = tmp_char;
    }
    return result;
}
	