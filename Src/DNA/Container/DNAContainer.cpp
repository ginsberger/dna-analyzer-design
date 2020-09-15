
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

const DNAMetaData* DNAContainer::operator[](size_t _id) {
//    std::cout << m_idMap.find(_id) << std::endl;
    return m_idMap[_id];
}

size_t DNAContainer::operator[](const std::string &name) {
    return m_nameMap[name];
}





