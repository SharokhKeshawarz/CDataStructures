#include "stack.h"

void* pop_stack(stack_s* stack)
{
    if (stack == NULL) {
        PRINT_ERROR("Cannot Pop In A Uninisilized Stack");
        return NULL;
    }
    if (stack->size == 0) {
        PRINT_ERROR("Cannot Pop An Empty Stack");
        return NULL;
    }

    void* data = stack->array[stack->size - 1];
    stack->array[stack->size - 1] = NULL;
    stack->size--;
    
    return data;
}
