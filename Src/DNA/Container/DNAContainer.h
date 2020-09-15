
#ifndef DNASEQUENCE_DNACONTAINER_H
#define DNASEQUENCE_DNACONTAINER_H

#include "../../Utils/stringHash.h"
#include "../MetaData/DNAmetaData/DNAMetaData.h"

class DNAContainer{
public:
    void insert(DNAMetaData* metaData);
    static DNAContainer& getDnaData();

    size_t getIdByName(std::string name);
//    const DNAMetaData* getDNAByID(size_t id)const ;
    const DNAMetaData* operator[](size_t _id) ;
    size_t operator[](const std::string &name);
private:
    __gnu_cxx::hash_map<size_t, DNAMetaData*> m_idMap;
    __gnu_cxx::hash_map<std::string, size_t > m_nameMap;
    size_t m_id;
    DNAContainer(): m_id(1){}
    DNAContainer(const DNAContainer&):m_id(1){}

};


#endif //DNASEQUENCE_DNACONTAINER_H