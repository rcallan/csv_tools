//
//  csvcolumnselector.cpp
//

#include "csv_operations.h"
#include "string_operations.h"
#include "parameters.h"

using namespace std;

int main(int argc, char** argv)
{
  parameters::parameter_set parameterSet = parameters::parse_arguments(argc, argv);
  
  if (parameterSet.showHelp == true)
  {
    cout << "usage- csvcolumnselector [--path <path>] [--output_path <output path>] [--columns COLUMNS]" << endl
    << endl << "The csvcolumnselector utility allows you to "
    << "select and save only particular columns of a csv file." << endl;
    return 0;
  }
  
  parameters::verify_parameters(parameterSet, true);
  
  csv_file::Ptr csvFile(csv_file::read_data(parameterSet.filePath));
  
  cout << "size of input is " << csvFile->get_num_rows() << " rows by "
  << csvFile->get_num_columns() << " columns" << endl;
  
  csv_operations::edit_columns(csvFile, parameterSet.colsToUse);
  
  cout << "size of output is " << csvFile->get_num_rows() << " rows by "
  << csvFile->get_num_columns() << " columns" << endl;
  
  csv_file::write_data(*csvFile, parameterSet.outputPath);
  
}

