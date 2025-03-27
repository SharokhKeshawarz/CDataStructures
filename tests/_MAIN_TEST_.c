#include <stdlib.h>

//#define TEST_CHAR
//#define TEST_UCHAR
//#define TEST_BOOL
//#define TEST_SHORT
//#define TEST_USHORT
//#define TEST_INT
//#define TEST_UINT
//#define TEST_LONG
//#define TEST_ULONG
//#define TEST_LONG_LONG
//#define TEST_ULONG_LONG
//#define TEST_FLOAT
//#define TEST_DOUBLE
//#define TEST_LONG_DOUBLE
//#define TEST_STRING
//#define TEST_STRUCT // SAME FOR UNION
//#define TEST_ENUM
//#define TEST_POINTER

/////////////////////////////////////////////////////////////////////////////////////////////////////
/*
    UNCOMMEND A DEFINE AND EXECUTE TO SEE THE TEST CASES
*/
int main()
{
    #ifdef TEST_CHAR
    test_char_stack_push();
    test_char_stack_pop();
    test_char_stack_is_empty();
    test_char_stack_print_all();
    test_char_stack_print_single();
    test_char_stack_get_bottom();
    test_char_stack_get_top();
    test_char_stack_get_data_from_index();
    test_char_stack_get_index_from_data();
    test_char_stack_derf_void_ptr();
    #endif

    #ifdef TEST_UCHAR
    test_uchar_stack_push();
    test_uchar_stack_pop();
    test_uchar_stack_is_empty();
    test_uchar_stack_print_all();
    test_uchar_stack_print_single();
    test_uchar_stack_get_bottom();
    test_uchar_stack_get_top();
    test_uchar_stack_get_data_from_index();
    test_uchar_stack_get_index_from_data();
    test_uchar_stack_derf_void_ptr();
    #endif

    #ifdef TEST_BOOL
    test_bool_stack_push();
    test_bool_stack_pop();
    test_bool_stack_is_empty();
    test_bool_stack_print_all();
    test_bool_stack_print_single();
    test_bool_stack_get_bottom();
    test_bool_stack_get_top();
    test_bool_stack_get_data_from_index();
    test_bool_stack_get_index_from_data();
    test_bool_stack_derf_void_ptr();
    #endif

    #ifdef TEST_SHORT
    test_short_stack_push();
    test_short_stack_pop();
    test_short_stack_is_empty();
    test_short_stack_print_all();
    test_short_stack_print_single();
    test_short_stack_get_bottom();
    test_short_stack_get_top();
    test_short_stack_get_data_from_index();
    test_short_stack_get_index_from_data();
    test_short_stack_derf_void_ptr();
    #endif

    #ifdef TEST_USHORT
    test_ushort_stack_push();
    test_ushort_stack_pop();
    test_ushort_stack_is_empty();
    test_ushort_stack_print_all();
    test_ushort_stack_print_single();
    test_ushort_stack_get_bottom();
    test_ushort_stack_get_top();
    test_ushort_stack_get_data_from_index();
    test_ushort_stack_get_index_from_data();
    test_ushort_stack_derf_void_ptr();
    #endif

    #ifdef TEST_INT
    test_int_stack_push();
    test_int_stack_pop();
    test_int_stack_is_empty();
    test_int_stack_print_all();
    test_int_stack_print_single();
    test_int_stack_get_bottom();
    test_int_stack_get_top();
    test_int_stack_get_data_from_index();
    test_int_stack_get_index_from_data();
    test_int_stack_derf_void_ptr();
    #endif

    #ifdef TEST_UINT
    test_uint_stack_push();
    test_uint_stack_pop();
    test_uint_stack_is_empty();
    test_uint_stack_print_all();
    test_uint_stack_print_single();
    test_uint_stack_get_bottom();
    test_uint_stack_get_top();
    test_uint_stack_get_data_from_index();
    test_uint_stack_get_index_from_data();
    test_uint_stack_derf_void_ptr();
    #endif

    #ifdef TEST_LONG
    test_long_stack_push();
    test_long_stack_pop();
    test_long_stack_is_empty();
    test_long_stack_print_all();
    test_long_stack_print_single();
    test_long_stack_get_bottom();
    test_long_stack_get_top();
    test_long_stack_get_data_from_index();
    test_long_stack_get_index_from_data();
    test_long_stack_derf_void_ptr();
    #endif

    #ifdef TEST_ULONG
    test_ulong_stack_push();
    test_ulong_stack_pop();
    test_ulong_stack_is_empty();
    test_ulong_stack_print_all();
    test_ulong_stack_print_single();
    test_ulong_stack_get_bottom();
    test_ulong_stack_get_top();
    test_ulong_stack_get_data_from_index();
    test_ulong_stack_get_index_from_data();
    test_ulong_stack_derf_void_ptr();
    #endif


    #ifdef TEST_LONG_LONG
    test_long_long_stack_push();
    test_long_long_stack_pop();
    test_long_long_stack_is_empty();
    test_long_long_stack_print_all();
    test_long_long_stack_print_single();
    test_long_long_stack_get_bottom();
    test_long_long_stack_get_top();
    test_long_long_stack_get_data_from_index();
    test_long_long_stack_get_index_from_data();
    test_long_long_stack_derf_void_ptr();
    #endif

    #ifdef TEST_ULONG_LONG
    test_ulong_long_stack_push();
    test_ulong_long_stack_pop();
    test_ulong_long_stack_is_empty();
    test_ulong_long_stack_print_all();
    test_ulong_long_stack_print_single();
    test_ulong_long_stack_get_bottom();
    test_ulong_long_stack_get_top();
    test_ulong_long_stack_get_data_from_index();
    test_ulong_long_stack_get_index_from_data();
    test_ulong_long_stack_derf_void_ptr();
    #endif

    #ifdef TEST_FLOAT
    test_float_stack_push();
    test_float_stack_pop();
    test_float_stack_is_empty();
    test_float_stack_print_all();
    test_float_stack_print_single();
    test_float_stack_get_bottom();
    test_float_stack_get_top();
    test_float_stack_get_data_from_index();
    test_float_stack_get_index_from_data();
    test_float_stack_derf_void_ptr();
    #endif

    #ifdef TEST_DOUBLE
    test_double_stack_push();
    test_double_stack_pop();
    test_double_stack_is_empty();
    test_double_stack_print_all();
    test_double_stack_print_single();
    test_double_stack_get_bottom();
    test_double_stack_get_top();
    test_double_stack_get_data_from_index();
    test_double_stack_get_index_from_data();
    test_double_stack_derf_void_ptr();
    #endif

    #ifdef TEST_LONG_DOUBLE
    test_long_double_stack_push();
    test_long_double_stack_pop();
    test_long_double_stack_is_empty();
    test_long_double_stack_print_all();
    test_long_double_stack_print_single();
    test_long_double_stack_get_bottom();
    test_long_double_stack_get_top();
    test_long_double_stack_get_data_from_index();
    test_long_double_stack_get_index_from_data();
    test_long_double_stack_derf_void_ptr();
    #endif

    #ifdef TEST_STRING
    test_string_stack_push();
    test_string_stack_pop();
    test_string_stack_is_empty();
    test_string_stack_assigment();
    test_string_stack_print_all();
    test_string_stack_print_single();
    test_string_stack_get_bottom();
    test_string_stack_get_top();
    test_string_stack_get_data_from_index();
    test_string_stack_get_index_from_data();
    test_string_stack_derf_void_ptr();
    #endif

    #ifdef TEST_STRUCT
    test_struct_stack_push();
    test_struct_stack_pop();
    test_struct_stack_is_empty();
    test_struct_stack_assigment();
    test_struct_stack_print_all();
    test_struct_stack_print_single();
    test_struct_stack_get_bottom();
    test_struct_stack_get_data_from_index();
    test_struct_stack_get_index_from_data();
    test_struct_stack_derf_void_ptr();
    #endif

    #ifdef TEST_ENUM
    test_enum_stack_push();
    test_enum_stack_pop();
    test_enum_stack_is_empty();
    test_enum_stack_assignment();
    test_enum_stack_print_all();
    test_enum_stack_print_single();
    test_enum_stack_get_bottom();
    test_enum_stack_get_data_from_index();
    test_enum_stack_get_index_from_data();
    test_enum_stack_deref_void_ptr();
    #endif

    #ifdef TEST_POINTER
    test_pointer_stack_push();
    test_pointer_stack_pop();
    test_pointer_stack_is_empty();
    test_pointer_stack_assigment();
    test_pointer_stack_print_all();
    test_pointer_stack_print_single();
    test_pointer_stack_get_bottom();
    test_pointer_stack_get_top();
    test_pointer_stack_get_data_from_index();
    test_pointer_stack_get_index_from_data();
    test_pointer_stack_derf_void_ptr();
    #endif

    return EXIT_SUCCESS;
}
