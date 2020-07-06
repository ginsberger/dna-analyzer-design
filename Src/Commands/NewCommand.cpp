
#include "../DNA/DNAData.h" // until implementation of ICommand
#include "NewCommand.h"

NewCommand::NewCommand(const Parsing& params):m_params(params){}


char* NewCommand::run(const Parsing& params)
{
    std::vector<std::string> param = params.getParams();
    std::string name;
    if(3 == param.size())
        name = param.pop_back();
    std::string dna = param.pop_back();

    DNAData::getDnaData().insert(name,dna);
}
