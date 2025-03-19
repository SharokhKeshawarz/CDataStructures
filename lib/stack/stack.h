#ifndef STACK_H
#define STACK_H

#include "main.h"

typedef enum stack_t {
    CHAR,
    U_CHAR,
    STRING,

    BOOL,
    SHORT,
    U_SHORT,
    INT,
    U_INT,
    LONG,
    U_LONG,
    LONG_LONG,
    U_LONG_LONG,

    FLOAT,
    DOUBLE,
    LONG_DOUBLE,

    POINTER,
    VOID,
    STRUCT
} stack_t;

typedef struct stack_s {
    stack_t type;
    size_t capacity;
    size_t size;
    void** array;
} stack_s;

stack_s* init_stack(size_t capacity, stack_t type);
void destroy_stack(stack_s* stack);

void* push_stack(stack_s* stack, void* data, size_t data_size);
void* pop_stack(stack_s* stack);

void  print_stack(stack_s* stack, void (*custom_print_function)(void*));

#endif
