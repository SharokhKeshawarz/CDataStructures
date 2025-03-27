#include "../lib/include/stack.h"

typedef enum {
    ENUM_VALUE_1 = 10,
    ENUM_VALUE_2 = 20,
    ENUM_VALUE_3 = 30
} enum_t;

void test_enum_stack_push()
{
    PRINT_INFO("STACK PUSH");

    stack_s* stack = stack_create(1, ENUM);

    enum_t value_1 = ENUM_VALUE_1;
    enum_t value_2 = ENUM_VALUE_2;

    stack_push(stack, &value_1, STACK_SIZE_ZERO);
    stack_push(stack, &value_2, STACK_SIZE_ZERO);

    stack_print_all(stack, NULL);

    stack_destroy(stack);
}

void test_enum_stack_pop()
{
    PRINT_INFO("STACK POP");

    stack_s* stack = stack_create(1, ENUM);

    enum_t value_1 = ENUM_VALUE_1;
    enum_t value_2 = ENUM_VALUE_2;

    stack_push(stack, &value_1, STACK_SIZE_ZERO);
    stack_push(stack, &value_2, STACK_SIZE_ZERO);

    stack_print_all(stack, NULL);

    stack_pop(stack);

    stack_print_all(stack, NULL);

    stack_destroy(stack);
}

void test_enum_stack_is_empty()
{
    PRINT_INFO("STACK EMPTY");

    stack_s* stack = stack_create(1, ENUM);

    enum_t value_1 = ENUM_VALUE_1;
    enum_t value_2 = ENUM_VALUE_2;

    stack_push(stack, &value_1, STACK_SIZE_ZERO);
    stack_push(stack, &value_2, STACK_SIZE_ZERO);

    printf("%d\n", stack_is_empty(stack));

    stack_pop(stack);
    stack_pop(stack);
    
    printf("%d\n", stack_is_empty(stack));

    stack_destroy(stack);
}

void test_enum_stack_assignment()
{
    PRINT_INFO("STACK ASSIGNMENT");

    stack_s* stack = stack_create(1, ENUM);

    enum_t value_1 = ENUM_VALUE_1;
    enum_t value_2 = ENUM_VALUE_2;
    enum_t value_3 = ENUM_VALUE_3;

    stack_push(stack, &value_1, STACK_SIZE_ZERO);
    stack_push(stack, &value_2, STACK_SIZE_ZERO);
    stack_push(stack, &value_3, STACK_SIZE_ZERO);

    enum_t value_A = *(enum_t*)stack->array[0];
    enum_t value_B = DEREF_VOID_PTR(stack->array[1], enum_t);

    printf("Value A (bottom): %d\n", value_A);
    printf("Value B (top): %d\n", value_B);

    stack_destroy(stack);
}

void test_enum_stack_print_all()
{
    PRINT_INFO("PRINTS ALL ELEMENTS OF THE STACK");

    stack_s* stack = stack_create(1, ENUM);

    enum_t value_1 = ENUM_VALUE_1;
    enum_t value_2 = ENUM_VALUE_2;

    stack_push(stack, &value_1, STACK_SIZE_ZERO);
    stack_push(stack, &value_2, STACK_SIZE_ZERO);

    stack_print_all(stack, NULL);

    stack_destroy(stack);
}

void test_enum_stack_print_single()
{
    PRINT_INFO("PRINTS SINGLE ELEMENT OF THE STACK");

    stack_s* stack = stack_create(1, ENUM);

    enum_t value_1 = ENUM_VALUE_1;
    enum_t value_2 = ENUM_VALUE_2;

    stack_push(stack, &value_1, STACK_SIZE_ZERO);
    stack_push(stack, &value_2, STACK_SIZE_ZERO);

    printf("Raw void* data\n");
    printf("%d\n", *(enum_t*)stack->array[0]);
    printf("%d\n", *(enum_t*)stack->array[1]);

    printf("Using macro directly\n");
    printf("%d\n", DEREF_VOID_PTR(stack->array[0], enum_t));
    printf("%d\n", DEREF_VOID_PTR(stack->array[1], enum_t));

    stack_destroy(stack);
}

void test_enum_stack_get_bottom()
{
    PRINT_INFO("GET BOTTOM ELEMENT");

    stack_s* stack = stack_create(1, ENUM);

    enum_t value_1 = ENUM_VALUE_1;
    enum_t value_2 = ENUM_VALUE_2;

    stack_push(stack, &value_1, STACK_SIZE_ZERO);
    stack_push(stack, &value_2, STACK_SIZE_ZERO);

    void* x = stack_get_bottom(stack);
    stack_print(x, ENUM, NULL);
    stack_destroy(stack);
}

void test_enum_stack_get_top()
{
    PRINT_INFO("GET TOP ELEMENT");

    stack_s* stack = stack_create(1, ENUM);

    enum_t value_1 = ENUM_VALUE_1;
    enum_t value_2 = ENUM_VALUE_2;

    stack_push(stack, &value_1, STACK_SIZE_ZERO);
    stack_push(stack, &value_2, STACK_SIZE_ZERO);

    void* x = stack_get_top(stack);
    stack_print(x, ENUM, NULL);
    stack_destroy(stack);
}

void test_enum_stack_get_data_from_index()
{
    PRINT_INFO("GET DATA FROM INDEX");

    stack_s* stack = stack_create(1, ENUM);

    enum_t value_1 = ENUM_VALUE_1;
    enum_t value_2 = ENUM_VALUE_2;

    stack_push(stack, &value_1, STACK_SIZE_ZERO);
    stack_push(stack, &value_2, STACK_SIZE_ZERO);

    void* x = stack_get_data(stack, 1);
    stack_print(x, ENUM, NULL);

    stack_destroy(stack);
}

void test_enum_stack_get_index_from_data()
{
    PRINT_INFO("GET INDEX FROM DATA");

    stack_s* stack = stack_create(1, ENUM);

    enum_t value_1 = ENUM_VALUE_1;
    enum_t value_2 = ENUM_VALUE_2;

    stack_push(stack, &value_1, STACK_SIZE_ZERO);
    stack_push(stack, &value_2, STACK_SIZE_ZERO);

    size_t x = stack_get_index(stack, stack_get_data(stack, 0), NULL);
    size_t y = stack_get_index(stack, stack->array[0], NULL);

    printf("%lu\n", x);
    printf("%lu\n", y);

    stack_destroy(stack);
}

void test_enum_stack_deref_void_ptr()
{
    PRINT_INFO("DEREFERENCE VOID POINTER USING MACRO FOR CLEAN CODE");

    stack_s* stack = stack_create(1, ENUM);

    enum_t value_1 = ENUM_VALUE_1;
    enum_t value_2 = ENUM_VALUE_2;

    stack_push(stack, &value_1, STACK_SIZE_ZERO);
    stack_push(stack, &value_2, STACK_SIZE_ZERO);

    enum_t x = DEREF_VOID_PTR(stack_get_bottom(stack), enum_t);
    enum_t y = DEREF_VOID_PTR(stack->array[1], enum_t);

    printf("%d\n", x);
    printf("%d\n", y);

    stack_destroy(stack);
}
