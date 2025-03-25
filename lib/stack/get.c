#include "../include/stack.h"

static size_t stack_get_element_size(stack_s* stack)
{
    size_t element_size = 0;

    switch (stack->type) {
        case BOOL:          element_size = sizeof(bool); break;
        case CHAR:          element_size = sizeof(char); break;
        case UCHAR:         element_size = sizeof(unsigned char); break;
        case SHORT:         element_size = sizeof(short); break;
        case USHORT:        element_size = sizeof(unsigned short); break;
        case INT:           element_size = sizeof(int); break;
        case UINT:          element_size = sizeof(unsigned int); break;
        case LONG:          element_size = sizeof(long); break;
        case ULONG:         element_size = sizeof(unsigned long); break;
        case LONG_LONG:     element_size = sizeof(long long); break;
        case ULONG_LONG:    element_size = sizeof(unsigned long long); break;
        case FLOAT:         element_size = sizeof(float); break;
        case DOUBLE:        element_size = sizeof(double); break;
        case LONG_DOUBLE:   element_size = sizeof(long double); break;
        case ENUM:          element_size = sizeof(int); break;
        case POINTER: element_size = sizeof(void*); break;
        case VOID_POINTER: element_size = sizeof(void*); break;
        case STRING: element_size = 0; break;
        case STRUCT: element_size = 0; break;
        case UNION: element_size = 0; break;
        default:
            PRINT_ERROR("Unsupported type");
            return EXIT_FAILURE;
    }

    return element_size;
}

void* stack_get_top(stack_s* stack)
{
    if (stack == NULL) {
        PRINT_ERROR("Cannot get element on an uninisilized stack");
        return NULL;
    }
    if (stack->size == 0) {
        PRINT_ERROR("Cannot get element on an empty stack");
        return NULL;
    }

    return stack->array[stack->size - 1];
}

void* stack_get_bottom(stack_s* stack)
{
    if (stack == NULL) {
        PRINT_ERROR("Cannot get element on an uninisilized stack");
        return NULL;
    }
    if (stack->size == 0) {
        PRINT_ERROR("Cannot get element on an empty stack");
        return NULL;
    }

    return stack->array[0];
}

size_t stack_get_index(stack_s* stack, void* data, size_t (*compare_function)(void*, void*))
{
    if (stack == NULL) {
        PRINT_ERROR("Cannot get element on an uninisilized stack");
        return EXIT_FAILURE;
    }
    if (stack->size == 0) {
        PRINT_ERROR("Cannot get element on an empty stack");
        return EXIT_FAILURE;
    }
    if (data == NULL) {
        PRINT_ERROR("Cannot search for NULL data");
        return EXIT_FAILURE;
    }

    size_t element_size = stack_get_element_size(stack);

    for (size_t i = 0; i < stack->size; i++) {
        void* element = stack->array[i];

        if (stack->type == STRING) {
            if (strcmp((char*)element, (char*)data) == 0)
                return i;
        }
        else if (stack->type == STRUCT || stack->type == UNION) {
            if (compare_function != NULL && compare_function(element, data) == 0)
                return i;
        }
        else if (memcmp(element, data, element_size) == 0) {
            return i;
        }
    }
    PRINT_ERROR("Element not found in stack");
    return EXIT_FAILURE;
}

void* stack_get_data(stack_s* stack, size_t index)
{
    if (stack == NULL) {
        PRINT_ERROR("Cannot get element on an uninisilized stack");
        return NULL;
    }
    if (stack->size == 0) {
        PRINT_ERROR("Cannot get element on an empty stack");
        return NULL;
    }
    if (index >= stack->size) {
        PRINT_ERROR("Index out of bounds");
        return NULL;
    }
    return stack->array[index];
}
