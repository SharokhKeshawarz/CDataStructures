#include "../include/stack.h"

void stack_destroy(stack_s* stack)
{
    if (stack == NULL) {
        PRINT_ERROR("Cannot free an uninisilized stack");
        return;
    }

    for (size_t i = 0; i < stack->size; i++)
        if (stack->array[i] != NULL)
            free(stack->array[i]);

    free(stack->array);
    free(stack);
}
