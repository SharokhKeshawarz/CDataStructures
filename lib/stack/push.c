#include "../include/stack.h"

static void grow_stack(stack_s* stack)
{
    stack->capacity = stack->capacity * 2;
    void** temp = realloc(stack->array, stack->capacity * sizeof(void*));
    if (temp == NULL) {
        PRINT_ERROR("Failed to realloc stack when pushed");
        return;
    }
    stack->array = temp;
}

static void* allocate_and_copy(void* data, size_t data_size)
{
    void* newData = malloc(data_size);

    if (newData == NULL) {
        PRINT_ERROR("Failed To Malloc");
        return NULL;
    }
    memcpy(newData, data, data_size);
    return newData;
}

static void* allocate_and_copy_string(char* data)
{
    void* newData = malloc(strlen(data) + 1);

    if (!newData) {
        PRINT_ERROR("Failed To Malloc For String");
        return NULL;
    }
    strcpy((char*)newData, data);
    return newData;
}

static void* set_new_data(stack_s* stack, void* data, size_t data_size)
{
    void* newData = NULL;

    switch (stack->type) {
        case CHAR:
            newData = allocate_and_copy(data, sizeof(char));
            break;

        case UCHAR:
            newData = allocate_and_copy(data, sizeof(unsigned char));
            break;

        case STRING:
            newData = allocate_and_copy_string((char*)data);
            break;

        case BOOL:
            newData = allocate_and_copy(data, sizeof(bool));
            break;

        case SHORT:
            newData = allocate_and_copy(data, sizeof(short));
            break;

        case USHORT:
            newData = allocate_and_copy(data, sizeof(unsigned short));
            break;

        case UINT:
            newData = allocate_and_copy(data, sizeof(unsigned int));
            break;

        case INT:
            newData = allocate_and_copy(data, sizeof(int));
            break;
        
        case ENUM:
            newData = allocate_and_copy(data, sizeof(*((int*)data)));
            break;

        case LONG:
            newData = allocate_and_copy(data, sizeof(long));
            break;

        case ULONG:
            newData = allocate_and_copy(data, sizeof(unsigned long));
            break;
            
        case LONG_LONG:
            newData = allocate_and_copy(data, sizeof(long long));
            break;

        case ULONG_LONG:
            newData = allocate_and_copy(data, sizeof(unsigned long long));
            break;

        case FLOAT:
            newData = allocate_and_copy(data, sizeof(float));
            break;

        case DOUBLE:
            newData = allocate_and_copy(data, sizeof(double));
            break;

        case LONG_DOUBLE:
            newData = allocate_and_copy(data, sizeof(long double));
            break;

        case POINTER:
            newData = allocate_and_copy(data, sizeof(void*));
            break;

        case STRUCT:
            newData = allocate_and_copy(data, data_size);
            break;

        case UNION:
            newData = allocate_and_copy(data, data_size);
            break;

        default:
            PRINT_ERROR("Unsupported Data Type");
            return NULL;
    }

    return newData;
}

void stack_push(stack_s* stack, void* data, size_t data_size)
{
    if (stack == NULL) {
        PRINT_ERROR("Cannot Push In An Uninitialized Stack");
        return;
    }
    if (data == NULL) {
        PRINT_ERROR("Data Is NULL For Push");
        return;
    }
    if (stack->capacity == stack->size) grow_stack(stack);

    void* newData = set_new_data(stack, data, data_size);

    if (newData == NULL) {
        PRINT_ERROR("New pushed data is NULL");
        return;
    }

    stack->array[stack->size] = newData;
    stack->size++;
}
