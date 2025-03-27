#include "../lib/include/stack.h"

/*
    ITS THE SAME FOR UNION
*/

typedef struct person_t {
    char* name;
    int age;
} person_t;

static void print_person_struct(void* personPointer)
{
    person_t* person = (person_t*)personPointer;

    printf("Hello my name is %s and I am %d years old\n", person->name, person->age);
}

static size_t compare_persons(void* personPointer1, void* personPointer2)
{
    person_t* person_1 = (person_t*)personPointer1;
    person_t* person_2 = (person_t*)personPointer2;

    if (strcmp(person_1->name, person_2->name) == 0 && person_1->age == person_2->age)
        return 0;
    return 1;
}

void test_struct_stack_push()
{
    PRINT_INFO("STACK PUSH");

    stack_s* stack = stack_create(1, STRUCT);

    person_t person_1 = {"John", 18};
    person_t person_2 = {"Patric", 21};

    stack_push(stack, &person_1, sizeof(person_1));
    stack_push(stack, &person_2, sizeof(person_2));

    stack_print_all(stack, &print_person_struct);

    stack_destroy(stack);
}

void test_struct_stack_pop()
{
    PRINT_INFO("STACK POP");

    stack_s* stack = stack_create(1, STRUCT);

    person_t person_1 = {"John", 18};
    person_t person_2 = {"Patric", 21};

    stack_push(stack, &person_1, sizeof(person_1));
    stack_push(stack, &person_2, sizeof(person_2));

    stack_print_all(stack, &print_person_struct);

    stack_pop(stack);

    stack_print_all(stack, &print_person_struct);

    stack_destroy(stack);
}

void test_struct_stack_is_empty()
{
    PRINT_INFO("STACK EMPTY");

    stack_s* stack = stack_create(1, STRUCT);

    person_t person_1 = {"John", 18};
    person_t person_2 = {"Patric", 21};

    stack_push(stack, &person_1, sizeof(person_1));
    stack_push(stack, &person_2, sizeof(person_2));

    printf("%d\n", stack_is_empty(stack));

    stack_pop(stack);
    stack_pop(stack);

    printf("%d\n", stack_is_empty(stack));

    stack_destroy(stack);
}

void test_struct_stack_assigment()
{
    PRINT_INFO("STACK ASSIGMENT");

    stack_s* stack = stack_create(1, STRUCT);

    person_t person_1 = {"John", 18};
    person_t person_2 = {"Patric", 21};

    stack_push(stack, &person_1, sizeof(person_1));
    stack_push(stack, &person_2, sizeof(person_2));

    person_t *value_A = (person_t*)stack->array[0];
    person_t *value_B = DEREF_VOID_PTR_CUSTOM(stack->array[1], person_t);

    printf("Value A (bottom) Name: %s and Age %d\n", value_A->name, value_A->age);
    printf("Value B (bottom) Name: %s and Age %d\n", value_B->name, value_B->age);
    
    stack_destroy(stack);
}

void test_struct_stack_print_all()
{
    PRINT_INFO("PRINTS ALL ELEMENTS OF THE STACK");

    stack_s* stack = stack_create(1, STRUCT);

    person_t person_1 = {"John", 18};
    person_t person_2 = {"Patric", 21};

    stack_push(stack, &person_1, sizeof(person_1));
    stack_push(stack, &person_2, sizeof(person_2));
    
    stack_print_all(stack, &print_person_struct);

    stack_destroy(stack);
}

void test_struct_stack_print_single()
{
    PRINT_INFO("PRINTS SINGLE ELEMENT OF THE STACK");

    stack_s* stack = stack_create(1, STRUCT);

    person_t person_1 = {"John", 18};
    person_t person_2 = {"Patric", 21};

    stack_push(stack, &person_1, sizeof(person_1));
    stack_push(stack, &person_2, sizeof(person_2));
    
    printf("Raw void* data\n");
    printf("Name: %s and Age: %d\n", ((person_t*)stack->array[0])->name, ((person_t*)stack->array[0])->age);
    printf("Name: %s and Age: %d\n", ((person_t*)stack->array[1])->name, ((person_t*)stack->array[1])->age);

    printf("Using macro directly\n");
    printf("Name: %s and Age %d\n", DEREF_VOID_PTR_CUSTOM(stack->array[0], person_t)->name, DEREF_VOID_PTR_CUSTOM(stack->array[0], person_t)->age);
    printf("Name: %s and Age %d\n", DEREF_VOID_PTR_CUSTOM(stack->array[0], person_t)->name, DEREF_VOID_PTR_CUSTOM(stack->array[0], person_t)->age);
    
    stack_destroy(stack);
}

void test_struct_stack_get_bottom()
{
    PRINT_INFO("GET BOTTOM ELEMENT");

    stack_s* stack = stack_create(1, STRUCT);

    person_t person_1 = {"John", 18};
    person_t person_2 = {"Patric", 21};

    stack_push(stack, &person_1, sizeof(person_1));
    stack_push(stack, &person_2, sizeof(person_2));
    
    void* x = stack_get_bottom(stack);

    stack_print(x, STRUCT, &print_person_struct);

    stack_destroy(stack);
}

void test_struct_stack_get_top()
{
    PRINT_INFO("GET TOP ELEMENT");

    stack_s* stack = stack_create(1, STRUCT);

    person_t person_1 = {"John", 18};
    person_t person_2 = {"Patric", 21};

    stack_push(stack, &person_1, sizeof(person_1));
    stack_push(stack, &person_2, sizeof(person_2));
    
    void* x = stack_get_top(stack);

    stack_print(x, STRUCT, &print_person_struct);

    stack_destroy(stack);
}

void test_struct_stack_get_data_from_index()
{
    PRINT_INFO("GET DATA FROM INDEX");

    stack_s* stack = stack_create(1, STRUCT);

    person_t person_1 = {"John", 18};
    person_t person_2 = {"Patric", 21};

    stack_push(stack, &person_1, sizeof(person_1));
    stack_push(stack, &person_2, sizeof(person_2));
    
    void* x = stack_get_data(stack, 1);

    stack_print(x, STRUCT, &print_person_struct);

    stack_destroy(stack);
}

void test_struct_stack_get_index_from_data()
{
    PRINT_INFO("GET INDEX FROM DATA");

    stack_s* stack = stack_create(1, STRUCT);

    person_t person_1 = {"John", 18};
    person_t person_2 = {"Patric", 21};

    person_t search_person = {"Patric", 21};

    stack_push(stack, &person_1, sizeof(person_1));
    stack_push(stack, &person_2, sizeof(person_2));
    
    size_t x = stack_get_index(stack, stack_get_data(stack, 0), &compare_persons);
    size_t y = stack_get_index(stack, stack->array[1], &compare_persons);    
    size_t z = stack_get_index(stack, &search_person, &compare_persons);

    printf("%lu\n", x);
    printf("%lu\n", y);
    printf("%lu\n", z);

    stack_destroy(stack);
}

void test_struct_stack_derf_void_ptr()
{
    PRINT_INFO("DERFERENCE VOID POINTER USING MACRO GOOD FOR CLEAN CODE");

    stack_s* stack = stack_create(1, STRUCT);

    person_t person_1 = {"John", 18};
    person_t person_2 = {"Patric", 21};

    stack_push(stack, &person_1, sizeof(person_1));
    stack_push(stack, &person_2, sizeof(person_2));
    
    person_t* x = DEREF_VOID_PTR_CUSTOM(stack_get_bottom(stack), person_t);
    person_t* y = DEREF_VOID_PTR_CUSTOM(stack->array[1], person_t);

    printf("Value A (bottom) Name: %s and Age %d\n", x->name, x->age);
    printf("Value B (top) Name: %s and Age %d\n", y->name, y->age);

    stack_destroy(stack);
}
