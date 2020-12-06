#include <cxxtest/TestSuite.h>
#include <iostream>
#include "../sudoku.h"

class Tests : public CxxTest::TestSuite
{
public:
    void test_fail()
    {
        TS_ASSERT(0==1);
    }
    void test_success()
    {
        TS_ASSERT(0==0);
    }
};