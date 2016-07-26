//
//  csvcolumnselector.cpp
//

#include "csv_operations.h"
#include "string_operations.h"
#include "parameters.h"

using namespace std;

void showHelp()
{
  cout << "usage- csvcolumnselector [--path <path>] [--output_path <output path>] [--columns COLUMNS]\n\n" 
  "The csvcolumnselector utility allows you to " 
  "select and save only particular columns of a csv file.\n";
}

int main(int argc, char** argv)
{
  parameters::parameter_set parameterSet = parameters::parse_arguments(argc, argv);
  
  if (parameterSet.showHelp == true)
  {
    showHelp();
    return 0;
  }
  
  parameters::verify_parameters(parameterSet, true);
  
  csv_file::Ptr csvFile(csv_file::read_data(parameterSet.filePath));
  
  csvFile->printSize("input");
  
  csv_operations::edit_columns(csvFile, parameterSet.colsToUse);
  
  csvFile->printSize("output");
  
  csv_file::write_data(*csvFile, parameterSet.outputPath);
  
  return 0;
}

