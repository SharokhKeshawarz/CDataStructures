#include "../Unity/unity.h"
#include "../lib/include/stack.h"

void setUp(void) {}     // Required by Unity (Runs before each test)
void tearDown(void) {}  // Required by Unity (Runs after each test)

void test_stack_push(void)
{
    stack_s* stack = stack_create(2, CHAR);
    char value1 = 'A', value2 = 'B';

    stack_push(stack, &value1, 1);
    stack_push(stack, &value2, 1);

    TEST_ASSERT_EQUAL('A', DEREF_VOID_PTR(stack->array[0], int));
    TEST_ASSERT_EQUAL('B', DEREF_VOID_PTR(stack->array[1], int));

    stack_destroy(stack);
}


int main()
{
    UNITY_BEGIN();
    RUN_TEST(test_stack_push);
    return UNITY_END();
}
