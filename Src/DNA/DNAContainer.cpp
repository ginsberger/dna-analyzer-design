
#include "DNAContainer.h"


void DNAContainer::insert(DNAMetaData* metaData)
{
    m_nameMap.insert(std::pair<std::string, size_t >(metaData->getName(),m_id));
    m_idMap.insert(std::pair<size_t, DNAMetaData *>(m_id, metaData));
    ++m_id;
}

DNAContainer& DNAContainer::getDnaData()
{
    static DNAContainer dnaHash;
    return dnaHash;
}

size_t DNAContainer::getIdByName(std::string name)
{
    return m_nameMap[name];
}

//const DNAMetaData& DNAContainer::getDNAByID(size_t id)
//{
//    return m_idMap[id];
//}



