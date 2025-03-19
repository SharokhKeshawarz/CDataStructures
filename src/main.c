#include "main.h"
#include "stack.h"

// Example Struct
typedef struct Person {
    char name[50];
    int age;
} Person;

void print_person(void* data) {
    Person* p = (Person*)data;
    printf("Person: %s, Age: %d\n", p->name, p->age);
}

int main(void)
{
    // Test for CHAR
    stack_s* charStack = init_stack(2, CHAR);
    char c1 = 'A', c2 = 'Z';
    push_stack(charStack, &c1, sizeof(char));
    push_stack(charStack, &c2, sizeof(char));
    print_stack(charStack, NULL);
    destroy_stack(charStack);

    // Test for U_CHAR
    stack_s* uCharStack = init_stack(2, U_CHAR);
    unsigned char uc1 = 65, uc2 = 90; // ASCII values for 'A' and 'Z'
    push_stack(uCharStack, &uc1, sizeof(unsigned char));
    push_stack(uCharStack, &uc2, sizeof(unsigned char));
    print_stack(uCharStack, NULL);
    destroy_stack(uCharStack);

    // Test for STRING
    stack_s* stringStack = init_stack(2, STRING);
    push_stack(stringStack, "Hello", 0);
    push_stack(stringStack, "World", 0);
    print_stack(stringStack, NULL);
    destroy_stack(stringStack);

    // Test for BOOL
    stack_s* boolStack = init_stack(2, BOOL);
    bool b1 = true, b2 = false;
    push_stack(boolStack, &b1, sizeof(bool));
    push_stack(boolStack, &b2, sizeof(bool));
    print_stack(boolStack, NULL);
    destroy_stack(boolStack);

    // Test for SHORT
    stack_s* shortStack = init_stack(2, SHORT);
    short s1 = 12345, s2 = -12345;
    push_stack(shortStack, &s1, sizeof(short));
    push_stack(shortStack, &s2, sizeof(short));
    print_stack(shortStack, NULL);
    destroy_stack(shortStack);

    // Test for U_SHORT
    stack_s* uShortStack = init_stack(2, U_SHORT);
    unsigned short us1 = 12345, us2 = 54321;
    push_stack(uShortStack, &us1, sizeof(unsigned short));
    push_stack(uShortStack, &us2, sizeof(unsigned short));
    print_stack(uShortStack, NULL);
    destroy_stack(uShortStack);

    // Test for INT
    stack_s* intStack = init_stack(2, INT);
    int num1 = 42, num2 = 99;
    push_stack(intStack, &num1, sizeof(int));
    push_stack(intStack, &num2, sizeof(int));
    print_stack(intStack, NULL);
    destroy_stack(intStack);

    // Test for U_INT
    stack_s* uIntStack = init_stack(2, U_INT);
    unsigned int uNum1 = 42, uNum2 = 99;
    push_stack(uIntStack, &uNum1, sizeof(unsigned int));
    push_stack(uIntStack, &uNum2, sizeof(unsigned int));
    print_stack(uIntStack, NULL);
    destroy_stack(uIntStack);

    // Test for LONG
    stack_s* longStack = init_stack(2, LONG);
    long l1 = 123456789L, l2 = -987654321L;
    push_stack(longStack, &l1, sizeof(long));
    push_stack(longStack, &l2, sizeof(long));
    print_stack(longStack, NULL);
    destroy_stack(longStack);

    // Test for U_LONG
    stack_s* uLongStack = init_stack(2, U_LONG);
    unsigned long ul1 = 123456789L, ul2 = 987654321L;
    push_stack(uLongStack, &ul1, sizeof(unsigned long));
    push_stack(uLongStack, &ul2, sizeof(unsigned long));
    print_stack(uLongStack, NULL);
    destroy_stack(uLongStack);

    // Test for LONG_LONG
    stack_s* longLongStack = init_stack(2, LONG_LONG);
    long long ll1 = 123456789123456LL, ll2 = -987654321987654LL;
    push_stack(longLongStack, &ll1, sizeof(long long));
    push_stack(longLongStack, &ll2, sizeof(long long));
    print_stack(longLongStack, NULL);
    destroy_stack(longLongStack);

    // Test for U_LONG_LONG
    stack_s* uLongLongStack = init_stack(2, U_LONG_LONG);
    unsigned long long ull1 = 123456789123456ULL, ull2 = 987654321987654ULL;
    push_stack(uLongLongStack, &ull1, sizeof(unsigned long long));
    push_stack(uLongLongStack, &ull2, sizeof(unsigned long long));
    print_stack(uLongLongStack, NULL);
    destroy_stack(uLongLongStack);

    // Test for FLOAT
    stack_s* floatStack = init_stack(2, FLOAT);
    float f1 = 3.14f, f2 = 2.71f;
    push_stack(floatStack, &f1, sizeof(float));
    push_stack(floatStack, &f2, sizeof(float));
    print_stack(floatStack, NULL);
    destroy_stack(floatStack);

    // Test for DOUBLE
    stack_s* doubleStack = init_stack(2, DOUBLE);
    double d1 = 3.14159, d2 = 2.71828;
    push_stack(doubleStack, &d1, sizeof(double));
    push_stack(doubleStack, &d2, sizeof(double));
    print_stack(doubleStack, NULL);
    destroy_stack(doubleStack);

    // Test for LONG_DOUBLE
    stack_s* longDoubleStack = init_stack(2, LONG_DOUBLE);
    long double ld1 = 3.1415926535L, ld2 = 2.7182818284L;
    push_stack(longDoubleStack, &ld1, sizeof(long double));
    push_stack(longDoubleStack, &ld2, sizeof(long double));
    print_stack(longDoubleStack, NULL);
    destroy_stack(longDoubleStack);

    // Test for POINTER
    stack_s* pointerStack = init_stack(2, POINTER);
    void* ptr1 = (void*) &num1, *ptr2 = (void*) &num2;
    push_stack(pointerStack, &ptr1, sizeof(void*));
    push_stack(pointerStack, &ptr2, sizeof(void*));
    print_stack(pointerStack, NULL);
    destroy_stack(pointerStack);

    // Test for VOID
    stack_s* voidStack = init_stack(2, VOID);
    void* voidPtr1 = (void*) &num1, *voidPtr2 = (void*) &num2;
    push_stack(voidStack, voidPtr1, sizeof(void*));
    push_stack(voidStack, voidPtr2, sizeof(void*));
    print_stack(voidStack, NULL);
    destroy_stack(voidStack);

    // Test for STRUCT (using Person struct as example)
    stack_s* structStack = init_stack(2, STRUCT);
    Person p1 = {"Alice", 25}, p2 = {"Bob", 30};
    push_stack(structStack, &p1, sizeof(Person));
    push_stack(structStack, &p2, sizeof(Person));
    print_stack(structStack, print_person);
    destroy_stack(structStack);

    return EXIT_SUCCESS;
}
