
#ifndef DNASEQUENCE_DNAMETADATA_H
#define DNASEQUENCE_DNAMETADATA_H

#include "Status.h"
#include "DnaSequence.h"

class DNAMetaData {
public:
    DNAMetaData(const std::string& name, const IReader& reader);

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

private:
    DnaSequence m_dna;
    Status m_status;
    std::string m_name;
};


#endif //DNASEQUENCE_DNAMETADATA_H
