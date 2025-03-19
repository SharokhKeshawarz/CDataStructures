#include "stack.h"

void print_stack(stack_s* stack, void (*custom_print_func)(void*))
{
    if (stack == NULL) {
        PRINT_ERROR("Cannot Print An Uninitialized Stack");
        return;
    }

    for (size_t i = 0; i < stack->size; i++) {
        switch (stack->type) {
            case STRING:
                printf("%s\n", (char*)stack->array[i]);
                break;
            case CHAR:
                printf("%c\n", *(char*)stack->array[i]);
                break;
            case U_CHAR:
                printf("%u\n", *(unsigned char*)stack->array[i]);
                break;
            case BOOL:
                printf("%s\n", (*(bool*)stack->array[i]) ? "true" : "false");
                break;
            case SHORT:
                printf("%hd\n", *(short*)stack->array[i]);
                break;
            case U_SHORT:
                printf("%hu\n", *(unsigned short*)stack->array[i]);
                break;
            case INT:
                printf("%d\n", *(int*)stack->array[i]);
                break;
            case U_INT:
                printf("%u\n", *(unsigned int*)stack->array[i]);
                break;
            case LONG:
                printf("%ld\n", *(long*)stack->array[i]);
                break;
            case U_LONG:
                printf("%lu\n", *(unsigned long*)stack->array[i]);
                break;
            case LONG_LONG:
                printf("%lld\n", *(long long*)stack->array[i]);
                break;
            case U_LONG_LONG:
                printf("%llu\n", *(unsigned long long*)stack->array[i]);
                break;
            case FLOAT:
                printf("%f\n", *(float*)stack->array[i]);
                break;
            case DOUBLE:
                printf("%lf\n", *(double*)stack->array[i]);
                break;
            case LONG_DOUBLE:
                printf("%Lf\n", *(long double*)stack->array[i]);
                break;
            case POINTER:
                printf("%p\n", *(void**)stack->array[i]);
                break;
            case VOID:
                printf("%p\n", stack->array[i]);
                break;
            case STRUCT:
                custom_print_func(stack->array[i]);
                break;
            default:
                PRINT_ERROR("Unsupported Data Type");
                return;
        }
    }
}

