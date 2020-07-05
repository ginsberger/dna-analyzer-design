#include "Test/TestDnaSequence.h"

int main() {
    TestDnaSequence testDnaSequence;

    testDnaSequence.testConstractors();
    testDnaSequence.testConstractorReadFromFile();
    testDnaSequence.testCopyConstractor();
    testDnaSequence.tsetAssignmentOperator();
    testDnaSequence.testStreamOperator();
    testDnaSequence.testSubscriptOperator();
    testDnaSequence.testLength();
    testDnaSequence.testEqualityOperator();
    testDnaSequence.testInequalityOperator();
    testDnaSequence.testSlice();
    testDnaSequence.testGetDnaPair();
    testDnaSequence.testFind();
    testDnaSequence.testCount();
    testDnaSequence.testFindAll();
    testDnaSequence.testFindConsensusSequences();
    testDnaSequence.testWriteDnaToFile();
    return 0;
}