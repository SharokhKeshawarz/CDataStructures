#include "../include/stack.h"

void stack_pop(stack_s* stack)
{
    if (stack == NULL) {
        PRINT_ERROR("Cannot pop from an uninitialized stack");
        return;
    }
    if (stack->size == 0) {
        PRINT_ERROR("Cannot pop from an empty stack");
        return;
    }

    void* data = stack->array[stack->size - 1];
    free(data);
    stack->size--;
}
