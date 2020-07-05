
#ifndef DNASEQUENCE_DNAHASH_H
#define DNASEQUENCE_DNAHASH_H

#include <map>
#include "DNAMetaData.h"


class DNAHash {
public:
    void insert(const std::string& name, const IReader& reader, size_t id = m_id);
private:
    std::map<size_t, DNAMetaData> m_idMap;
    std::map<std::string, size_t > m_nameMap;
    static size_t m_id;
};


#endif //DNASEQUENCE_DNAHASH_H
