#include "sample_test.hpp"

void SampleTest::runTest(void){
    CPPUNIT_ASSERT_MESSAGE("true", true);
    CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("true", 1.0, 1.0, 0.01);
}
