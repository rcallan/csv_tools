//
//  showcsv.cpp
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
    cout << "usage- showcsv [--path <path>] [--print_values off || on]" << endl << endl
    << "The showcsv tool prints the number of rows and columns and (optionally) all "
    << "the values of the csv file to the standard output." << endl;
    return 0;
  }
  
  parameters::verify_parameters(parameterSet);
  
  csv_file::Ptr csvFile(csv_file::read_data(parameterSet.filePath));
  
  cout << "size of input data is " << csvFile->get_num_rows() << " rows by "
  << csvFile->get_num_columns() << " columns" << endl;
  
  if (parameterSet.printValues)
    csv_operations::print_csv_values(*csvFile);
  
}

