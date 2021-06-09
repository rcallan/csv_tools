//
//  backtester.cpp
//

#include "csv_operations.h"
#include "string_operations.h"
#include "parameters.h"

void showHelp()
{
  cout << "usage- backtester [--path <path>] [--output_path <output path>] [--columns COLUMNS]" 
  "\n\n" 
  "The backtester allows you to see how certain strategies would have worked in the past by using historical data\n";
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
    csv_file::Ptr csvFile(csv_file::read_data(parameterSet.filePath));
    
    csvFile->printSize("input");
    
    csv_file::Ptr outputcsvFile = csv_operations::perform_column_op(csvFile, parameterSet.myoper, 
                                                                        parameterSet.colsToUse);
    csv_file::write_data(*outputcsvFile, parameterSet.outputPath);
    
    duration = (clock() - start) / (double) CLOCKS_PER_SEC;
    cout << "it took " << duration << " seconds to complete the operation" << endl;
    
    return 0;
}