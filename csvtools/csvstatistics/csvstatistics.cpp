//
//  csvstatistics.cpp
//

#include "csv_operations.h"
#include "string_operations.h"
#include "parameters.h"

using namespace std;

void showHelp()
{
  cout << "usage- csvstatistics [--path <path>] [--columns COLUMNS] [--other_stat"
    << " OTHERSTATISTIC]" << endl << endl << "optional arguments" << endl << endl
    << "--other_stat - provides desired information about the columns instead of"
    << " default statistics. available arguments are standard_deviation, correlation_coefficient,   and none (default)"
    << endl << endl << "The csvstatistics tool shows some statistics about"
    << " specified columns of a csv file." << endl;
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

  csvFile->printSize("input data");
  
  csv_operations::show_multiple_column_stats(*csvFile, parameterSet.colsToUse, parameterSet.otherStat);
  
}

