//
//  csvarith.cpp
//

#include "csv_operations.h"
#include "string_operations.h"
#include "parameters.h"

using namespace std;

typedef csv_file DataType;


void showHelp()
{
  cout << "usage- csvarith [--path <path>] [--output_path <output path>] [--columns COLUMNS]"
    << "[--operator OPERATOR]" << endl << endl << "The csvarith utility allows you to perform column "
    << "arithmetic on csv files." << endl;
}

int main(int argc, char** argv)
{
  // keep track of total run time
  clock_t start;
  double duration;
  start = clock();
  
  parameters::parameter_set parameterSet = parameters::parse_arguments(argc, argv);
  
  if (parameterSet.showHelp == true)
  {
    showHelp();
    return 0;
  }
  
  parameters::verify_parameters(parameterSet, true);
  
  // read csv file
  DataType::Ptr csvFile(DataType::read_data(parameterSet.filePath));
  
  csvFile->printSize("input");
  
  DataType::Ptr outputcsvFile = csv_operations::perform_column_op(csvFile, parameterSet.myoper,
                                                         parameterSet.colsToUse);
  csv_file::write_data(*outputcsvFile, parameterSet.outputPath);
  
  duration = (clock() - start) / (double) CLOCKS_PER_SEC;
  cout << "it took " << duration << " seconds to complete the operation" << endl;
  
  return 0;
}

