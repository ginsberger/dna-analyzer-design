//
// Created by a on 6/1/20.
//

#ifndef DNASEQUENCE_DNASEQUENCE_H
#define DNASEQUENCE_DNASEQUENCE_H

#include <iostream> //size_t
#include <list>
class IReader;
class IWriter;


class DnaSequence {

private:
    class Nucleotide{
    public:
        Nucleotide(char nucleotide);
        Nucleotide():m_nucleotide('\0'){};
        Nucleotide operator=(Nucleotide nucleotide);
        operator char (){ return m_nucleotide;}
        bool operator==(const Nucleotide& other);
        bool operator!=(const Nucleotide& other);
        Nucleotide getNucleotidePair()const;

    private:
        char m_nucleotide;
        bool isValidNucleotide(Nucleotide nucleotide);
    };


public:
    DnaSequence(const std::string& dnaSequence);
    DnaSequence(const char* dnaSequence);
    DnaSequence(const IReader& reader);
    DnaSequence(const DnaSequence& dnaSequence);
    ~DnaSequence();

    DnaSequence& operator=(const DnaSequence& dnaSequence);
    friend std::ostream& operator<<(std::ostream& os, const DnaSequence& dnaSequence);
    Nucleotide& operator[](size_t index)const;
    size_t getLength()const;
    DnaSequence slice(size_t start,size_t end)const;
    DnaSequence getDnaPaired()const;
    size_t find(const DnaSequence& dnaSubSequence, size_t start=0)const;
    size_t count(const DnaSequence& dnaSubSequence)const;
    std::list<size_t> findAll(const DnaSequence& dnaSubSequence)const;
    std::list<DnaSequence> findConsensusSequences();
    void writeDna(const IWriter& writer)const;

protected:
    friend class TestDnaSequence;
    bool isValidDna(const char* dnaSequence)const ;
    void initDnaSequence(const char* dnaSequence);
    DnaSequence(size_t length);

private:
    Nucleotide* m_dnaSequence;
    size_t m_length;
};


bool operator==(const DnaSequence& dnaSequence1,const DnaSequence& dnaSequence2);
bool operator!=(const DnaSequence& dnaSequence1, const DnaSequence& dnaSequence2);

#endif //DNASEQUENCE_DNASEQUENCE_H
