//
//  showcsv.cpp
//

#include "CsvOperations.h"
#include "StringOperations.h"
#include "parameters.h"

// #include <sys/sysctl.h>



void showHelp()
{
  std::cout << "usage- showcsv [--path <path>] [--print_values off || on]\n\n" 
  "The showcsv tool prints the number of rows and columns and (optionally) all " 
  "the values of the csv file to the standard output.\n";
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
  
  csvFile->printSize("input file");
  
  if (pset.printValues)
    csv_operations::print_csv_values(csvFile);
  
  return 0;
}

