
#include "DNAConteiner.h"

size_t DNAConteiner::m_id=1;


void DNAConteiner::insert(const std::string& name, const IReader& reader, size_t id)
{
    m_idMap.insert(std::pair<size_t, DNAMetaData>(id, DNAMetaData(name,reader)));
    m_nameMap.insert(std::pair<std::string, size_t >(name,id));
}
