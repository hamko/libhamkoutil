#ifndef __INCLUDED_SAMPLE_TEST__
#define __INCLUDED_SAMPLE_TEST__

#include <string>
#include <cppunit/TestCase.h>

class SampleTest : public CppUnit::TestCase{
    void runTest(void);
public:
    SampleTest(std::string name) : CppUnit::TestCase(name){}
};

#endif
