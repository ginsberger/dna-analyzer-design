#include "../Writer/FileWriter.h"
#include "../Reader/FileReader.h"
#include "TestDnaSequence.h"

void TestDnaSequence::testConstractors()
{
    std::cout << "\n\n\n---------------test DnaSequence Constractors---------------\n";
    std::cout << "---test create DnaSequence with valid DNA---" << std::endl;
    try {
        DnaSequence dnaSequence("ACTG");
    }
    catch (std::exception& ex){
        std::cout << ex.what() << std::endl;
    }


    try{
        std::string DNA = "AGCT";
        DnaSequence dnaSequence(DNA);
    }
    catch (std::exception& ex){
        std::cout << ex.what() << std::endl;
    }


    std::cout << "---test create DnaSequence with invalid DNA---" << std::endl;

    try{
        DnaSequence dnaSequence("asf");
    }
    catch (std::exception& ex){
        std::cout << ex.what() << std::endl;
    }


    try{
        std::string DNA = "afsd";
        DnaSequence dnaSequence(DNA);
    }
    catch (std::exception& ex){
        std::cout << ex.what() << std::endl;
    }


}
void TestDnaSequence::testConstractorReadFromFile()
{
    std::cout << "\n\n\n---------------test DnaSequence Constractor- Read Dna From File---------------\n";
    try {
        FileReader reader("DnaFile.txt");
        DnaSequence dnaSequence(reader);
    }
    catch (OpenFileError& ex)
    {
        std::cout << ex.what() << std::endl;
    }
    catch (std::exception& ex){
        std::cout << ex.what() << std::endl;
    }

}
void TestDnaSequence::testCopyConstractor()
{
    std::cout << "\n\n\n-----------------test DnaSequence Copy Constractor-----------------\n";
    try{
        DnaSequence dnaSequence1("AG");
        DnaSequence dnaSequence(dnaSequence1);
        if(*dnaSequence.m_dnaSequence != *dnaSequence1.m_dnaSequence)
            std::cout << "error Copy Constractor method is not OK!" << std::endl;
    }
    catch (std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
    }
}
void TestDnaSequence::tsetAssignmentOperator()
{
    std::cout << "\n\n\n-----------------test DnaSequence Assignment Operator-----------------\n";
    try{
        DnaSequence dnaSequence1("AGCTGAATC");
        DnaSequence dnaSequence2("AC");
        dnaSequence2 = dnaSequence1;
        std::cout << "dnaSequence1- " << dnaSequence1<< std::endl <<"dnaSequence2- " << dnaSequence2 << std::endl;

    }
    catch (std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
    }
}
void TestDnaSequence::testStreamOperator()
{
    std::cout << "\n\n\n-----------------test DnaSequence Stream Operator-----------------\n";
    try{

        DnaSequence dnaSequence("AGTC");
        std::cout << "expected output: DnaSequence: AGTC" << std::endl;
        std::cout << "function output: " << dnaSequence << std::endl;
    }
    catch (std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
    }
}
void TestDnaSequence::testSubscriptOperator() {
    std::cout << "\n\n\n-----------------test DnaSequence Subscript Operator-----------------\n";
    try {
        DnaSequence dnaSequence("AGCT");

        std::cout << "\n---chack simply get substring---" << std::endl;
        std::cout << "expected output for dnaSequence[0]: A" << std::endl;
        std::cout << "function output: " << dnaSequence[0] << std::endl;

        std::cout << "\n---chack get substring out of range---" << std::endl;
        dnaSequence[10] = 'A';
    }
    catch (std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
    }

    try {
        DnaSequence dnaSequence("AGCT");

        std::cout << "\n---chack assignment to DNA---" << std::endl;

        std::cout << "\n-assignment valid nucleotide-" << std::endl;
        std::cout << "before assignment: " << dnaSequence << std::endl;
        dnaSequence[0] = 'T';
        std::cout << "after assignment dnaSequence[0] = 'T': " << dnaSequence << std::endl;

        std::cout << "\n-assignment invalid nucleotide-" << std::endl;
        dnaSequence[0] = 'S';
    }
    catch (std::exception &ex) {
        std::cout << ex.what() << std::endl;
    }
}
void TestDnaSequence::testLength()
{
    std::cout << "\n\n\n-----------------test DnaSequence Length Function-----------------\n";
    try{
        DnaSequence dnaSequence("AGTC");
        std::cout << "length of \"AGTC\": " << dnaSequence.getLength() << std::endl;
    }
    catch (std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
    }
}
void TestDnaSequence::testEqualityOperator()
{
    std::cout << "\n\n\n-----------------test DnaSequence Equality Operator-----------------\n";
    try{
        DnaSequence dnaSequence1("ACTG");
        DnaSequence dnaSequence2("ACTG");
        if(dnaSequence1 == dnaSequence2)
            std::cout << "DnaSequence Equality Operator works good!!";
        else
            std::cout << "DnaSequence Equality Operator is not OK!";
    }
    catch (std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
    }
}
void TestDnaSequence::testInequalityOperator()
{
    std::cout << "\n\n\n-----------------test DnaSequence Inequality Operator-----------------\n";
    try{
        DnaSequence dnaSequence1("ACTG");
        DnaSequence dnaSequence2("GT");
        if(dnaSequence1 != dnaSequence2)
            std::cout << "DnaSequence Inequality Operator works good!!" << std::endl;
        else
            std::cout << "DnaSequence Inequality Operator is not OK!" << std::endl;
    }
    catch (std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
    }
}
void TestDnaSequence::testSlice()
{
    std::cout << "\n\n\n-----------------test DnaSequence Slice-----------------\n";
    try{
        DnaSequence dnaSequence("ACTGAAAAATTTTGGCC");
        std::cout << "expected output: TGAAA" << std::endl;
        std::cout << "function output: " << dnaSequence.slice(2,8)<< std::endl;
    }
    catch (std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
    }
}
void TestDnaSequence::testGetDnaPair()
{
    std::cout << "\n\n\n-----------------test Get DnaSequence Pair-----------------\n";
    try{
        DnaSequence dnaSequence("ACTGAAGGTTC");
        std::cout << "expected output: GAACCTTCAGT" << std::endl;
        std::cout << "function output: " << dnaSequence.getDnaPaired()<< std::endl;
    }
    catch (std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
    }
}
void TestDnaSequence::testFind()
{
    std::cout << "\n\n\n-----------------test DnaSequence Find-----------------\n";
    try{
        DnaSequence dnaSequence("ACTGAAGGTTC");
        if(dnaSequence.find("CTGA") == 1 and dnaSequence.find("TG",1) == 2)
            std::cout << "DnaSequence Find Function works good!!" << std::endl;
        else
            std::cout << "DnaSequence Find Function is not OK!" << std::endl;
    }
    catch (std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
    }
}
void TestDnaSequence::testCount()
{
    std::cout << "\n\n\n-----------------test DnaSequence Count-----------------\n";
    try{
        DnaSequence dnaSequence("ACTGAAGGTTC");
        if(dnaSequence.count("AC") == 1)
            std::cout << "DnaSequence Count Function works good!!" << std::endl;
        else
            std::cout << "DnaSequence Count Function is not OK!" << std::endl;
    }
    catch (std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
    }
}
void TestDnaSequence::testFindAll()
{
    std::cout << "\n\n\n-----------------test DnaSequence FindAll-----------------\n";
    try{
        DnaSequence dnaSequence("ACTGACAGGTTAC");
        size_t indexes[] = {0,4,11};
        std::list<size_t > subsequenceIndexes = dnaSequence.findAll("AC");
        size_t i = 0;
        bool flag = true;

        for(std::list<size_t >::iterator it=subsequenceIndexes.begin(); it != subsequenceIndexes.end() and i<subsequenceIndexes.size(); ++it,++i)
        {
            if(*it != indexes[i])
            {
                flag = false;
                break;
            }
        }

        if(flag)
        {
            std::cout << "DnaSequence FindAll Function works good!!" << std::endl;
        }
        else
        {
            std::cout << "DnaSequence FindAll Function is not OK!" << std::endl;
        }
    }
    catch (std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
    }
}
void TestDnaSequence::testFindConsensusSequences()
{
    std::cout << "\n\n\n-----------------test DnaSequence Find Consensus Sequences-----------------\n";
    try{
        DnaSequence dnaSequence("ATGTGATAATAGATAG");
        std::list<DnaSequence> consensusSequences = dnaSequence.findConsensusSequences();

        DnaSequence sequencesString[] = {"ATGTGA", "ATGTGATAA", "ATGTGATAATAG"};
        std::list<DnaSequence > sequencesList;
        sequencesList.assign(sequencesString,sequencesString+3);

        bool flag = true;

        for(std::list<DnaSequence >::iterator it=consensusSequences.begin(), it2=sequencesList.begin() ; it != consensusSequences.end(); ++it,++it2)
        {
            if(*it != *it2)
            {
                flag = false;
                break;
            }
        }

        if(flag)
        {
            std::cout << "DnaSequence Find Consensus Sequences Function works good!!" << std::endl;
        }
        else
        {
            std::cout << "DnaSequence Find Consensus Sequences Function is not OK!" << std::endl;
        }
    }
    catch (std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
    }
}
void TestDnaSequence::testWriteDnaToFile()
{
    std::cout << "\n\n\n---------------test DnaSequence Write Dna To File---------------\n";
    try {
        FileWriter writer("DnaFile.txt");
        DnaSequence dnaSequence("ATGTGATAATAGATAG");
        writer.write((char*)dnaSequence.m_dnaSequence);
    }
    catch (OpenFileError& ex)
    {
        std::cout << ex.what() << std::endl;
    }
    catch (std::exception& ex){
        std::cout << ex.what() << std::endl;
    }
}


