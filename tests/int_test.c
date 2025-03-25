#include "../lib/include/stack.h"

void test_int_stack_push()
{
    PRINT_INFO("STACK PUSH");

    stack_s* stack = stack_create(1, INT);

    int value_1 = 10;
    int value_2 = 20;

    stack_push(stack, &value_1, STACK_SIZE_ZERO);
    stack_push(stack, &value_2, STACK_SIZE_ZERO);

    stack_print_all(stack, NULL);

    stack_destroy(stack);
}

void test_int_stack_pop()
{
    PRINT_INFO("STACK POP");

    stack_s* stack = stack_create(1, INT);

    int value_1 = 10;
    int value_2 = 20;

    stack_push(stack, &value_1, STACK_SIZE_ZERO);
    stack_push(stack, &value_2, STACK_SIZE_ZERO);

    stack_print_all(stack, NULL);

    stack_pop(stack);

    stack_print_all(stack, NULL);

    stack_destroy(stack);
}

void test_int_stack_is_empty()
{
    PRINT_INFO("STACK PUSH");

    stack_s* stack = stack_create(1, INT);

    int value_1 = 10;
    int value_2 = 20;

    stack_push(stack, &value_1, STACK_SIZE_ZERO);
    stack_push(stack, &value_2, STACK_SIZE_ZERO);

    printf("%d\n", stack_is_empty(stack));

    stack_pop(stack);
    stack_pop(stack);
    
    printf("%d\n", stack_is_empty(stack));

    stack_destroy(stack);
}

void test_int_stack_assigment()
{
    PRINT_INFO("STACK ASSIGNMENT");

    stack_s* stack = stack_create(1, INT);

    int value_1 = 10;
    int value_2 = 20;
    int value_3 = 30;

    stack_push(stack, &value_1, STACK_SIZE_ZERO);
    stack_push(stack, &value_2, STACK_SIZE_ZERO);
    stack_push(stack, &value_3, STACK_SIZE_ZERO);

    int value_A = *(int*)stack->array[0];
    // OR
    int value_b = DEREF_VOID_PTR(stack->array[1], int);

    printf("Value A (bottom): %d\n", value_A);
    printf("Value B (top): %d\n", value_b);

    stack_destroy(stack);
}

void test_int_stack_print_all()
{
    PRINT_INFO("PRINTS ALL ELEMENTS OF THE STACK");

    stack_s* stack = stack_create(1, INT);

    int value_1 = 10;
    int value_2 = 20;

    stack_push(stack, &value_1, STACK_SIZE_ZERO);
    stack_push(stack, &value_2, STACK_SIZE_ZERO);

    stack_print_all(stack, NULL);

    stack_destroy(stack);
}

void test_int_stack_print_single()
{
    PRINT_INFO("PRINTS SINGLE ELEMENT OF THE STACK");

    stack_s* stack = stack_create(1, INT);

    int value_1 = 10;
    int value_2 = 20;

    stack_push(stack, &value_1, STACK_SIZE_ZERO);
    stack_push(stack, &value_2, STACK_SIZE_ZERO);

    printf("Raw void* data\n");
    printf("%d\n", *(int*)stack->array[0]);
    printf("%d\n", *(int*)stack->array[1]);

    printf("Using macro directly\n");
    printf("%d\n", DEREF_VOID_PTR(stack->array[0], int));
    printf("%d\n", DEREF_VOID_PTR(stack->array[1], int));

    stack_destroy(stack);
}

void test_int_stack_get_bottom()
{
    PRINT_INFO("GET BOTTOM ELEMENT");

    stack_s* stack = stack_create(1, INT);

    int value_1 = 10;
    int value_2 = 20;

    stack_push(stack, &value_1, STACK_SIZE_ZERO);
    stack_push(stack, &value_2, STACK_SIZE_ZERO);

    void* x = stack_get_bottom(stack);
    stack_print(x, INT, NULL);
    stack_destroy(stack);
}

void test_int_stack_get_top()
{
    PRINT_INFO("GET TOP ELEMENT");

    stack_s* stack = stack_create(1, INT);

    int value_1 = 10;
    int value_2 = 20;

    stack_push(stack, &value_1, STACK_SIZE_ZERO);
    stack_push(stack, &value_2, STACK_SIZE_ZERO);

    void* x = stack_get_top(stack);
    stack_print(x, INT, NULL);
    stack_destroy(stack);
}

void test_int_stack_get_data_from_index()
{
    PRINT_INFO("GET DATA FROM INDEX");

    stack_s* stack = stack_create(1, INT);

    int value_1 = 10;
    int value_2 = 20;

    stack_push(stack, &value_1, STACK_SIZE_ZERO);
    stack_push(stack, &value_2, STACK_SIZE_ZERO);

    void* x = stack_get_data(stack, 1);
    stack_print(x, INT, NULL);

    stack_destroy(stack);
}

void test_int_stack_get_index_from_data()
{
    PRINT_INFO("GET INDEX FROM DATA");

    stack_s* stack = stack_create(1, INT);

    int value_1 = 10;
    int value_2 = 20;

    stack_push(stack, &value_1, STACK_SIZE_ZERO);
    stack_push(stack, &value_2, STACK_SIZE_ZERO);

    size_t x = stack_get_index(stack, stack_get_data(stack, 0), NULL);
    // OR
    size_t y = stack_get_index(stack, stack->array[0], NULL);

    printf("%ld\n", x);
    printf("%ld\n", y);

    stack_destroy(stack);
}

void test_int_stack_derf_void_ptr()
{
    PRINT_INFO("DERFERENCE VOID POINTER USING MACRO GOOD FOR CLEAN CODE");

    stack_s* stack = stack_create(1, INT);

    int value_1 = 10;
    int value_2 = 20;

    stack_push(stack, &value_1, STACK_SIZE_ZERO);
    stack_push(stack, &value_2, STACK_SIZE_ZERO);

    int x = DEREF_VOID_PTR(stack_get_bottom(stack), int);
    int y = DEREF_VOID_PTR(stack->array[1], int);

    printf("%d\n", x);
    printf("%d\n", y);

    stack_destroy(stack);
}
