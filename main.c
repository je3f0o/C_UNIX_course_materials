
#include <stdio.h>

/**
 * ASCII
 * American Standard Code for Information Interchange
 *
 */

int main ()
{
    char my_string[] = "Hello world";

    printf("%s\n", my_string);
    printf("my_string size = %ld bytes.\n", sizeof my_string);

    return 0;
}
