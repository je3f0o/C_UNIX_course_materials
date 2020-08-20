
#include <stdio.h>

void swap (int * ptr_a, int * ptr_b) {
    const int temp = *ptr_a;
    *ptr_a = *ptr_b;
    *ptr_b = temp;
}

int main (void)
{
    int array[2] = {333, 666};

    printf("a = %d\nb = %d\n", array[0], array[1]);
    printf("--------------\n");
    swap(&(array[0]), &(array[1]));
    printf("a = %d\nb = %d\n", array[0], array[1]);

    return 0;
}







