
#ifndef DNASEQUENCE_DNACONTAINER_H
#define DNASEQUENCE_DNACONTAINER_H

#include "../../Utils/stringHash.h"
#include "../MetaData/DNAmetaData/DNAMetaData.h"
#include "../../Utils/SharedPointer/SharedPtr.h"

class DNAContainer{
public:
    void insert(DNAMetaData* metaData);
    static DNAContainer& getDnaData();

    size_t getIdByName(const std::string& name);
//    const DNAMetaData* getDNAByID(size_t id)const ;
    DNAMetaData* operator[](size_t _id);
    size_t operator[](const std::string &name);
    void setNameMap(const std::string& prevName, const std::string& newName);

private:
    __gnu_cxx::hash_map<size_t, SharedPtr<DNAMetaData> > m_idMap;
    __gnu_cxx::hash_map<std::string, size_t > m_nameMap;
    size_t m_id;
    DNAContainer(): m_id(1){}
    DNAContainer(const DNAContainer&):m_id(1){}

};


#endif //DNASEQUENCE_DNACONTAINER_H
