
#include <stdio.h>

//static const unsigned int STACK_MAX_LENGTH = 1024;
#define STACK_MAX_LENGTH 1024
const int  ERR_STACK_VALUE = 0xFFFFFFFF;

#define ERR_STACK_NONE 0
const char ERR_STACK_EMPTY = 1;
const char ERR_STACK_FULL  = 2;

struct Stack_type {
    int error_code;
    int values[STACK_MAX_LENGTH];
    unsigned int length;
} STACK_DEFAULT = {
    ERR_STACK_NONE,
    {0},
    0
};

typedef struct Stack_type Stack;

unsigned int stack_push (Stack * ptr, int value) {
    if (ptr->length == STACK_MAX_LENGTH) {
        ptr->error_code = ERR_STACK_FULL;
        return ERR_STACK_VALUE;
    }

    ptr->values[ptr->length++] = value;
    return ptr->length;
}

int stack_pop (Stack * ptr) {
    if (ptr->length == 0) {
        ptr->error_code = ERR_STACK_EMPTY;
        return ERR_STACK_VALUE;
    }
    return ptr->values[--ptr->length];
}

void stack_print (Stack * ptr) {
    while (ptr->length != 0) {
        const int value = stack_pop(ptr);
        if (ptr->error_code != ERR_STACK_NONE) {
            fprintf(stderr, "Error log\n");
            return;
        }

        printf("last poped value = %d, len = %d\n", value, ptr->length);
    }
}

int main (void)
{
    Stack s1 = STACK_DEFAULT;
    Stack s2 = STACK_DEFAULT;
    Stack s3 = STACK_DEFAULT;

    stack_push(&s1, 123);

    stack_push(&s2, 123);
    stack_push(&s2, 321);
    stack_push(&s2, 999);

    stack_push(&s3, 444);

    stack_print(&s2);

    return 0;
}







