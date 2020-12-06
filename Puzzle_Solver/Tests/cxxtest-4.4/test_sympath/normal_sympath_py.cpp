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
bool suite_LessThanEquals_init = false;
#include "/mnt/c/Users/UserZero/Desktop/CSCI430/SudokuSolver/Puzzle_Solver/Tests/cxxtest-4.4/test/LessThanEquals.h"

static LessThanEquals suite_LessThanEquals;

static CxxTest::List Tests_LessThanEquals = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_LessThanEquals( "LessThanEquals.h", 8, "LessThanEquals", suite_LessThanEquals, Tests_LessThanEquals );

static class TestDescription_suite_LessThanEquals_testLessThanEquals : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_LessThanEquals_testLessThanEquals() : CxxTest::RealTestDescription( Tests_LessThanEquals, suiteDescription_LessThanEquals, 11, "testLessThanEquals" ) {}
 void runTest() { suite_LessThanEquals.testLessThanEquals(); }
} testDescription_suite_LessThanEquals_testLessThanEquals;

#include "/mnt/c/Users/UserZero/Desktop/CSCI430/SudokuSolver/Puzzle_Solver/Tests/cxxtest-4.4/test/Relation.h"

static Relation suite_Relation;

static CxxTest::List Tests_Relation = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_Relation( "Relation.h", 14, "Relation", suite_Relation, Tests_Relation );

static class TestDescription_suite_Relation_testPredicate : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Relation_testPredicate() : CxxTest::RealTestDescription( Tests_Relation, suiteDescription_Relation, 17, "testPredicate" ) {}
 void runTest() { suite_Relation.testPredicate(); }
} testDescription_suite_Relation_testPredicate;

static class TestDescription_suite_Relation_testRelation : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Relation_testRelation() : CxxTest::RealTestDescription( Tests_Relation, suiteDescription_Relation, 27, "testRelation" ) {}
 void runTest() { suite_Relation.testRelation(); }
} testDescription_suite_Relation_testRelation;

#include "/mnt/c/Users/UserZero/Desktop/CSCI430/SudokuSolver/Puzzle_Solver/Tests/cxxtest-4.4/test/DefaultTraits.h"

static DefaultTraits suite_DefaultTraits;

static CxxTest::List Tests_DefaultTraits = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_DefaultTraits( "DefaultTraits.h", 7, "DefaultTraits", suite_DefaultTraits, Tests_DefaultTraits );

static class TestDescription_suite_DefaultTraits_testSmallDefaultTraits : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_DefaultTraits_testSmallDefaultTraits() : CxxTest::RealTestDescription( Tests_DefaultTraits, suiteDescription_DefaultTraits, 16, "testSmallDefaultTraits" ) {}
 void runTest() { suite_DefaultTraits.testSmallDefaultTraits(); }
} testDescription_suite_DefaultTraits_testSmallDefaultTraits;

static class TestDescription_suite_DefaultTraits_testBigDefaultTraits : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_DefaultTraits_testBigDefaultTraits() : CxxTest::RealTestDescription( Tests_DefaultTraits, suiteDescription_DefaultTraits, 32, "testBigDefaultTraits" ) {}
 void runTest() { suite_DefaultTraits.testBigDefaultTraits(); }
} testDescription_suite_DefaultTraits_testBigDefaultTraits;

#include "/mnt/c/Users/UserZero/Desktop/CSCI430/SudokuSolver/Puzzle_Solver/Tests/cxxtest-4.4/test/DoubleCall.h"

static DoubleCall suite_DoubleCall;

static CxxTest::List Tests_DoubleCall = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_DoubleCall( "DoubleCall.h", 9, "DoubleCall", suite_DoubleCall, Tests_DoubleCall );

static class TestDescription_suite_DoubleCall_testAssertEqualsWithSideEffects : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_DoubleCall_testAssertEqualsWithSideEffects() : CxxTest::RealTestDescription( Tests_DoubleCall, suiteDescription_DoubleCall, 19, "testAssertEqualsWithSideEffects" ) {}
 void runTest() { suite_DoubleCall.testAssertEqualsWithSideEffects(); }
} testDescription_suite_DoubleCall_testAssertEqualsWithSideEffects;

static class TestDescription_suite_DoubleCall_testAssertDiffersWithSideEffects : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_DoubleCall_testAssertDiffersWithSideEffects() : CxxTest::RealTestDescription( Tests_DoubleCall, suiteDescription_DoubleCall, 24, "testAssertDiffersWithSideEffects" ) {}
 void runTest() { suite_DoubleCall.testAssertDiffersWithSideEffects(); }
} testDescription_suite_DoubleCall_testAssertDiffersWithSideEffects;

static class TestDescription_suite_DoubleCall_testAssertDeltaWithSideEffects : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_DoubleCall_testAssertDeltaWithSideEffects() : CxxTest::RealTestDescription( Tests_DoubleCall, suiteDescription_DoubleCall, 29, "testAssertDeltaWithSideEffects" ) {}
 void runTest() { suite_DoubleCall.testAssertDeltaWithSideEffects(); }
} testDescription_suite_DoubleCall_testAssertDeltaWithSideEffects;

#include "/mnt/c/Users/UserZero/Desktop/CSCI430/SudokuSolver/Puzzle_Solver/Tests/cxxtest-4.4/test/SameData.h"

static SameData suite_SameData;

static CxxTest::List Tests_SameData = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_SameData( "SameData.h", 7, "SameData", suite_SameData, Tests_SameData );

static class TestDescription_suite_SameData_testAssertSameData : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_SameData_testAssertSameData() : CxxTest::RealTestDescription( Tests_SameData, suiteDescription_SameData, 22, "testAssertSameData" ) {}
 void runTest() { suite_SameData.testAssertSameData(); }
} testDescription_suite_SameData_testAssertSameData;

static class TestDescription_suite_SameData_testAssertMessageSameData : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_SameData_testAssertMessageSameData() : CxxTest::RealTestDescription( Tests_SameData, suiteDescription_SameData, 27, "testAssertMessageSameData" ) {}
 void runTest() { suite_SameData.testAssertMessageSameData(); }
} testDescription_suite_SameData_testAssertMessageSameData;

static class TestDescription_suite_SameData_testSafeAssertSameData : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_SameData_testSafeAssertSameData() : CxxTest::RealTestDescription( Tests_SameData, suiteDescription_SameData, 32, "testSafeAssertSameData" ) {}
 void runTest() { suite_SameData.testSafeAssertSameData(); }
} testDescription_suite_SameData_testSafeAssertSameData;

static class TestDescription_suite_SameData_testSafeAssertMessageSameData : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_SameData_testSafeAssertMessageSameData() : CxxTest::RealTestDescription( Tests_SameData, suiteDescription_SameData, 37, "testSafeAssertMessageSameData" ) {}
 void runTest() { suite_SameData.testSafeAssertMessageSameData(); }
} testDescription_suite_SameData_testSafeAssertMessageSameData;

#include "/mnt/c/Users/UserZero/Desktop/CSCI430/SudokuSolver/Puzzle_Solver/Tests/cxxtest-4.4/test/SameFiles.h"

static SameFiles suite_SameFiles;

static CxxTest::List Tests_SameFiles = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_SameFiles( "SameFiles.h", 7, "SameFiles", suite_SameFiles, Tests_SameFiles );

static class TestDescription_suite_SameFiles_testAssertFiles : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_SameFiles_testAssertFiles() : CxxTest::RealTestDescription( Tests_SameFiles, suiteDescription_SameFiles, 11, "testAssertFiles" ) {}
 void runTest() { suite_SameFiles.testAssertFiles(); }
} testDescription_suite_SameFiles_testAssertFiles;

static class TestDescription_suite_SameFiles_testAssertFileShorter : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_SameFiles_testAssertFileShorter() : CxxTest::RealTestDescription( Tests_SameFiles, suiteDescription_SameFiles, 16, "testAssertFileShorter" ) {}
 void runTest() { suite_SameFiles.testAssertFileShorter(); }
} testDescription_suite_SameFiles_testAssertFileShorter;

static class TestDescription_suite_SameFiles_testAssertFileLonger : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_SameFiles_testAssertFileLonger() : CxxTest::RealTestDescription( Tests_SameFiles, suiteDescription_SameFiles, 21, "testAssertFileLonger" ) {}
 void runTest() { suite_SameFiles.testAssertFileLonger(); }
} testDescription_suite_SameFiles_testAssertFileLonger;

static class TestDescription_suite_SameFiles_testAssertMessageSameFiles : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_SameFiles_testAssertMessageSameFiles() : CxxTest::RealTestDescription( Tests_SameFiles, suiteDescription_SameFiles, 26, "testAssertMessageSameFiles" ) {}
 void runTest() { suite_SameFiles.testAssertMessageSameFiles(); }
} testDescription_suite_SameFiles_testAssertMessageSameFiles;

static class TestDescription_suite_SameFiles_testSafeAssertSameFiles : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_SameFiles_testSafeAssertSameFiles() : CxxTest::RealTestDescription( Tests_SameFiles, suiteDescription_SameFiles, 31, "testSafeAssertSameFiles" ) {}
 void runTest() { suite_SameFiles.testSafeAssertSameFiles(); }
} testDescription_suite_SameFiles_testSafeAssertSameFiles;

static class TestDescription_suite_SameFiles_testSafeAssertMessageSameFiles : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_SameFiles_testSafeAssertMessageSameFiles() : CxxTest::RealTestDescription( Tests_SameFiles, suiteDescription_SameFiles, 36, "testSafeAssertMessageSameFiles" ) {}
 void runTest() { suite_SameFiles.testSafeAssertMessageSameFiles(); }
} testDescription_suite_SameFiles_testSafeAssertMessageSameFiles;

#include "/mnt/c/Users/UserZero/Desktop/CSCI430/SudokuSolver/Puzzle_Solver/Tests/cxxtest-4.4/test/Tsm.h"

static TestMessageMacros suite_TestMessageMacros;

static CxxTest::List Tests_TestMessageMacros = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_TestMessageMacros( "Tsm.h", 7, "TestMessageMacros", suite_TestMessageMacros, Tests_TestMessageMacros );

static class TestDescription_suite_TestMessageMacros_testMessageMacros : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMessageMacros_testMessageMacros() : CxxTest::RealTestDescription( Tests_TestMessageMacros, suiteDescription_TestMessageMacros, 10, "testMessageMacros" ) {}
 void runTest() { suite_TestMessageMacros.testMessageMacros(); }
} testDescription_suite_TestMessageMacros_testMessageMacros;

#include "/mnt/c/Users/UserZero/Desktop/CSCI430/SudokuSolver/Puzzle_Solver/Tests/cxxtest-4.4/test/TraitsTest.h"

static TraitsTest suite_TraitsTest;

static CxxTest::List Tests_TraitsTest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_TraitsTest( "TraitsTest.h", 8, "TraitsTest", suite_TraitsTest, Tests_TraitsTest );

static class TestDescription_suite_TraitsTest_testIntegerTraits : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TraitsTest_testIntegerTraits() : CxxTest::RealTestDescription( Tests_TraitsTest, suiteDescription_TraitsTest, 11, "testIntegerTraits" ) {}
 void runTest() { suite_TraitsTest.testIntegerTraits(); }
} testDescription_suite_TraitsTest_testIntegerTraits;

static class TestDescription_suite_TraitsTest_testFloatingPointTraits : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TraitsTest_testFloatingPointTraits() : CxxTest::RealTestDescription( Tests_TraitsTest, suiteDescription_TraitsTest, 23, "testFloatingPointTraits" ) {}
 void runTest() { suite_TraitsTest.testFloatingPointTraits(); }
} testDescription_suite_TraitsTest_testFloatingPointTraits;

static class TestDescription_suite_TraitsTest_testBoolTraits : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TraitsTest_testBoolTraits() : CxxTest::RealTestDescription( Tests_TraitsTest, suiteDescription_TraitsTest, 29, "testBoolTraits" ) {}
 void runTest() { suite_TraitsTest.testBoolTraits(); }
} testDescription_suite_TraitsTest_testBoolTraits;

static class TestDescription_suite_TraitsTest_testCharTraits : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TraitsTest_testCharTraits() : CxxTest::RealTestDescription( Tests_TraitsTest, suiteDescription_TraitsTest, 35, "testCharTraits" ) {}
 void runTest() { suite_TraitsTest.testCharTraits(); }
} testDescription_suite_TraitsTest_testCharTraits;

static class TestDescription_suite_TraitsTest_testStringTraits : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TraitsTest_testStringTraits() : CxxTest::RealTestDescription( Tests_TraitsTest, suiteDescription_TraitsTest, 49, "testStringTraits" ) {}
 void runTest() { suite_TraitsTest.testStringTraits(); }
} testDescription_suite_TraitsTest_testStringTraits;

static class TestDescription_suite_TraitsTest_testStdStringTraits : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TraitsTest_testStdStringTraits() : CxxTest::RealTestDescription( Tests_TraitsTest, suiteDescription_TraitsTest, 54, "testStdStringTraits" ) {}
 void runTest() { suite_TraitsTest.testStdStringTraits(); }
} testDescription_suite_TraitsTest_testStdStringTraits;

#include "/mnt/c/Users/UserZero/Desktop/CSCI430/SudokuSolver/Puzzle_Solver/Tests/cxxtest-4.4/test/MockTest.h"

static MockTest suite_MockTest;

static CxxTest::List Tests_MockTest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_MockTest( "MockTest.h", 112, "MockTest", suite_MockTest, Tests_MockTest );

static class TestDescription_suite_MockTest_test_Mock : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MockTest_test_Mock() : CxxTest::RealTestDescription( Tests_MockTest, suiteDescription_MockTest, 115, "test_Mock" ) {}
 void runTest() { suite_MockTest.test_Mock(); }
} testDescription_suite_MockTest_test_Mock;

static class TestDescription_suite_MockTest_test_Real : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MockTest_test_Real() : CxxTest::RealTestDescription( Tests_MockTest, suiteDescription_MockTest, 121, "test_Real" ) {}
 void runTest() { suite_MockTest.test_Real(); }
} testDescription_suite_MockTest_test_Real;

static class TestDescription_suite_MockTest_test_Unimplemented : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MockTest_test_Unimplemented() : CxxTest::RealTestDescription( Tests_MockTest, suiteDescription_MockTest, 127, "test_Unimplemented" ) {}
 void runTest() { suite_MockTest.test_Unimplemented(); }
} testDescription_suite_MockTest_test_Unimplemented;

static class TestDescription_suite_MockTest_test_More_complex_mock : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MockTest_test_More_complex_mock() : CxxTest::RealTestDescription( Tests_MockTest, suiteDescription_MockTest, 132, "test_More_complex_mock" ) {}
 void runTest() { suite_MockTest.test_More_complex_mock(); }
} testDescription_suite_MockTest_test_More_complex_mock;

static class TestDescription_suite_MockTest_test_Mock_traits : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MockTest_test_Mock_traits() : CxxTest::RealTestDescription( Tests_MockTest, suiteDescription_MockTest, 141, "test_Mock_traits" ) {}
 void runTest() { suite_MockTest.test_Mock_traits(); }
} testDescription_suite_MockTest_test_Mock_traits;

static class TestDescription_suite_MockTest_test_Override : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MockTest_test_Override() : CxxTest::RealTestDescription( Tests_MockTest, suiteDescription_MockTest, 146, "test_Override" ) {}
 void runTest() { suite_MockTest.test_Override(); }
} testDescription_suite_MockTest_test_Override;

static class TestDescription_suite_MockTest_test_Supply : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MockTest_test_Supply() : CxxTest::RealTestDescription( Tests_MockTest, suiteDescription_MockTest, 160, "test_Supply" ) {}
 void runTest() { suite_MockTest.test_Supply(); }
} testDescription_suite_MockTest_test_Supply;

static class TestDescription_suite_MockTest_test_Unimplemented_supply : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MockTest_test_Unimplemented_supply() : CxxTest::RealTestDescription( Tests_MockTest, suiteDescription_MockTest, 166, "test_Unimplemented_supply" ) {}
 void runTest() { suite_MockTest.test_Unimplemented_supply(); }
} testDescription_suite_MockTest_test_Unimplemented_supply;

static class TestDescription_suite_MockTest_test_More_complex_supply : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MockTest_test_More_complex_supply() : CxxTest::RealTestDescription( Tests_MockTest, suiteDescription_MockTest, 171, "test_More_complex_supply" ) {}
 void runTest() { suite_MockTest.test_More_complex_supply(); }
} testDescription_suite_MockTest_test_More_complex_supply;

#include "/mnt/c/Users/UserZero/Desktop/CSCI430/SudokuSolver/Puzzle_Solver/Tests/cxxtest-4.4/test/SameZero.h"

static SameZero suite_SameZero;

static CxxTest::List Tests_SameZero = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_SameZero( "SameZero.h", 7, "SameZero", suite_SameZero, Tests_SameZero );

static class TestDescription_suite_SameZero_test_TS_ASSERT_SAME_DATA_passed_zero : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_SameZero_test_TS_ASSERT_SAME_DATA_passed_zero() : CxxTest::RealTestDescription( Tests_SameZero, suiteDescription_SameZero, 20, "test_TS_ASSERT_SAME_DATA_passed_zero" ) {}
 void runTest() { suite_SameZero.test_TS_ASSERT_SAME_DATA_passed_zero(); }
} testDescription_suite_SameZero_test_TS_ASSERT_SAME_DATA_passed_zero;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
