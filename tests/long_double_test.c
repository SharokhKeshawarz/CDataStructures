#include "../lib/include/stack.h"

void test_long_double_stack_push()
{
    PRINT_INFO("STACK PUSH");

    stack_s* stack = stack_create(1, LONG_DOUBLE);

    long double value_1 = 10.5L;
    long double value_2 = 20.75L;

    stack_push(stack, &value_1, STACK_SIZE_ZERO);
    stack_push(stack, &value_2, STACK_SIZE_ZERO);

    stack_print_all(stack, NULL);

    stack_destroy(stack);
}

void test_long_double_stack_pop()
{
    PRINT_INFO("STACK POP");

    stack_s* stack = stack_create(1, LONG_DOUBLE);

    long double value_1 = 10.5L;
    long double value_2 = 20.75L;

    stack_push(stack, &value_1, STACK_SIZE_ZERO);
    stack_push(stack, &value_2, STACK_SIZE_ZERO);

    stack_print_all(stack, NULL);

    stack_pop(stack);

    stack_print_all(stack, NULL);

    stack_destroy(stack);
}

void test_long_double_stack_is_empty()
{
    PRINT_INFO("STACK PUSH");

    stack_s* stack = stack_create(1, LONG_DOUBLE);

    long double value_1 = 10.5L;
    long double value_2 = 20.75L;

    stack_push(stack, &value_1, STACK_SIZE_ZERO);
    stack_push(stack, &value_2, STACK_SIZE_ZERO);

    printf("%d\n", stack_is_empty(stack));

    stack_pop(stack);
    stack_pop(stack);
    
    printf("%d\n", stack_is_empty(stack));

    stack_destroy(stack);
}

void test_long_double_stack_assigment()
{
    PRINT_INFO("STACK ASSIGNMENT");

    stack_s* stack = stack_create(1, LONG_DOUBLE);

    long double value_1 = 10.5L;
    long double value_2 = 20.75L;
    long double value_3 = 30.25L;

    stack_push(stack, &value_1, STACK_SIZE_ZERO);
    stack_push(stack, &value_2, STACK_SIZE_ZERO);
    stack_push(stack, &value_3, STACK_SIZE_ZERO);

    long double value_A = *(long double*)stack->array[0];
    long double value_b = DEREF_VOID_PTR(stack->array[1], long double);

    printf("Value A (bottom): %Lf\n", value_A);
    printf("Value B (top): %Lf\n", value_b);

    stack_destroy(stack);
}

void test_long_double_stack_print_all()
{
    PRINT_INFO("PRINTS ALL ELEMENTS OF THE STACK");

    stack_s* stack = stack_create(1, LONG_DOUBLE);

    long double value_1 = 10.5L;
    long double value_2 = 20.75L;

    stack_push(stack, &value_1, STACK_SIZE_ZERO);
    stack_push(stack, &value_2, STACK_SIZE_ZERO);

    stack_print_all(stack, NULL);

    stack_destroy(stack);
}

void test_long_double_stack_print_single()
{
    PRINT_INFO("PRINTS SINGLE ELEMENT OF THE STACK");

    stack_s* stack = stack_create(1, LONG_DOUBLE);

    long double value_1 = 10.5L;
    long double value_2 = 20.75L;

    stack_push(stack, &value_1, STACK_SIZE_ZERO);
    stack_push(stack, &value_2, STACK_SIZE_ZERO);

    printf("Raw void* data\n");
    printf("%Lf\n", *(long double*)stack->array[0]);
    printf("%Lf\n", *(long double*)stack->array[1]);

    printf("Using macro directly\n");
    printf("%Lf\n", DEREF_VOID_PTR(stack->array[0], long double));
    printf("%Lf\n", DEREF_VOID_PTR(stack->array[1], long double));

    stack_destroy(stack);
}

void test_long_double_stack_get_bottom()
{
    PRINT_INFO("GET BOTTOM ELEMENT");

    stack_s* stack = stack_create(1, LONG_DOUBLE);

    long double value_1 = 10.5L;
    long double value_2 = 20.75L;

    stack_push(stack, &value_1, STACK_SIZE_ZERO);
    stack_push(stack, &value_2, STACK_SIZE_ZERO);

    void* x = stack_get_bottom(stack);
    stack_print(x, LONG_DOUBLE, NULL);
    stack_destroy(stack);
}

void test_long_double_stack_get_top()
{
    PRINT_INFO("GET TOP ELEMENT");

    stack_s* stack = stack_create(1, LONG_DOUBLE);

    long double value_1 = 10.5L;
    long double value_2 = 20.75L;

    stack_push(stack, &value_1, STACK_SIZE_ZERO);
    stack_push(stack, &value_2, STACK_SIZE_ZERO);

    void* x = stack_get_top(stack);
    stack_print(x, LONG_DOUBLE, NULL);
    stack_destroy(stack);
}

void test_long_double_stack_get_data_from_index()
{
    PRINT_INFO("GET DATA FROM INDEX");

    stack_s* stack = stack_create(1, LONG_DOUBLE);

    long double value_1 = 10.5L;
    long double value_2 = 20.75L;

    stack_push(stack, &value_1, STACK_SIZE_ZERO);
    stack_push(stack, &value_2, STACK_SIZE_ZERO);

    void* x = stack_get_data(stack, 1);
    stack_print(x, LONG_DOUBLE, NULL);

    stack_destroy(stack);
}

void test_long_double_stack_get_index_from_data()
{
    PRINT_INFO("GET INDEX FROM DATA");

    stack_s* stack = stack_create(1, LONG_DOUBLE);

    long double value_1 = 10.5L;
    long double value_2 = 20.75L;

    stack_push(stack, &value_1, STACK_SIZE_ZERO);
    stack_push(stack, &value_2, STACK_SIZE_ZERO);

    size_t x = stack_get_index(stack, stack_get_data(stack, 0), NULL);
    size_t y = stack_get_index(stack, stack->array[0], NULL);

    printf("%lu\n", x);
    printf("%lu\n", y);

    stack_destroy(stack);
}

void test_long_double_stack_derf_void_ptr()
{
    PRINT_INFO("DERFERENCE VOID POINTER USING MACRO GOOD FOR CLEAN CODE");

    stack_s* stack = stack_create(1, LONG_DOUBLE);

    long double value_1 = 10;
    long double value_2 = 20;

    stack_push(stack, &value_1, STACK_SIZE_ZERO);
    stack_push(stack, &value_2, STACK_SIZE_ZERO);

    long double x = DEREF_VOID_PTR(stack_get_bottom(stack), long double);
    long double y = DEREF_VOID_PTR(stack->array[1], long double);

    printf("%Lf\n", x);
    printf("%Lf\n", y);

    stack_destroy(stack);
}

