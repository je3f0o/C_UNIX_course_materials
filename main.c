
#include <stdio.h>

// Unary operators
// OPERAND op (Unary postfix operator)
// op OPERAND (Unary prefix operator)

// Binary operators
// OPERAND op OPERAND

#define TRUE  1
#define FALSE 0
#define BOOL char

int main (void)
{
    BOOL x = TRUE;
    if (x == TRUE) printf("true\n");
    else printf("false\n");

    return 0;
}
