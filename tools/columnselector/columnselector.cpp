//
//  csvcolumnselector.cpp
//

#include "CsvOperations.h"
#include "StringOperations.h"
#include "parameters.h"



void showHelp()
{
  std::cout << "usage- csvcolumnselector [--path <path>] [--output_path <output path>] [--columns COLUMNS]\n\n" 
  "The csvcolumnselector utility allows you to " 
  "select and save only particular columns of a csv file.\n";
}

int main(int argc, char** argv)
{
  parameters::ParameterSet pset = parameters::parse_arguments(argc, argv);
  
  if (pset.showHelp == true)
  {
    showHelp();
    return 0;
  }
  
  parameters::verify_parameters(pset, true);
  
  CsvFile::Ptr csvFile(CsvFile::read_data(pset.filePath));
  
  csvFile->printSize("input");
  
  csv_operations::edit_columns(csvFile, pset.colsToUse);
  
  csvFile->printSize("output");
  
  CsvFile::write_data(csvFile, pset.outputPath);
  
  return 0;
}

