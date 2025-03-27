#include "../lib/include/stack.h"

void test_pointer_stack_push()
{
    PRINT_INFO("STACK PUSH");

    stack_s* stack = stack_create(1, POINTER);

    int value_1 = 32;
    int value_2 = 11;

    int* ptr_1 = &value_1;
    int* ptr_2 = &value_2;

    stack_push(stack, &ptr_1, sizeof(int*));
    stack_push(stack, &ptr_2, sizeof(int*));

    stack_print_all(stack, NULL);

    stack_destroy(stack);
}

void test_pointer_stack_pop()
{
    PRINT_INFO("STACK POP");

    stack_s* stack = stack_create(1, POINTER);

    int value_1 = 32;
    int value_2 = 11;

    int* ptr_1 = &value_1;
    int* ptr_2 = &value_2;

    stack_push(stack, &ptr_1, sizeof(int*));
    stack_push(stack, &ptr_2, sizeof(int*));

    stack_print_all(stack, NULL);

    stack_pop(stack);

    stack_print_all(stack, NULL);

    stack_destroy(stack);
}

void test_pointer_stack_is_empty()
{
    PRINT_INFO("STACK EMPTY");

    stack_s* stack = stack_create(1, POINTER);

    int value_1 = 32;
    int value_2 = 11;

    int* ptr_1 = &value_1;
    int* ptr_2 = &value_2;

    stack_push(stack, &ptr_1, sizeof(int*));
    stack_push(stack, &ptr_2, sizeof(int*));

    printf("%d\n", stack_is_empty(stack));

    stack_pop(stack);
    stack_pop(stack);

    printf("%d\n", stack_is_empty(stack));

    stack_destroy(stack);
}

void test_pointer_stack_assigment()
{
    PRINT_INFO("STACK ASSIGNMENT");

    stack_s* stack = stack_create(1, POINTER);

    int value_1 = 32;
    int value_2 = 11;

    int* ptr_1 = &value_1;
    int* ptr_2 = &value_2;

    stack_push(stack, &ptr_1, sizeof(int*));
    stack_push(stack, &ptr_2, sizeof(int*));

    int* value_A = ptr_1;
    int* value_B = ptr_2;

    printf("%p\n", value_A);
    printf("%p\n", value_B);

    stack_destroy(stack);
}

void test_pointer_stack_print_all()
{
    PRINT_INFO("PRINTS ALL ELEMENTS OF THE STACK");

    stack_s* stack = stack_create(1, POINTER);

    int value_1 = 32;
    int value_2 = 11;

    int* ptr_1 = &value_1;
    int* ptr_2 = &value_2;

    stack_push(stack, &ptr_1, sizeof(int*));
    stack_push(stack, &ptr_2, sizeof(int*));

    stack_print_all(stack, NULL);

    stack_destroy(stack);
}

void test_pointer_stack_print_single()
{
    PRINT_INFO("PRINTS SINGLE ELEMENT OF THE STACK");

    stack_s* stack = stack_create(1, POINTER);

    int value_1 = 32;
    int value_2 = 11;

    int* ptr_1 = &value_1;
    int* ptr_2 = &value_2;

    stack_push(stack, &ptr_1, sizeof(int*));
    stack_push(stack, &ptr_2, sizeof(int*));

    printf("Raw void* data\n");
    printf("%p\n", (int*)stack->array[0]);
    printf("%p\n", (int*)stack->array[1]);

    printf("Using macro directly\n");
    printf("%p\n", DEREF_VOID_PTR(stack->array[0], int*));
    printf("%p\n", DEREF_VOID_PTR(stack->array[1], int*));

    printf("Using macro by first assigning to a variable\n");
    int* value_1_A = DEREF_VOID_PTR(stack->array[0], int*);
    int* value_1_b = DEREF_VOID_PTR(stack->array[0], int*);
    printf("%p\n", value_1_A);
    printf("%p\n", value_1_b);

    printf("Using stack_print function\n");
    stack_print(stack->array[0], POINTER, NULL);
    stack_print(stack->array[1], POINTER, NULL);

    stack_destroy(stack);
}

void test_pointer_stack_get_bottom()
{
    PRINT_INFO("GET BOTTOM ELEMENT");

    stack_s* stack = stack_create(1, POINTER);

    int value_1 = 32;
    int value_2 = 11;

    int* ptr_1 = &value_1;
    int* ptr_2 = &value_2;

    stack_push(stack, &ptr_1, sizeof(int*));
    stack_push(stack, &ptr_2, sizeof(int*));

    void* x = stack_get_bottom(stack);
    stack_print(x, POINTER, NULL);
    stack_print(stack_get_bottom(stack), POINTER, NULL);

    stack_destroy(stack);
}

void test_pointer_stack_get_top()
{
    PRINT_INFO("GET TOP ELEMENT");

    stack_s* stack = stack_create(1, POINTER);

    int value_1 = 32;
    int value_2 = 11;

    int* ptr_1 = &value_1;
    int* ptr_2 = &value_2;

    stack_push(stack, &ptr_1, sizeof(int*));
    stack_push(stack, &ptr_2, sizeof(int*));

    void* x = stack_get_bottom(stack);
    stack_print(x, POINTER, NULL);
    stack_print(stack_get_bottom(stack), POINTER, NULL);

    stack_destroy(stack);
}

void test_pointer_stack_get_data_from_index()
{
    PRINT_INFO("GET DATA FROM INDEX");

    stack_s* stack = stack_create(1, POINTER);

    int value_1 = 32;
    int value_2 = 11;

    int* ptr_1 = &value_1;
    int* ptr_2 = &value_2;

    stack_push(stack, &ptr_1, sizeof(int*));
    stack_push(stack, &ptr_2, sizeof(int*));

    void* x = stack_get_data(stack, 1);
    stack_print(x, POINTER, NULL);

    stack_destroy(stack);
}

void test_pointer_stack_get_index_from_data()
{
    PRINT_INFO("GET DATA FROM INDEX");

    stack_s* stack = stack_create(1, POINTER);

    int value_1 = 32;
    int value_2 = 11;

    int* ptr_1 = &value_1;
    int* ptr_2 = &value_2;

    stack_push(stack, &ptr_1, sizeof(int*));
    stack_push(stack, &ptr_2, sizeof(int*));

    size_t x = stack_get_index(stack, stack_get_data(stack, 0), NULL);
    size_t y = stack_get_index(stack, stack->array[0], NULL);

    printf("%ld\n", x);
    printf("%ld\n", y);

    stack_destroy(stack);
}

void test_pointer_stack_derf_void_ptr()
{
    PRINT_INFO("DERFERENCE VOID POINTER USING MACRO GOOD FOR CLEAN CODE");

    stack_s* stack = stack_create(1, POINTER);

    int value_1 = 32;
    int value_2 = 11;

    int* ptr_1 = &value_1;
    int* ptr_2 = &value_2;

    stack_push(stack, &ptr_1, sizeof(int*));
    stack_push(stack, &ptr_2, sizeof(int*));

    int* x = DEREF_VOID_PTR(stack_get_bottom(stack), int*);
    int* y = DEREF_VOID_PTR(stack->array[0], int*);

    printf("%p\n", x);
    printf("%p\n", y);

    stack_destroy(stack);
}
