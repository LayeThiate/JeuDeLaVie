#include <stdio.h>
#include <CUnit/CUnit.h>
#include "../src/utils.h"



void test_grid_create()
{
    State **array = init_array(10, 10);
    CU_ASSERT_NOT_EQUAL(array, NULL);
    free_array(array, 10);
}


int main()
{

    CU_pSuite pSuite = NULL;

    // initialize the CUnit test registry
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    // add a suite to the registry 
    pSuite = CU_add_suite("suite_test", NULL, NULL);
    if (NULL == pSuite)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // add the tests to the suite
    if (NULL == CU_add_test(pSuite, "test of init_array()", test_grid_create))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_set_mode(2);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}