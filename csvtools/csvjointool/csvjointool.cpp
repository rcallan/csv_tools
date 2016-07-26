//
//  csvjointool.cpp
//

#include "csv_operations.h"
#include "string_operations.h"
#include "parameters.h"

using namespace std;

void showHelp()
{
  cout << "usage- csvjointool [--path <path>] [--path2 <second path>] [--output_path <output path>] " 
  "[--columns_to_join_on COLUMNKEYS] [--operation OPERATION]\n\n" 
  "The csvjointool utility performs inner and outer joins on csv files.\n";
}

int main(int argc, char** argv)
{
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
  
  // read csv files
  csv_file::Ptr csvFile(csv_file::read_data(parameterSet.filePath));
  csv_file::Ptr csvFile2(csv_file::read_data(parameterSet.filePath2));
  
  csvFile->printSize("first input file");
  csvFile->printSize("second input file");
  
  csv_file::Ptr outputCsvFile = csv_operations::join_data_sets(*csvFile, *csvFile2, parameterSet.colsToUse,
                                                             parameterSet.operation);
  
  outputCsvFile->printSize("output file");
  
  csv_file::write_data(*outputCsvFile, parameterSet.outputPath);
  
  duration = (clock() - start) / (double) CLOCKS_PER_SEC;
  cout << "it took " << duration << " seconds to complete the operation" << endl;
  
  return 0;
}

