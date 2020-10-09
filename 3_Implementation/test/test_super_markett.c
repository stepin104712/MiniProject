#include<super_markett.h>
#include<unity.h>

/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}


void test_ADD(void)
{
    TEST_ASSERT(ADD());
}

void test_VIEW(void)
{
    TEST_ASSERT(VIEW());
}

void test_SEARCH(void)
{
    TEST_ASSERT(SEARCH());
}

void test_EDIT(void)
{
    TEST_ASSERT(EDIT());
}

void test_DELETE(void)
{
    TEST_ASSERT(DELETE());
}

int test_main(void)
{
    UNITY_BEGIN();


    RUN_TEST(test_ADD);
    RUN_TEST(test_VIEW);
    RUN_TEST(test_SEARCH);
    RUN_TEST(test_EDIT);
    RUN_TEST(test_DELETE);

    return UNITY_END();
}
