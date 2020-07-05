
#ifndef DNASEQUENCE_TESTDNASEQUENCE_H
#define DNASEQUENCE_TESTDNASEQUENCE_H

#include "../DNA/DnaSequence.h"

class TestDnaSequence {
public:
    void testConstractors();
    void testConstractorReadFromFile();
    void testCopyConstractor();
    void tsetAssignmentOperator();
    void testStreamOperator();
    void testSubscriptOperator();
    void testLength();
    void testEqualityOperator();
    void testInequalityOperator();
    void testSlice();
    void testGetDnaPair();
    void testFind();
    void testCount();
    void testFindAll();
    void testFindConsensusSequences();
    void testWriteDnaToFile();
};


#endif //DNASEQUENCE_TESTDNASEQUENCE_H
