
#include <stdio.h>

/**
 * Primitive datatypes
 * ===================
 *
 * Intigere datatypes
 * ------------------
 * - char  1 byte
 * - short 2 byte
 * - int   4 byte
 * - long  8 byte
 *
 *
 * User Defined datatypes
 * ======================
 **/

/** Operator
 * = Assign Operator
 * sizeof
 */

// Max Integer Computer Science
// https://en.wikipedia.org/wiki/Integer_(computer_science)

/*
             -8 ..-3 -2 -1   1 2 3 4 5.. 7
---------------------------0-----------------------------
*/

int main ()
{
    unsigned char char_num   = 255;
    unsigned short short_num = 5000;
    unsigned int int_num     = 1000000;
    unsigned long long_num   = 1e7;

    printf("Char value: %d size: %ld bytes.\n"  , char_num  , sizeof char_num);
    printf("Short value: %d size: %ld bytes.\n" , short_num , sizeof short_num);
    printf("Int value: %d size: %ld bytes.\n"   , int_num   , sizeof int_num);
    printf("Long value: %ld size: %ld bytes.\n" , long_num  , sizeof long_num);

    return 0;
}
