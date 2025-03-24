#include "../lib/include/stack.h"

/*
*** This works the same with all primitive data types:
- BOOL    %d (1 or 0) || %s ("true" or "false")
- CHAR    %c
- UCHAR   %u
- SHORT   %hd
- USHORT  %hu
- INT     %d
- UINT    %u
- LONG    %ld
- ULONG   %lu
- LONG_LONG   %lld
- ULONG_LONG   %llu
- FLOAT   %f
- DOUBLE  %lf
- LONG_DOUBLE   %Lf

*** In this example, CHAR data type is used, so the format specifier is %c.
*/

/////////////////////////////////////////////////////////////////////////////////////////////////////
/* 
    Function: test_char_stack_push
    Description:
        - Pushes elements onto the stack.
        - Demonstrates how to use stack_push to add elements.
        - Displays the LIFO (Last In, First Out) behavior of the stack.
        - After pushing 'A' and 'b', the stack will print in reverse order: b, A.
*/
void test_char_stack_push()
{
    PRINT_INFO("STACK PUSH");

    // Create a stack with space for CHAR type data
    stack_s* stack = stack_create(1, CHAR);

    char value_1 = 'A';
    char value_2 = 'b';

    // Push two characters onto the stack
    stack_push(stack, &value_1, STACK_SIZE_ZERO);  // Pushed A
    stack_push(stack, &value_2, STACK_SIZE_ZERO);  // Pushed b

    // Print all stack elements, expected output: b, A
    stack_print_all(stack, NULL);

    // Clean up the stack
    stack_destroy(stack);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
/* 
    Function: test_char_stack_pop
    Description:
        - Pops elements from the stack.
        - After pushing 'A' and 'b', it pops the top element and shows the updated stack.
        - Demonstrates that the last element pushed is the first to be popped.
*/
void test_char_stack_pop()
{
    PRINT_INFO("STACK POP");

    // Create a stack for CHAR type data
    stack_s* stack = stack_create(1, CHAR);

    char value_1 = 'A';
    char value_2 = 'b';

    // Push elements onto the stack
    stack_push(stack, &value_1, STACK_SIZE_ZERO);
    stack_push(stack, &value_2, STACK_SIZE_ZERO);

    // Print the stack before popping, expected output: stack: b, A
    stack_print_all(stack, NULL);

    // Pop the top element (b) off the stack
    stack_pop(stack);

    // Print the stack after popping, expected output: stack: A
    stack_print_all(stack, NULL);

    // Clean up the stack
    stack_destroy(stack);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
/* 
    Function: test_char_stack_assigment
    Description:
        - Demonstrates how to access and assign values from the stack to variables.
        - Shows two methods of dereferencing void pointers and extracting `char` values.
*/
void test_char_stack_assigment()
{
    PRINT_INFO("STACK ASSIGNMENT");

    // Create a stack for CHAR type data
    stack_s* stack = stack_create(1, CHAR);

    char value_1 = 'A';
    char value_2 = 'b';
    char value_3 = 'c';

    // Push elements onto the stack
    stack_push(stack, &value_1, STACK_SIZE_ZERO);
    stack_push(stack, &value_2, STACK_SIZE_ZERO);
    stack_push(stack, &value_3, STACK_SIZE_ZERO);

    // Method 1: Dereference the void pointer to access the value directly
    // Access the first element in the stack (bottom element) and dereference it to char
    char value_A = *(char*)stack->array[0]; // Correct dereferencing (pointer to char)

    // Method 2: Using macro to dereference and assign to a variable
    // Dereference using the macro for readability and clarity
    char value_b = DEREF_VOID_PTR(stack->array[1], char); // Access the second element in the stack (top element)

    // Debugging: Print out the dereferenced values
    printf("Value A (bottom): %c\n", value_A);  // Expected output: 'A'
    printf("Value B (top): %c\n", value_b);    // Expected output: 'b'

    // Clean up the stack
    stack_destroy(stack);
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
/* 
    Function: test_char_stack_print_all
    Description:
        - Prints all elements in the stack.
        - Displays all elements in LIFO order, starting from the top (most recently pushed).
*/
void test_char_stack_print_all()
{
    PRINT_INFO("PRINTS ALL ELEMENTS OF THE STACK");

    // Create a stack for CHAR type data
    stack_s* stack = stack_create(1, CHAR);

    char value_1 = 'A';
    char value_2 = 'b';

    // Push elements onto the stack
    stack_push(stack, &value_1, STACK_SIZE_ZERO);
    stack_push(stack, &value_2, STACK_SIZE_ZERO);

    // Print all stack elements, expected output: b, A
    stack_print_all(stack, NULL);

    // Clean up the stack
    stack_destroy(stack);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
/* 
    Function: test_char_stack_print_single
    Description:
        - Demonstrates various ways to print individual elements from the stack.
        - Shows direct dereferencing, macro dereferencing, and stack_print function usage.
*/
void test_char_stack_print_single()
{
    PRINT_INFO("PRINTS SINGLE ELEMENT OF THE STACK");

    // Create a stack for CHAR type data
    stack_s* stack = stack_create(1, CHAR);

    char value_1 = 'A';
    char value_2 = 'b';

    // Push elements onto the stack
    stack_push(stack, &value_1, STACK_SIZE_ZERO);
    stack_push(stack, &value_2, STACK_SIZE_ZERO);

    // Print using raw dereferencing
    printf("Raw void* data\n");
    printf("%c\n", *(char*)stack->array[0]); // A
    printf("%c\n", *(char*)stack->array[1]); // b

    // Print using macro dereferencing
    printf("Using macro directly\n");
    printf("%c\n", DEREF_VOID_PTR(stack->array[0], char)); // A
    printf("%c\n", DEREF_VOID_PTR(stack->array[1], char)); // b

    // Assign to a variable before printing
    printf("Using macro by first assigning to a variable\n");
    char value_1_A = DEREF_VOID_PTR(stack->array[0], char); // A
    char value_1_b = DEREF_VOID_PTR(stack->array[0], char); // b
    printf("%c\n", value_1_A); // A
    printf("%c\n", value_1_b); // b

    // Use stack_print to display individual elements
    printf("Using stack_print function\n");
    stack_print(stack->array[0], CHAR, NULL); // A
    stack_print(stack->array[1], CHAR, NULL); // B

    // Clean up the stack
    stack_destroy(stack);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
/* 
    Function: test_char_stack_get_bottom
    Description:
        - Retrieves the bottom element of the stack (the first element pushed).
        - Demonstrates how to use stack_get_bottom to access the earliest pushed item.
*/
void test_char_stack_get_bottom()
{
    PRINT_INFO("GET BOTTOM ELEMENT");

    // Create a stack for CHAR type data
    stack_s* stack = stack_create(1, CHAR);

    char value_1 = 'A';
    char value_2 = 'b';

    // Push elements onto the stack
    stack_push(stack, &value_1, STACK_SIZE_ZERO);
    stack_push(stack, &value_2, STACK_SIZE_ZERO);

    // Retrieve and print the bottom element (first pushed element)
    void* x = stack_get_bottom(stack); // Gets A
    stack_print(x, CHAR, NULL); // A
    // OR
    stack_print(stack_get_bottom(stack), CHAR, NULL); // A

    // Clean up the stack
    stack_destroy(stack);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
/* 
    Function: test_char_stack_get_top
    Description:
        - Retrieves the top element of the stack (the most recently pushed).
        - Demonstrates how to use stack_get_top to access the latest item.
*/
void test_char_stack_get_top()
{
    PRINT_INFO("GET TOP ELEMENT");

    // Create a stack for CHAR type data
    stack_s* stack = stack_create(1, CHAR);

    char value_1 = 'A';
    char value_2 = 'b';

    // Push elements onto the stack
    stack_push(stack, &value_1, STACK_SIZE_ZERO);
    stack_push(stack, &value_2, STACK_SIZE_ZERO);

    // Retrieve and print the top element (most recent element pushed)
    void* x = stack_get_top(stack); // Gets b
    stack_print(x, CHAR, NULL); // b
    // OR you can access it directly
    stack_print(stack_get_top(stack), CHAR, NULL); // b

    // Clean up the stack
    stack_destroy(stack);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
/* 
    Function: test_char_stack_get_data_from_index
    Description:
        - Retrieves stack data from a specific index.
        - Demonstrates how to use stack_get_data to access elements at any index.
*/
void test_char_stack_get_data_from_index()
{
    PRINT_INFO("GET DATA FROM INDEX");

    // Create a stack for CHAR type data
    stack_s* stack = stack_create(1, CHAR);

    char value_1 = 'A';
    char value_2 = 'b';

    // Push elements onto the stack
    stack_push(stack, &value_1, STACK_SIZE_ZERO);
    stack_push(stack, &value_2, STACK_SIZE_ZERO);

    // Retrieve data from a specific index (1 in this case)
    void* x = stack_get_data(stack, 1);
    stack_print(x, CHAR, NULL); // b

    // Clean up the stack
    stack_destroy(stack);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
/* 
    Function: test_char_stack_get_index_from_data
    Description:
        - Retrieves the index of a specific data element.
        - Demonstrates how to find the index of an element in the stack using stack_get_index.
*/
void test_char_stack_get_index_from_data()
{
    PRINT_INFO("GET INDEX FROM DATA");

    // Create a stack for CHAR type data
    stack_s* stack = stack_create(1, CHAR);

    char value_1 = 'A';
    char value_2 = 'b';

    // Push elements onto the stack
    stack_push(stack, &value_1, STACK_SIZE_ZERO);
    stack_push(stack, &value_2, STACK_SIZE_ZERO);

    // Retrieve the index of a specific data element
    size_t x = stack_get_index(stack, stack_get_data(stack, 0), NULL); // Gets index 0
    // Or use the array directly
    size_t y = stack_get_index(stack, stack->array[0], NULL); // Gets index 0

    // Print the indexes
    printf("%ld\n", x); // 0
    printf("%ld\n", y); // 0

    // Clean up the stack
    stack_destroy(stack);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
/* 
    Function: test_char_stack_derf_void_ptr
    Description:
        - Demonstrates the use of the DEREF_VOID_PTR macro for dereferencing void pointers.
        - Improves code readability by directly accessing values without explicit casting.
*/
void test_char_stack_derf_void_ptr()
{
    PRINT_INFO("DERFERENCE VOID POINTER USING MACRO GOOD FOR CLEAN CODE");

    // Create a stack for CHAR type data
    stack_s* stack = stack_create(1, CHAR);

    char value_1 = 'A';
    char value_2 = 'b';

    // Push elements onto the stack
    stack_push(stack, &value_1, STACK_SIZE_ZERO);
    stack_push(stack, &value_2, STACK_SIZE_ZERO);

    // Dereference using the macro for clean code
    char x = DEREF_VOID_PTR(stack_get_bottom(stack), char); // A
    char y = DEREF_VOID_PTR(stack->array[1], char); // b

    // Print the dereferenced values
    printf("%c\n", x); // A
    printf("%c\n", y); // b

    // Clean up the stack
    stack_destroy(stack);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
/*
    Main function:
        - Calls the test functions to demonstrate stack operations on the CHAR type data.
*/
int main()
{
    // Running all the test functions
    test_char_stack_push();
    test_char_stack_pop();
    test_char_stack_print_all();
    test_char_stack_print_single();
    test_char_stack_get_bottom();
    test_char_stack_get_top();
    test_char_stack_get_data_from_index();
    test_char_stack_get_index_from_data();
    test_char_stack_derf_void_ptr();

    return EXIT_SUCCESS;
}
