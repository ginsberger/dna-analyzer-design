
#include "DNAMetaData.h"

DNAMetaData::DNAMetaData(const std::string& name, const IReader& reader):m_dna(reader), m_status(), m_name(name){}

