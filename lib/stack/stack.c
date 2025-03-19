#include "stack.h"

stack_s* init_stack(size_t capacity, stack_t type)
{
    if (capacity <= 0) {
        PRINT_ERROR("Stack Capacity Cannot Be 0 or Lower");
        return NULL;
    }

    stack_s* stack = malloc(sizeof(stack_s));

    stack->capacity = capacity;
    stack->size = 0;
    stack->type = type;
    stack->array = malloc(capacity * sizeof(void*));

    if (stack->array == NULL) {
        PRINT_ERROR("Failed To Malloc Stack array");
        return NULL;
    }
    
    return stack;
}

void destroy_stack(stack_s* stack)
{
    if (stack == NULL) {
        PRINT_ERROR("Cannot Destroy An Uninitialized Stack");
        return;
    }

    for (size_t i = 0; i < stack->size; i++)
        if (stack->array[i] != NULL && stack->type != VOID)
            free(stack->array[i]);
    free(stack->array);
    free(stack);
}
