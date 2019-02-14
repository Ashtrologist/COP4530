#ifndef GRITVM_HPP
#define GRITVM_HPP

#include "GritVMBase.hpp"
#include <vector>
#include <string>

 class GritVM : public GritVMInterface{
     
      STATUS load(const std::string filename, const std::vector<long> &initialMemory);
      STATUS run();
      std::vector<long> getDataMem();
      STATUS reset();


};

#endif