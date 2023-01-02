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

  // get the default compute device
  boost::compute::device gpu = boost::compute::system::default_device();

  // create a compute context and command queue
  boost::compute::context ctx(gpu);
  
  CsvFile::Ptr csvFile(CsvFile::read_data(pset.filePath));
  
  csvFile->printSize("input");

  boost::compute::vector<std::string> cols(pset.colsToUse);
  
  csv_operations::edit_columns(csvFile, cols);
  
  csvFile->printSize("output");
  
  CsvFile::write_data(csvFile, pset.outputPath);
  
  return 0;
}

