//
//  csvarith.cpp
//

#include "CsvOperations.h"
#include "StringOperations.h"
#include "parameters.h"


void showHelp()
{
  std::cout << "usage- csvarith [--path <path>] [--output_path <output path>] [--columns COLUMNS]" 
  "[--operator OPERATOR]\n\n" 
  "The csvarith utility allows you to perform column arithmetic on csv files. Commands to use for the\n"
  "operator are addition, subtraction, multiplication and division. Also note that the columns are zero indexed values\n";
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
  
  // read csv file
  CsvFile::Ptr csvFile(CsvFile::read_data(pset.filePath));
  
  csvFile->printSize("input");

  // keep track of total operation time
  auto start = std::chrono::steady_clock::now();
  
  CsvFile::PtrC outputcsvFile = csv_operations::perform_column_op(csvFile, pset.myoper, pset.colsToUse);

  auto end = std::chrono::steady_clock::now();
  auto diff = end - start;

  CsvFile::write_data(outputcsvFile, pset.outputPath);

  std::cout << "it took " << std::chrono::duration <double, std::milli> (diff).count() << " ms to complete the operation" << std::endl;
  
  return 0;
}

