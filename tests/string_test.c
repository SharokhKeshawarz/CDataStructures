#include "../lib/include/stack.h"

void test_string_stack_push()
{
    PRINT_INFO("STACK PUSH");
    stack_s* stack = stack_create(1, STRING);

    char* value_1 = "world!";
    char* value_2 = "Hello";

    stack_push(stack, value_1, sizeof(value_1));
    stack_push(stack, value_2, strlen(value_2));

    stack_print_all(stack, NULL);

    stack_destroy(stack);
}

void test_string_stack_pop()
{
    PRINT_INFO("STACK POP");

    stack_s* stack = stack_create(1, STRING);
    
    char* value_1 = "world!";
    char* value_2 = "Hello";

    stack_push(stack, value_1, sizeof(value_1));
    stack_push(stack, value_2, strlen(value_2));

    stack_print_all(stack, NULL);

    stack_pop(stack);

    stack_print_all(stack, NULL);

    stack_destroy(stack);
}

void test_string_stack_is_empty()
{
    PRINT_INFO("STACK EMPTY");

    stack_s* stack = stack_create(1, STRING);
    
    char* value_1 = "world!";
    char* value_2 = "Hello";

    stack_push(stack, value_1, sizeof(value_1));
    stack_push(stack, value_2, strlen(value_2));

    printf("%d\n", stack_is_empty(stack));

    stack_pop(stack);
    stack_pop(stack);

    printf("%d\n", stack_is_empty(stack));

    stack_destroy(stack);
}

void test_string_stack_assigment()
{
    PRINT_INFO("STACK ASSIGMENT");

    stack_s* stack = stack_create(1, STRING);
    
    char* value_1 = "world!";
    char* value_2 = "Hello";

    stack_push(stack, value_1, sizeof(value_1));
    stack_push(stack, value_2, strlen(value_2));

    char* value_A = (char*)stack->array[0];
    char* value_B = DEREF_VOID_PTR_STRING(stack->array[1], char*);

    printf("Value A (bottom): %s\n", value_A);
    printf("Value B (top): %s\n", value_B);

    stack_destroy(stack);
}

void test_string_stack_print_all()
{
    PRINT_INFO("PRINTS ALL ELEMENTS OF THE STACK");

    stack_s* stack = stack_create(1, STRING);
    
    char* value_1 = "world!";
    char* value_2 = "Hello";

    stack_push(stack, value_1, sizeof(value_1));
    stack_push(stack, value_2, strlen(value_2));

    stack_print_all(stack, NULL);

    stack_destroy(stack);
}

void test_string_stack_print_single()
{
    PRINT_INFO("PRINTS SINGLE ELEMENT OF THE STACK");

    stack_s* stack = stack_create(1, STRING);
    
    char* value_1 = "world!";
    char* value_2 = "Hello";

    stack_push(stack, value_1, sizeof(value_1));
    stack_push(stack, value_2, strlen(value_2));

    printf("Raw void* data\n");
    printf("%s\n", (char*)stack->array[0]);
    printf("%s\n", (char*)stack->array[1]);

    printf("Using macro directly\n");
    printf("%s\n", DEREF_VOID_PTR_STRING(stack->array[0], char*));
    printf("%s\n", DEREF_VOID_PTR_STRING(stack->array[1], char*));

    stack_destroy(stack);
}

void test_string_stack_get_bottom()
{
    PRINT_INFO("GET BOTTOM ELEMENT");

    stack_s* stack = stack_create(1, STRING);
    
    char* value_1 = "world!";
    char* value_2 = "Hello";

    stack_push(stack, value_1, sizeof(value_1));
    stack_push(stack, value_2, strlen(value_2));

    void* x = stack_get_bottom(stack);
    stack_print(x, STRING, NULL);

    stack_destroy(stack);
}

void test_string_stack_get_top()
{
    PRINT_INFO("GET TOP ELEMENT");

    stack_s* stack = stack_create(1, STRING);
    
    char* value_1 = "world!";
    char* value_2 = "Hello";

    stack_push(stack, value_1, sizeof(value_1));
    stack_push(stack, value_2, strlen(value_2));

    void* x = stack_get_top(stack);
    stack_print(x, STRING, NULL);

    stack_destroy(stack);
}

void test_string_stack_get_data_from_index()
{
    PRINT_INFO("GET DATA FROM INDEX");

    stack_s* stack = stack_create(1, STRING);
    
    char* value_1 = "world!";
    char* value_2 = "Hello";

    stack_push(stack, value_1, sizeof(value_1));
    stack_push(stack, value_2, strlen(value_2));

    void* x = stack_get_data(stack, 1);
    stack_print(x, STRING, NULL);

    stack_destroy(stack);
}

void test_string_stack_get_index_from_data()
{
    PRINT_INFO("GET DATA FROM INDEX");

    stack_s* stack = stack_create(1, STRING);
    
    char* value_1 = "world!";
    char* value_2 = "Hello";

    stack_push(stack, value_1, sizeof(value_1));
    stack_push(stack, value_2, strlen(value_2));

    size_t x = stack_get_index(stack, stack_get_data(stack, 0), NULL);
    size_t y = stack_get_index(stack, stack->array[0], NULL);
    
    printf("%lu\n", x);
    printf("%lu\n", y);

    stack_destroy(stack);
}

void test_string_stack_derf_void_ptr()
{
    PRINT_INFO("DERFERENCE VOID POINTER USING MACRO GOOD FOR CLEAN CODE");

    stack_s* stack = stack_create(1, STRING);
    
    char* value_1 = "world!";
    char* value_2 = "Hello";

    stack_push(stack, value_1, sizeof(value_1));
    stack_push(stack, value_2, strlen(value_2));

    char* x = DEREF_VOID_PTR_STRING(stack_get_bottom(stack), char*);
    char* y = DEREF_VOID_PTR_STRING(stack->array[1], char*);

    printf("%s\n", x);
    printf("%s\n", y);

    stack_destroy(stack);
}
