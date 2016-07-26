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
#include "string_operations.h"

using namespace std;

namespace parameters
{
  
  struct parameter_set
  {
    parameter_set()
    {
      showHelp = false;
      filePath = nullptr;
      filePath2 = nullptr;
      outputPath = nullptr;
      myoper = nullptr;
      numThreads = thread::hardware_concurrency();
      otherStat = "none";
      printValues = true;
      numOptions = 0;
    }
    
    bool showHelp;
    char* filePath;
    char* filePath2;
    char* outputPath;
    vector<string> colsToUse;
    string operation;
    function<double(double, double)> myoper;
    unsigned numThreads;
    string otherStat;
    bool printValues;
    unsigned numOptions;
  };
  
  parameter_set parse_arguments(int argc, char** argv);
  
  void verify_parameters(const parameter_set& parameterSet, bool outputPathRequired = false);
  
}

#endif /* defined(____parameters__) */

