#include "../include/stack.h"

stack_s* stack_create(size_t capacity, stack_t type)
{
    if (capacity == 0) {
        PRINT_ERROR("Capacity should at least be 1");
        return NULL;
    }

    stack_s* stack = malloc(sizeof(stack_s));
    if (stack == NULL) {
        PRINT_ERROR("failed to malloc for stack");
        return NULL;
    }

    stack->capacity = capacity;
    stack->size = 0;
    stack->type = type;

    stack->array = malloc(capacity * sizeof(void*));
    if (stack->array == NULL) {
        PRINT_ERROR("Failed to malloc for array");
        return NULL;
    }

    for (size_t i = 0; i < stack->capacity; i++)
        stack->array[i] = NULL;

    return stack;
}
