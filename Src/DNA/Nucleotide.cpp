
#include "Nucleotide.h"
#include <iostream>

Nucleotide::Nucleotide(char nucleotide): m_nucleotide(nucleotide){}


Nucleotide Nucleotide::operator=(Nucleotide nucleotide)
{
    if(!isValidNucleotide(nucleotide))
        throw std::invalid_argument("error: Illegal nucleotide");
    m_nucleotide = nucleotide.m_nucleotide;
    return *this;
}


bool Nucleotide::operator==(const Nucleotide& other)
{
    return m_nucleotide == other.m_nucleotide;
}


bool Nucleotide::operator!=(const Nucleotide& other)
{
    return m_nucleotide != other.m_nucleotide;
}


bool Nucleotide::isValidNucleotide(Nucleotide nucleotide)
{
    static std::string validNucleotids = "ACGT";
    return validNucleotids.find(nucleotide) != std::string::npos;
}


Nucleotide Nucleotide::getNucleotidePair()const
{
    if(m_nucleotide == 'A')
        return 'T';
    if(m_nucleotide == 'T')
        return 'A';
    if(m_nucleotide == 'C')
        return 'G';
    return 'C';
}

