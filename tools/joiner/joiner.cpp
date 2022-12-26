//
//  csvjointool.cpp
//

#include "CsvOperations.h"
#include "StringOperations.h"
#include "parameters.h"



void showHelp()
{
  std::cout << "usage- csvjointool [--path <path>] [--path2 <second path>] [--output_path <output path>] " 
  "[--columns_to_join_on COLUMNKEYS] [--operation OPERATION]\n\n" 
  "The csvjointool utility performs inner and outer joins on csv files.\n";
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
  
  // read csv files
  CsvFile::Ptr csvFile(CsvFile::read_data(pset.filePath));
  CsvFile::Ptr csvFile2(CsvFile::read_data(pset.filePath2));
  
  csvFile->printSize("first input file");
  csvFile->printSize("second input file");

  auto start = std::chrono::steady_clock::now();
  
  CsvFile::PtrC outputCsvFile = csv_operations::join_data_sets(*csvFile, *csvFile2, pset.colsToUse, pset.operation);

  auto end = std::chrono::steady_clock::now();
  auto diff = end - start;
  
  outputCsvFile->printSize("output file");
  
  CsvFile::write_data(outputCsvFile, pset.outputPath);
  
  std::cout << "it took " << std::chrono::duration <double, std::milli> (diff).count() << " ms to complete the operation" << std::endl;
  
  return 0;
}

