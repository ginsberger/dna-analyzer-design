
#include "DNAContainer.h"
#include "SharedPtr.h"

void DNAContainer::insert(DNAMetaData* metaData)
{
    m_nameMap.insert(std::pair<std::string, size_t >(metaData->getName(),m_id));
    m_idMap.insert(std::pair<size_t, SharedPtr<DNAMetaData> >(m_id, metaData));
    ++m_id;
}

DNAContainer& DNAContainer::getDnaData()
{
    static DNAContainer dnaHash;
    return dnaHash;
}

size_t DNAContainer::getIdByName(const std::string& name)
{
    return m_nameMap[name];
}

DNAMetaData* DNAContainer::operator[](size_t _id){
    return m_idMap[_id].getPtr();
}

size_t DNAContainer::operator[](const std::string &name) {
    return m_nameMap[name];
}

void DNAContainer::setNameMap(const std::string &prevName, const std::string &newName) {
    m_nameMap[newName] = m_nameMap[prevName];
    m_nameMap.erase(prevName);
}

