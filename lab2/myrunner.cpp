/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/ErrorPrinter.h>

int main( int argc, char *argv[] ) {
 int status;
    CxxTest::ErrorPrinter tmp;
    CxxTest::RealWorldDescription::_worldName = "cxxtest";
    status = CxxTest::Main< CxxTest::ErrorPrinter >( tmp, argc, argv );
    return status;
}
bool suite_MyTestSuite_init = false;
#include "mytest.h"

static MyTestSuite suite_MyTestSuite;

static CxxTest::List Tests_MyTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_MyTestSuite( "mytest.h", 4, "MyTestSuite", suite_MyTestSuite, Tests_MyTestSuite );

static class TestDescription_suite_MyTestSuite_testConstructors : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testConstructors() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 7, "testConstructors" ) {}
 void runTest() { suite_MyTestSuite.testConstructors(); }
} testDescription_suite_MyTestSuite_testConstructors;

static class TestDescription_suite_MyTestSuite_testIndexingOperator : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testIndexingOperator() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 45, "testIndexingOperator" ) {}
 void runTest() { suite_MyTestSuite.testIndexingOperator(); }
} testDescription_suite_MyTestSuite_testIndexingOperator;

static class TestDescription_suite_MyTestSuite_testAssignmentOperator : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testAssignmentOperator() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 51, "testAssignmentOperator" ) {}
 void runTest() { suite_MyTestSuite.testAssignmentOperator(); }
} testDescription_suite_MyTestSuite_testAssignmentOperator;

static class TestDescription_suite_MyTestSuite_testIstream : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testIstream() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 58, "testIstream" ) {}
 void runTest() { suite_MyTestSuite.testIstream(); }
} testDescription_suite_MyTestSuite_testIstream;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
