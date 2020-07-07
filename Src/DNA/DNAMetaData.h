
#ifndef DNASEQUENCE_DNAMETADATA_H
#define DNASEQUENCE_DNAMETADATA_H

#include "Status.h"
#include "DnaSequence.h"


class DNAMetaData {
public:
    DNAMetaData(const std::string& name, const IReader& reader);

    std::string getName()const { return m_name;}
    void setName(const std::string& name){m_name = name;}
//    operator const DnaSequence&()const { return m_dna;}

    //Status methods
    std::string getStatus()const { return m_status.getStatus();}
    void setStatus(EStatus status){m_status.setStatus(status);}

    //DNASequence public methods
    DnaSequence& operator=(const DNAMetaData& dnaMetaData) { return m_dna.operator=(dnaMetaData.m_dna);}
    friend std::ostream& operator<<(std::ostream& os, const DNAMetaData& dnaMetaData) { return operator<<(os,dnaMetaData.m_dna);}
    Nucleotide& operator[](size_t index)const { return m_dna.DnaSequence::operator[](index);}
    size_t getLength()const { return m_dna.getLength();}
    DnaSequence slice(size_t start,size_t end)const { return m_dna.slice(start, end);}
    DnaSequence getDnaPaired()const { return m_dna.getDnaPaired();}
    size_t find(const DNAMetaData& dnaMetaData, size_t start=0)const { return m_dna.find(dnaMetaData.m_dna, start);}
    size_t count(const DNAMetaData& dnaMetaData)const { return m_dna.count(dnaMetaData.m_dna);}
    std::list<size_t> findAll(const DNAMetaData& dnaMetaData)const { return m_dna.findAll(dnaMetaData.m_dna);}
    std::list<DnaSequence> findConsensusSequences() { return m_dna.findConsensusSequences();}
    void writeDna(const IWriter& writer)const {m_dna.writeDna(writer);}

private:
    DnaSequence m_dna;
    Status m_status;
    std::string m_name;
};


#endif //DNASEQUENCE_DNAMETADATA_H
