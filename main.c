
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
 * Floating point numbers
 * - float
 * - double
 *
 * User Defined datatypes
 * ======================
 **/

/** Operator
 * = Assign Operator
 * sizeof
 */

int main ()
{
    float  fPI = 3.14159265359;
    double dPI = 3.14159265359;

    printf("Float  PI: %f, size: %ld bytes.\n", fPI, sizeof fPI);
    printf("Double PI: %f, size: %ld bytes.\n", dPI, sizeof dPI);

    return 0;
}
