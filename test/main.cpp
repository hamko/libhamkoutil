#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include "sample_test.hpp"

int main(int argc, char** argv)
{
    CppUnit::TextUi::TestRunner runner;
    runner.addTest(new SampleTest("SampleTest"));

    runner.run();

    return 0;
}
