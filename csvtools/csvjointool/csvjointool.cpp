//
//  csvjointool.cpp
//

#include "csv_operations.h"
#include "string_operations.h"
#include "parameters.h"

using namespace std;

int main(int argc, char** argv)
{
  clock_t start;
  double duration;
  start = clock();
  
  parameters::parameter_set parameterSet = parameters::parse_arguments(argc, argv);
  
  if (parameterSet.showHelp == true)
  {
    cout << "usage- csvjointool [--path <path>] [--path2 <second path>] [--output_path <output path>] "
    << "[--columns_to_join_on COLUMNKEYS] [--operation OPERATION]" << endl
    << endl << "The csvjointool utility performs inner and outer joins on csv files." << endl;
    return 0;
  }
  
  parameters::verify_parameters(parameterSet, true);
  
  // read csv files
  csv_file::Ptr csvFile(csv_file::read_data(parameterSet.filePath));
  csv_file::Ptr csvFile2(csv_file::read_data(parameterSet.filePath2));
  
  cout << "size of first input file is " << csvFile->get_num_rows() << " rows by "
  << csvFile->get_num_columns() << " columns" << endl;
  cout << "size of second input file is " << csvFile2->get_num_rows() << " rows by "
  << csvFile2->get_num_columns() << " columns" << endl;
  
  csv_file::Ptr outputCsvFile = csv_operations::join_data_sets(*csvFile, *csvFile2, parameterSet.colsToUse,
                                                             parameterSet.operation);
  
  cout << "size of output file is " << outputCsvFile->get_num_rows() << " rows by "
  << outputCsvFile->get_num_columns() << " columns" << endl;
  
  csv_file::write_data(*outputCsvFile, parameterSet.outputPath);
  
  duration = (clock() - start) / (double) CLOCKS_PER_SEC;
  cout << "it took " << duration << " seconds to complete the operation" << endl;
  
}

