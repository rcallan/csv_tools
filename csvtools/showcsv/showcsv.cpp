//
//  showcsv.cpp
//

#include "csv_operations.h"
#include "string_operations.h"
#include "parameters.h"

using namespace std;


void showHelp()
{
  cout << "usage- showcsv [--path <path>] [--print_values off || on]" << endl << endl
    << "The showcsv tool prints the number of rows and columns and (optionally) all "
    << "the values of the csv file to the standard output." << endl;
}


int main(int argc, char** argv)
{
  parameters::parameter_set parameterSet = parameters::parse_arguments(argc, argv);
  
  if (parameterSet.showHelp == true)
  {
    showHelp();
    return 0;
  }
  
  parameters::verify_parameters(parameterSet);
  
  csv_file::Ptr csvFile(csv_file::read_data(parameterSet.filePath));
  
  csvFile->printSize("input file");
  
  if (parameterSet.printValues)
    csv_operations::print_csv_values(*csvFile);
  
}

