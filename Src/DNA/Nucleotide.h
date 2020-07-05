

#ifndef DNASEQUENCE_NUCLEOTIDE_H
#define DNASEQUENCE_NUCLEOTIDE_H


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


#endif //DNASEQUENCE_NUCLEOTIDE_H
