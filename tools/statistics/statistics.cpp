//
//  csvstatistics.cpp
//

#include "CsvOperations.h"
#include "StringOperations.h"
#include "parameters.h"

void showHelp()
{
  std::cout << "usage- csvstatistics [--path <path>] [--columns COLUMNS] [--other_stat OTHERSTATISTIC]\n" 
  "optional arguments\n--other_stat - provides desired information about the columns instead of" 
  " default statistics. available arguments are standard_deviation, correlation_coefficient, " 
  "and none (default)\n\n" 
  "The csvstatistics tool shows some statistics about specified columns of a csv file.\n";
}

int main(int argc, char** argv)
{
  parameters::ParameterSet pset = parameters::parse_arguments(argc, argv);
  
  if (pset.showHelp == true)
  {
    showHelp();
    return 0;
  }
  
  parameters::verify_parameters(pset);
  
  CsvFile::Ptr csvFile(CsvFile::read_data(pset.filePath));

  csvFile->printSize("input data");
  
  csv_operations::show_multiple_column_stats(*csvFile, pset.colsToUse, pset.otherStat);
  
  return 0;
}

