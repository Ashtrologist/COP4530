#ifndef GRITVM_HPP
#define GRITVM_HPP
#include "GritVMBase.hpp"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

 class GritVM : public GritVMInterface{
      public:
      
            STATUS load(const std::string filename, const std::vector<long> &initialMemory);
            STATUS run();
            std::vector<long> getDataMem();
            STATUS reset();


};

#endif