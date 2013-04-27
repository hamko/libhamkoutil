# ./make_test_skelton.sh is_ring_pass IsRingPass
# ./make_test_skelton.sh [c-like name] [cpp-like name]

cat > $1_test.cpp <<EOF
#include "$1_test.hpp"
void $2Test::runTest(void)
{
    CPPUNIT_ASSERT_MESSAGE("true", true);
    CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("true", 1.0, 1.0, 0.01);
}
EOF

cat > $1_test.hpp <<EOF
#ifndef __INCLUDED_`echo $1 | tr '[a-z]' '[A-Z]'`_TEST_H__
#define __INCLUDED_`echo $1 | tr '[a-z]' '[A-Z]'`_TEST_H__
#include <string>
#include <cppunit/TestCase.h>

class $2Test : public CppUnit::TestCase{
    void runTest(void);
    public:
        $2Test(std::string name) : CppUnit::TestCase(name){}
};

#endif
EOF
