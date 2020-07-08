
#ifndef DNASEQUENCE_STRINGHASH_H
#define DNASEQUENCE_STRINGHASH_H

#include <string>
#include <hash_map>
namespace __gnu_cxx {
    template <> struct hash<std::string> {
        size_t operator()(std::string const & s) const {
            hash<const char *> h;
            return h(s.c_str());
        }
    };
}

#endif //DNASEQUENCE_STRINGHASH_H
