//
//  parameters.cpp
//

#include "parameters.h"

namespace parameters
{
  
  ParameterSet parse_arguments(int argc, char** argv)
  {
    ParameterSet parameterSet;
    
    for (int i = 1; i < argc; ++i)
    {
      
      if ( !strcmp(argv[i], "--help") )
      {
        parameterSet.showHelp = true;
        return parameterSet;
      }
      ++parameterSet.numOptions;
      if ( !strcmp(argv[i], "--path") )
      {
        parameterSet.filePath = argv[++i];
      }
      else if ( !strcmp(argv[i], "--path2") )
      {
        parameterSet.filePath2 = argv[++i];
      }
      else if ( !strcmp(argv[i], "--output_path") )
      {
        parameterSet.outputPath = argv[++i];
      }
      else if ( !strcmp(argv[i], "--columns") || !strcmp(argv[i], "--columns_to_join_on") )
      {
        std::string optionArg = argv[++i];
        string_operations::split_line(optionArg, ",", parameterSet.colsToUse);
      }
      else if ( !strcmp(argv[i], "--operation") )
      {
        parameterSet.operation = argv[++i];
      }
      else if ( !strcmp(argv[i], "--print_values") )
      {
        if ( !strcmp(argv[i + 1], "off") )
        {
          parameterSet.printValues = false;
        }
        ++i;
      }
      else if ( !strcmp(argv[i], "--other_stat") )
      {
        parameterSet.otherStat = argv[++i];
      }
      else if ( !strcmp(argv[i], "--n_threads") )
      {
        parameterSet.numThreads = std::stoi(argv[++i]);
      }
      else if ( !strcmp(argv[i], "--operator") )
      {
        if ( !strcmp(argv[i + 1], "addition") )
        {
          parameterSet.myoper = std::plus<double>();
        }
        else if ( !strcmp(argv[i + 1], "subtraction") )
        {
          parameterSet.myoper = std::minus<double>();
        }
        else if ( !strcmp(argv[i + 1], "multiplication") )
        {
          parameterSet.myoper = std::multiplies<double>();
        }
        else if ( !strcmp(argv[i + 1], "division") )
        {
          parameterSet.myoper = std::divides<double>();
        }
        ++i;
      }
    }
    
    // we use one thread if built in function returns zero
    if (parameterSet.numThreads == 0)
    {
      parameterSet.numThreads = 1;
    }

    std::cout << "number of options given is " << parameterSet.numOptions << std::endl;
    
    return parameterSet;
  }
  
  void verify_parameters(const ParameterSet &parameterSet, bool outputPathNeeded)
  {
    if (parameterSet.numOptions == 0)
    {
      std::cerr << "arguments are required for the use of this tool" << std::endl;
      exit(1);
    }
    if (!parameterSet.filePath || parameterSet.filePath[0] == '\0')
    {
      std::cerr << "a path to input data must be provided" << std::endl;
      exit(1);
    }
    if (outputPathNeeded == true)
    {
      if (!parameterSet.outputPath || parameterSet.outputPath[0] == '\0')
      {
        std::cerr << "a path to where output data will be saved must provided" << std::endl;
        exit(1);
      }
    }
  }
  
}
