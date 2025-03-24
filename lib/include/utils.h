#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <complex.h>
#include <math.h>
#include <string.h>
#include <inttypes.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <time.h>

// No Size Nedded
#define STACK_SIZE_ZERO 0

// DEREF MACRO
#define DEREF_VOID_PTR(ptr, type) (*(type*)ptr)
#define DEREF_VOID_PTR_STRING(ptr, type) ((type)ptr)
#define DEREF_VOID_PTR_CUSTOM(ptr, type) ((type*)ptr)

// MESSAGE
#define COLOR_RESET   "\x1b[0m"
#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_BLUE    "\x1b[34m"
#define BUFFER_SIZE 24

void get_current_time(char *buffer, size_t size);

#define PRINT_INFO(message, ...)   do { \
    char time_buffer[BUFFER_SIZE]; \
    get_current_time(time_buffer, sizeof(time_buffer)); \
    printf(COLOR_BLUE "%s -> INFO: " message COLOR_RESET "\n", time_buffer, ##__VA_ARGS__); \
} while(0)

#define PRINT_ERROR(message, ...)  do { \
    char time_buffer[BUFFER_SIZE]; \
    get_current_time(time_buffer, sizeof(time_buffer)); \
    printf(COLOR_RED "%s -> ERROR: " message COLOR_RESET "\n", time_buffer, ##__VA_ARGS__); \
} while(0)

#define PRINT_SUCCESS(message, ...) do { \
    char time_buffer[BUFFER_SIZE]; \
    get_current_time(time_buffer, sizeof(time_buffer)); \
    printf(COLOR_GREEN "%s -> SUCCESS: " message COLOR_RESET "\n", time_buffer, ##__VA_ARGS__); \
} while(0)

#endif
