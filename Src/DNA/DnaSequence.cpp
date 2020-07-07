
#include "DnaSequence.h"
#include <cstring>//strlen strcpy ...
#include "../Reader/IReader.h"
#include "../Writer/IWriter.h"

static bool dnaSeqCmp(const DnaSequence& dna1,const DnaSequence& dna2);



DnaSequence::DnaSequence(const char* dnaSequence):m_length(strlen(dnaSequence))
{
    initDnaSequence(dnaSequence);
}

DnaSequence::DnaSequence(const IReader& reader)
{
    initDnaSequence(reader.read().c_str());
}


DnaSequence::DnaSequence(const std::string& dnaSequence):m_length(dnaSequence.length())
{
    initDnaSequence(dnaSequence.c_str());
}


DnaSequence::~DnaSequence()
{
    delete[] m_dnaSequence;
    m_dnaSequence = NULL;
}


void DnaSequence::initDnaSequence(const char* dnaSequence)
{
    if (!isValidDna(dnaSequence) or !*dnaSequence) {
        throw std::invalid_argument("error: Illegal DNA");
    }
    Nucleotide* newnucleotide = new Nucleotide[strlen(dnaSequence)];
    for(size_t i=0; i<strlen(dnaSequence);++i)
    {
        newnucleotide[i] = dnaSequence[i];
    }
    m_dnaSequence = newnucleotide;
}


DnaSequence::DnaSequence(const DnaSequence& other):m_dnaSequence(NULL)
{
    Nucleotide* newnucleotide = new Nucleotide[other.getLength()];
    for(size_t i=0; i<other.m_length;++i)
    {
        newnucleotide[i] = other[i];
    }
    m_dnaSequence = newnucleotide;
    m_length = other.m_length;
}


DnaSequence& DnaSequence::operator=(const DnaSequence& other) {

    if(this == &other)
    {
        return *this;
    }
    Nucleotide* newnucleotide = new Nucleotide[other.getLength()];
    for(size_t i=0; i<other.m_length;++i)
    {
        newnucleotide[i] = other[i];
    }
    m_dnaSequence = newnucleotide;
    m_length = other.m_length;
    return *this;
}


std::ostream& operator<<(std::ostream& os, const DnaSequence& dnaSequence)
{
    for(size_t i = 0; i< dnaSequence.getLength();++i)
    {
        os << dnaSequence[i];
    }
    return os;
}


bool operator==(const DnaSequence& dnaSequence1,const DnaSequence& dnaSequence2)
{
    return !dnaSeqCmp(dnaSequence1,dnaSequence2);
}


bool operator!=(const DnaSequence& dnaSequence1, const DnaSequence& dnaSequence2)
{
    return dnaSeqCmp(dnaSequence1,dnaSequence2) != 0;
}


Nucleotide& DnaSequence::operator[](size_t index)const
{
    if(index >= m_length)
    {
        throw std::invalid_argument("Array index out of range");
    }

    return m_dnaSequence[index];
}


size_t DnaSequence::getLength()const
{
    return m_length;
}


DnaSequence DnaSequence::slice(size_t start,size_t end)const
{
    DnaSequence sliceDna(end - start -1);
    for(size_t i=start ; i < end-1 ; i++)
    {
        sliceDna[i-start] = m_dnaSequence[i];
    }
    return sliceDna;
}


DnaSequence DnaSequence::getDnaPaired()const
{
    DnaSequence sliceDna(m_length);
    for(size_t i=0 ; i < m_length ; i++)
    {
        sliceDna[m_length-i-1] = m_dnaSequence[i].getNucleotidePair();
    }
    return sliceDna;
}


size_t DnaSequence::find(const DnaSequence& dnaSubSequence, size_t start)const
{
    std::string seq=(const char*)m_dnaSequence;
    return seq.find((const char*)dnaSubSequence.m_dnaSequence,start);

}


size_t DnaSequence::count(const DnaSequence& dnaSubSequence)const
{
    size_t count = 0,indexFound = find(dnaSubSequence);
    DnaSequence dna = *this;
    while(indexFound != std::string::npos)
    {
        count++;
        indexFound = find(dnaSubSequence,indexFound + 1);
    }

    return count;
}


std::list<size_t> DnaSequence::findAll(const DnaSequence& dnaSubSequence)const
{
    std::list<size_t> subSequenceIndexes;
    size_t subSequenceIndex = find(dnaSubSequence);
    while (subSequenceIndex != std::string::npos)
    {
        subSequenceIndexes.push_back(subSequenceIndex);
        subSequenceIndex = slice(subSequenceIndex, m_length+1).find(dnaSubSequence);
    }

    return subSequenceIndexes;
}


std::list<DnaSequence> DnaSequence::findConsensusSequences()
{
    std::list<DnaSequence> consensusSequences;
    std::list<size_t > startSequences = findAll("ATG");
    std::list<size_t > endSequences1 = findAll("TAG");
    std::list<size_t > endSequences2 = findAll("TAA");
    std::list<size_t > endSequences3 = findAll("TGA");

    for(std::list<size_t >::iterator startIt=startSequences.begin(); startIt != startSequences.end(); ++startIt)
    {
        for(std::list<size_t >::iterator endIt=endSequences1.begin(); endIt != endSequences1.end(); ++endIt)
        {
            if(*startIt < *endIt and (*endIt-*startIt)%3 == 0)
            {
                DnaSequence consensusSequence = slice(*startIt -1, *endIt +1);
                consensusSequences.push_back(consensusSequence);
            }
        }

        for(std::list<size_t >::iterator endIt=endSequences2.begin(); endIt != endSequences2.end(); ++endIt)
        {
            if(*startIt < *endIt and (*endIt-*startIt)%3 == 0)
            {
                DnaSequence consensusSequence = slice(*startIt -1, *endIt +1);
                consensusSequences.push_back(consensusSequence);
            }
        }

        for(std::list<size_t >::iterator endIt=endSequences3.begin(); endIt != endSequences3.end(); ++endIt)
        {
            if(*startIt < *endIt and (*endIt-*startIt)%3 == 0)
            {
                DnaSequence consensusSequence = slice(*startIt -1, *endIt +1);
                consensusSequences.push_back(consensusSequence);
            }
        }
    }

    return consensusSequences;
}


void DnaSequence::writeDna(const IWriter& writer)const
{
    writer.write((char*)m_dnaSequence);
}


bool DnaSequence::isValidDna(const char* dnaSequence)const
{
    return strlen(dnaSequence) == strspn( dnaSequence, "ACGT");
}


DnaSequence::DnaSequence(size_t length)
{
    m_dnaSequence = new Nucleotide[length];
    m_length = length;
}





static bool dnaSeqCmp(const DnaSequence &dna1, const DnaSequence &dna2)
{
    size_t i=0;

    while(i < dna1.getLength()-1 && i < dna2.getLength()-1 && dna1[i] == dna2[i])
    {
        i++;
    }

    return dna1[i] - dna2[i];
}