
#ifndef DNASEQUENCE_DNACONTEINER_H
#define DNASEQUENCE_DNACONTEINER_H

#include <map>
#include "DNAMetaData.h"
#include "DNAData.h"

class DNAConteiner:{
public:
    void insert(const std::string& name, const IReader& reader, size_t id = m_id);
    static DNAData& getDnaData(){
        static DNAConteiner dnaHash;
        return dnaHash;
    }

private:
    std::map<size_t, DNAMetaData> m_idMap;
    std::map<std::string, size_t > m_nameMap;
    size_t m_id;
    DNAConteiner(): m_id(1){}
    DNAConteiner(const DNAConteiner&){}
    const DNAConteiner&operator=(const DNAConteiner& )

};


#endif //DNASEQUENCE_DNACONTEINER_H
