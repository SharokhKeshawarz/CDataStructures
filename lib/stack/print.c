#include "../include/stack.h"

void stack_print(void* value, stack_t type, void (*custom_print_func)(void*)) {
    if (value == NULL) {
        printf("NULL\n");
        return;
    }

    switch (type) {
        case STRING:
            printf("%s\n", (char*)value);
            break;
        case CHAR:
            printf("%c\n", DEREF_VOID_PTR(value, char));
            break;
        case UCHAR:
            printf("%u\n", DEREF_VOID_PTR(value, unsigned char));
            break;
        case BOOL:
            printf("%s\n", DEREF_VOID_PTR(value, bool) ? "true" : "false");
            break;
        case SHORT:
            printf("%hd\n", DEREF_VOID_PTR(value, short));
            break;
        case USHORT:
            printf("%hu\n", DEREF_VOID_PTR(value, unsigned short));
            break;
        case INT:
            printf("%d\n", DEREF_VOID_PTR(value, int));
            break;
        case UINT:
            printf("%u\n", DEREF_VOID_PTR(value, unsigned int));
            break;
        case LONG:
            printf("%ld\n", DEREF_VOID_PTR(value, long));
            break;
        case ULONG:
            printf("%lu\n", DEREF_VOID_PTR(value, unsigned long));
            break;
        case LONG_LONG:
            printf("%lld\n", DEREF_VOID_PTR(value, long long));
            break;
        case ULONG_LONG:
            printf("%llu\n", DEREF_VOID_PTR(value, unsigned long long));
            break;
        case FLOAT:
            printf("%f\n", DEREF_VOID_PTR(value, float));
            break;
        case DOUBLE:
            printf("%lf\n", DEREF_VOID_PTR(value, double));
            break;
        case LONG_DOUBLE:
            printf("%Lf\n", DEREF_VOID_PTR(value, long double));
            break;
        case POINTER:
            printf("%p\n", DEREF_VOID_PTR(value, void*));
            break;
        case ENUM:
            printf("%d\n", DEREF_VOID_PTR(value, int));
            break;
        case STRUCT:
            if (custom_print_func) custom_print_func(value);
            else printf("Custom print function is NULL for struct\n");
            break;
        case UNION:
            if (custom_print_func) custom_print_func(value);
            else printf("Custom print function is NULL for union\n");
            break;
        default:
            printf("Unsupported Data Type\n");
            return;
    }
}


void stack_print_all(stack_s* stack, void (*custom_print_func)(void*))
{
    if (stack == NULL) {
        PRINT_ERROR("Cannot Print An Uninitialized Stack");
        return;
    }

    for (size_t i = 0; i < stack->size; i++)
        stack_print(stack->array[i], stack->type, custom_print_func);
}
