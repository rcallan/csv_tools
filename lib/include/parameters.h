//
//  parameters.h
//

#ifndef ____parameters__
#define ____parameters__

#include <iostream>
#include <vector>
#include <functional>
#include <thread>
#include <cstring>
#include "StringOperations.h"



namespace parameters
{
  
  struct ParameterSet
  {
    ParameterSet()
    {
      showHelp = false;
      numThreads = std::thread::hardware_concurrency();
      otherStat = "none";
      printValues = true;
      numOptions = 0;
    }
    
    bool showHelp;
    char* filePath { };
    char* filePath2 { };
    char* outputPath { };
    std::vector<std::string> colsToUse;
    std::string operation;
    std::function<double(double, double)> myoper { };
    unsigned numThreads;
    std::string otherStat;
    bool printValues;
    unsigned numOptions;
  };
  
  ParameterSet parse_arguments(int argc, char** argv);
  
  void verify_parameters(const ParameterSet& parameterSet, bool outputPathRequired = false);
  
}

#endif /* defined(____parameters__) */

