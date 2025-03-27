#include "../lib/include/stack.h"

void test_char_stack_push()
{
    PRINT_INFO("STACK PUSH");

    stack_s* stack = stack_create(1, CHAR);

    char value_1 = 'A';
    char value_2 = 'b';

    stack_push(stack, &value_1, STACK_SIZE_ZERO);
    stack_push(stack, &value_2, STACK_SIZE_ZERO);

    stack_print_all(stack, NULL);

    stack_destroy(stack);
}

void test_char_stack_pop()
{
    PRINT_INFO("STACK POP");

    stack_s* stack = stack_create(1, CHAR);

    char value_1 = 'A';
    char value_2 = 'b';

    stack_push(stack, &value_1, STACK_SIZE_ZERO);
    stack_push(stack, &value_2, STACK_SIZE_ZERO);

    stack_print_all(stack, NULL);

    stack_pop(stack);

    stack_print_all(stack, NULL);

    stack_destroy(stack);
}

void test_char_stack_is_empty()
{
    PRINT_INFO("STACK EMPTY");

    stack_s* stack = stack_create(1, CHAR);

    char value_1 = 'A';
    char value_2 = 'b';

    stack_push(stack, &value_1, STACK_SIZE_ZERO);
    stack_push(stack, &value_2, STACK_SIZE_ZERO);

    printf("%d\n", stack_is_empty(stack));

    stack_pop(stack);
    stack_pop(stack);
    
    printf("%d\n", stack_is_empty(stack));

    stack_destroy(stack);
}

void test_char_stack_assigment()
{
    PRINT_INFO("STACK ASSIGNMENT");

    stack_s* stack = stack_create(1, CHAR);

    char value_1 = 'A';
    char value_2 = 'b';
    char value_3 = 'c';

    stack_push(stack, &value_1, STACK_SIZE_ZERO);
    stack_push(stack, &value_2, STACK_SIZE_ZERO);
    stack_push(stack, &value_3, STACK_SIZE_ZERO);

    char value_A = *(char*)stack->array[0];

    char value_b = DEREF_VOID_PTR(stack->array[1], char);

    printf("Value A (bottom): %c\n", value_A);
    printf("Value B (top): %c\n", value_b);

    stack_destroy(stack);
}

void test_char_stack_print_all()
{
    PRINT_INFO("PRINTS ALL ELEMENTS OF THE STACK");

    stack_s* stack = stack_create(1, CHAR);

    char value_1 = 'A';
    char value_2 = 'b';

    stack_push(stack, &value_1, STACK_SIZE_ZERO);
    stack_push(stack, &value_2, STACK_SIZE_ZERO);

    stack_print_all(stack, NULL);

    stack_destroy(stack);
}

void test_char_stack_print_single()
{
    PRINT_INFO("PRINTS SINGLE ELEMENT OF THE STACK");

    stack_s* stack = stack_create(1, CHAR);

    char value_1 = 'A';
    char value_2 = 'b';

    stack_push(stack, &value_1, STACK_SIZE_ZERO);
    stack_push(stack, &value_2, STACK_SIZE_ZERO);

    printf("Raw void* data\n");
    printf("%c\n", *(char*)stack->array[0]);
    printf("%c\n", *(char*)stack->array[1]);

    printf("Using macro directly\n");
    printf("%c\n", DEREF_VOID_PTR(stack->array[0], char));
    printf("%c\n", DEREF_VOID_PTR(stack->array[1], char));

    printf("Using macro by first assigning to a variable\n");
    char value_1_A = DEREF_VOID_PTR(stack->array[0], char);
    char value_1_b = DEREF_VOID_PTR(stack->array[0], char);
    printf("%c\n", value_1_A);
    printf("%c\n", value_1_b);

    printf("Using stack_print function\n");
    stack_print(stack->array[0], CHAR, NULL);
    stack_print(stack->array[1], CHAR, NULL);

    stack_destroy(stack);
}

void test_char_stack_get_bottom()
{
    PRINT_INFO("GET BOTTOM ELEMENT");

    stack_s* stack = stack_create(1, CHAR);

    char value_1 = 'A';
    char value_2 = 'b';

    stack_push(stack, &value_1, STACK_SIZE_ZERO);
    stack_push(stack, &value_2, STACK_SIZE_ZERO);

    void* x = stack_get_bottom(stack);
    stack_print(x, CHAR, NULL);

    stack_print(stack_get_bottom(stack), CHAR, NULL);

    stack_destroy(stack);
}

void test_char_stack_get_top()
{
    PRINT_INFO("GET TOP ELEMENT");

    stack_s* stack = stack_create(1, CHAR);

    char value_1 = 'A';
    char value_2 = 'b';

    stack_push(stack, &value_1, STACK_SIZE_ZERO);
    stack_push(stack, &value_2, STACK_SIZE_ZERO);

    void* x = stack_get_top(stack);
    stack_print(x, CHAR, NULL);

    stack_print(stack_get_top(stack), CHAR, NULL);

    stack_destroy(stack);
}

void test_char_stack_get_data_from_index()
{
    PRINT_INFO("GET DATA FROM INDEX");

    stack_s* stack = stack_create(1, CHAR);

    char value_1 = 'A';
    char value_2 = 'b';

    stack_push(stack, &value_1, STACK_SIZE_ZERO);
    stack_push(stack, &value_2, STACK_SIZE_ZERO);

    void* x = stack_get_data(stack, 1);
    stack_print(x, CHAR, NULL);

    stack_destroy(stack);
}

void test_char_stack_get_index_from_data()
{
    PRINT_INFO("GET INDEX FROM DATA");

    stack_s* stack = stack_create(1, CHAR);

    char value_1 = 'A';
    char value_2 = 'b';

    stack_push(stack, &value_1, STACK_SIZE_ZERO);
    stack_push(stack, &value_2, STACK_SIZE_ZERO);

    size_t x = stack_get_index(stack, stack_get_data(stack, 0), NULL);

    size_t y = stack_get_index(stack, stack->array[0], NULL);

    printf("%ld\n", x);
    printf("%ld\n", y);

    stack_destroy(stack);
}

void test_char_stack_derf_void_ptr()
{
    PRINT_INFO("DERFERENCE VOID POINTER USING MACRO GOOD FOR CLEAN CODE");

    stack_s* stack = stack_create(1, CHAR);

    char value_1 = 'A';
    char value_2 = 'b';

    stack_push(stack, &value_1, STACK_SIZE_ZERO);
    stack_push(stack, &value_2, STACK_SIZE_ZERO);

    char x = DEREF_VOID_PTR(stack_get_bottom(stack), char);
    char y = DEREF_VOID_PTR(stack->array[1], char);

    printf("%c\n", x);
    printf("%c\n", y);

    stack_destroy(stack);
}

