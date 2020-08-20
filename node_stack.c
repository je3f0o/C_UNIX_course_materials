
#include <stdio.h>
#include <stdlib.h>

#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0

#define ERR_STACK_NONE              0
#define ERR_STACK_EMPTY             1
#define ERR_STACK_MAX               2
#define ERR_STACK_MEMORY_ALLOCATION 3
#define STACK_MAX_LENGTH 1024

const int ERR_STACK_VALUE = 0xFFFFFFFF;

typedef struct StackNode_type {
    int value;
    struct StackNode_type * prev;
} StackNode;

typedef struct {
    int error_code;
    StackNode * top;
    unsigned int length;
} Stack;

Stack stack_init (void) {
    Stack default_stack = {
        ERR_STACK_NONE,
        NULL,
        0
    };
    return default_stack;
}

unsigned int stack_push (Stack * stack, int value) {
    if (stack->length == STACK_MAX_LENGTH) {
        stack->error_code = ERR_STACK_MAX;
        return ERR_STACK_VALUE;
    }

    StackNode * next_node = (StackNode*) malloc(sizeof(StackNode));
    if (next_node == NULL) {
        stack->error_code = ERR_STACK_MEMORY_ALLOCATION;
        return ERR_STACK_VALUE;
    }
    next_node->value = value;
    next_node->prev  = stack->top;
    stack->top = next_node;

    return ++stack->length;
}

int stack_pop (Stack * stack) {
    if (stack->top == NULL) {
        stack->error_code = ERR_STACK_EMPTY;
        return ERR_STACK_VALUE;
    }

    StackNode * top = stack->top;
    stack->top     = top->prev;
    stack->length -= 1;

    int ret = top->value;
    free(top);

    return ret;
}

void stack_print (Stack * stack) {
    while (stack->top != NULL) {
        int value = stack_pop(stack);
        if (stack->error_code != ERR_STACK_NONE) {
            fprintf(stderr, "Error log\n");
            return;
        }

        printf("last poped value = %d, len = %d\n", value, stack->length);
    }
}

int main (void)
{
    Stack s1 = stack_init();
    Stack s2 = stack_init();
    Stack s3 = stack_init();

    stack_push(&s1, 123);

    stack_push(&s2, 123);
    stack_push(&s2, 321);
    stack_push(&s2, 999);

    stack_push(&s3, 444);

    stack_print(&s2);

    return EXIT_SUCCESS;
}
