//
//  parameters.cpp
//

#include "parameters.h"

namespace parameters
{
  
  parameter_set parse_arguments(int argc, char** argv)
  {
    
    parameter_set parameterSet;
    string arg, optionArg;
    
    for (unsigned i = 1; i < argc; ++i)
    {
      arg = argv[i];
      
      if (arg == "--help")
      {
        parameterSet.showHelp = true;
        break;
      }
      if (arg.substr(0,2) == "--")
      {
        parameterSet.numOptions++;
        if (i < argc - 1)
        {
          optionArg = argv[i + 1];
        }
        if (i + 1 == argc || optionArg.substr(0,2) == "--")
        {
          cerr << "one of the options given is missing an argument" << endl;
          exit(1);
        }
      }
      if (arg == "--path")
      {
        parameterSet.filePath = argv[i+1];
      }
      else if (arg == "--path2")
      {
        parameterSet.filePath2 = argv[i+1];
      }
      else if (arg == "--output_path")
      {
        parameterSet.outputPath = argv[i+1];
      }
      else if (arg == "--columns" || arg == "--columns_to_join_on")
      {
        string_operations::split_line(optionArg, ",", parameterSet.colsToUse);
      }
      else if (arg == "--operation")
      {
        parameterSet.operation = argv[i+1];
      }
      else if (arg == "--print_values")
      {
        if (optionArg == "off")
        {
          parameterSet.printValues = false;
        }
      }
      if (arg == "--other_stat")
      {
        parameterSet.otherStat = argv[i + 1];
      }
      else if (arg == "--n_threads")
      {
        parameterSet.numThreads = stoi(argv[i+1]);
      }
      else if (arg == "--operator")
      {
        if (string(argv[i + 1]) == "addition")
        {
          parameterSet.myoper = std::plus<double>();
        }
        else if (string(argv[i + 1]) == "subtraction")
        {
          parameterSet.myoper = std::minus<double>();
        }
        else if (string(argv[i + 1]) == "multiplication")
        {
          parameterSet.myoper = std::multiplies<double>();
        }
        else if (string(argv[i + 1]) == "division")
        {
          parameterSet.myoper = std::divides<double>();
        }
      }
    }
    
    // we use one thread if above function returns zero
    if (parameterSet.numThreads == 0)
    {
      parameterSet.numThreads = 1;
    }
    
    cout << "number of options given is " << parameterSet.numOptions << endl;
    
    return parameterSet;
  }
  
  void verify_parameters(const parameter_set &parameterSet, bool outputPathNeeded)
  {
    if (parameterSet.numOptions == 0)
    {
      cerr << "arguments are required for the use of this tool" << endl;
      exit(1);
    }
    if (!parameterSet.filePath || parameterSet.filePath[0] == '\0')
    {
      cerr << "a path to input data must be provided" << endl;
      exit(1);
    }
    if (outputPathNeeded == true)
    {
      if (!parameterSet.outputPath || parameterSet.outputPath[0] == '\0')
      {
        cerr << "a path to where output data will be saved must provided" << endl;
        exit(1);
      }
    }
  }
  
}
