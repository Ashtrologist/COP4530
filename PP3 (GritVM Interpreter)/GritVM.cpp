#ifndef GRITVM_CPP
#define GRITVM_CPP
#include "GritVM.hpp"


STATUS GritVM::load(const std::string filename, const std::vector<long> &initialMemory){

    std::fstream input;
    input.open(filename);


    input.close();

}

#endif