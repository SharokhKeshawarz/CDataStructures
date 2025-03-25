#ifndef STACK_H
#define STACK_H

#include "utils.h"

typedef enum stack_t {
    BOOL,

    CHAR,
    UCHAR,

    SHORT,
    USHORT,

    INT,
    UINT,

    LONG,
    ULONG,
    LONG_LONG,
    ULONG_LONG,

    FLOAT,
    DOUBLE,
    LONG_DOUBLE,

    POINTER,
    STRING,
    STRUCT,
    ENUM,
    UNION,
    VOID_POINTER
} stack_t;

typedef struct stack_s {
    stack_t type;
    size_t capacity;
    size_t size;
    void** array;
} stack_s;

stack_s* stack_create(size_t capacity, stack_t type);
void stack_destroy(stack_s* stack);

void stack_push(stack_s* stack, void* data, size_t data_size);
void stack_pop(stack_s* stack);

void* stack_get_data(stack_s* stack, size_t index);
size_t stack_get_index(stack_s* stack, void* data, size_t (*compare_function)(void*, void*));

void* stack_get_top(stack_s* stack);
void* stack_get_bottom(stack_s* stack);

bool stack_is_empty(stack_s* stack);

void stack_print(void* value, stack_t type, void (*custom_print_func)(void*));
void stack_print_all(stack_s* stack, void (*custom_print_func)(void*));

#endif