/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#define _CXXTEST_HAVE_EH
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

static class TestDescription_suite_MyTestSuite_testAssignmentOperator : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testAssignmentOperator() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 51, "testAssignmentOperator" ) {}
 void runTest() { suite_MyTestSuite.testAssignmentOperator(); }
} testDescription_suite_MyTestSuite_testAssignmentOperator;

static class TestDescription_suite_MyTestSuite_testAddition : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testAddition() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 63, "testAddition" ) {}
 void runTest() { suite_MyTestSuite.testAddition(); }
} testDescription_suite_MyTestSuite_testAddition;

static class TestDescription_suite_MyTestSuite_testSubtraction : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testSubtraction() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 83, "testSubtraction" ) {}
 void runTest() { suite_MyTestSuite.testSubtraction(); }
} testDescription_suite_MyTestSuite_testSubtraction;

static class TestDescription_suite_MyTestSuite_testMultiplication : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testMultiplication() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 104, "testMultiplication" ) {}
 void runTest() { suite_MyTestSuite.testMultiplication(); }
} testDescription_suite_MyTestSuite_testMultiplication;

static class TestDescription_suite_MyTestSuite_testIstream : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testIstream() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 122, "testIstream" ) {}
 void runTest() { suite_MyTestSuite.testIstream(); }
} testDescription_suite_MyTestSuite_testIstream;

static class TestDescription_suite_MyTestSuite_testGetRows : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testGetRows() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 132, "testGetRows" ) {}
 void runTest() { suite_MyTestSuite.testGetRows(); }
} testDescription_suite_MyTestSuite_testGetRows;

static class TestDescription_suite_MyTestSuite_testGetCols : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testGetCols() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 146, "testGetCols" ) {}
 void runTest() { suite_MyTestSuite.testGetCols(); }
} testDescription_suite_MyTestSuite_testGetCols;

static class TestDescription_suite_MyTestSuite_testSetValue : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testSetValue() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 160, "testSetValue" ) {}
 void runTest() { suite_MyTestSuite.testSetValue(); }
} testDescription_suite_MyTestSuite_testSetValue;

static class TestDescription_suite_MyTestSuite_testReset : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testReset() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 170, "testReset" ) {}
 void runTest() { suite_MyTestSuite.testReset(); }
} testDescription_suite_MyTestSuite_testReset;

static class TestDescription_suite_MyTestSuite_testIdentity : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testIdentity() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 179, "testIdentity" ) {}
 void runTest() { suite_MyTestSuite.testIdentity(); }
} testDescription_suite_MyTestSuite_testIdentity;

static class TestDescription_suite_MyTestSuite_testInsertRow : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testInsertRow() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 190, "testInsertRow" ) {}
 void runTest() { suite_MyTestSuite.testInsertRow(); }
} testDescription_suite_MyTestSuite_testInsertRow;

static class TestDescription_suite_MyTestSuite_testAppendRow : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testAppendRow() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 215, "testAppendRow" ) {}
 void runTest() { suite_MyTestSuite.testAppendRow(); }
} testDescription_suite_MyTestSuite_testAppendRow;

static class TestDescription_suite_MyTestSuite_testRemoveRow : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testRemoveRow() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 242, "testRemoveRow" ) {}
 void runTest() { suite_MyTestSuite.testRemoveRow(); }
} testDescription_suite_MyTestSuite_testRemoveRow;

static class TestDescription_suite_MyTestSuite_testInsertCol : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testInsertCol() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 260, "testInsertCol" ) {}
 void runTest() { suite_MyTestSuite.testInsertCol(); }
} testDescription_suite_MyTestSuite_testInsertCol;

static class TestDescription_suite_MyTestSuite_testAppendCol : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testAppendCol() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 285, "testAppendCol" ) {}
 void runTest() { suite_MyTestSuite.testAppendCol(); }
} testDescription_suite_MyTestSuite_testAppendCol;

static class TestDescription_suite_MyTestSuite_testRemoveCol : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testRemoveCol() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 312, "testRemoveCol" ) {}
 void runTest() { suite_MyTestSuite.testRemoveCol(); }
} testDescription_suite_MyTestSuite_testRemoveCol;

static class TestDescription_suite_MyTestSuite_testBegin : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testBegin() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 331, "testBegin" ) {}
 void runTest() { suite_MyTestSuite.testBegin(); }
} testDescription_suite_MyTestSuite_testBegin;

static class TestDescription_suite_MyTestSuite_testEnd : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testEnd() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 337, "testEnd" ) {}
 void runTest() { suite_MyTestSuite.testEnd(); }
} testDescription_suite_MyTestSuite_testEnd;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
