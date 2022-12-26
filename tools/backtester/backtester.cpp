//
//  backtester.cpp
//

#include "CsvOperations.h"
#include "StringOperations.h"
#include "parameters.h"

void showHelp()
{
  std::cout << "usage- backtester [--path <path>] [--output_path <output path>] [--columns COLUMNS]" 
  "\n\n" 
  "The backtester allows you to see how certain strategies would have worked in the past by using historical data\n";
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
    
    // read csv file
    CsvFile::Ptr csvFile(CsvFile::read_data(pset.filePath));
    
    csvFile->printSize("input");

    // keep track of total operation time
    auto start = std::chrono::steady_clock::now();
    
    // btester not implemented yett

    auto end = std::chrono::steady_clock::now();
    auto diff = end - start;

    // CsvFile::write_data(*outputcsvFile, pset.outputPath);
    
    std::cout << "it took " << std::chrono::duration <double, std::milli> (diff).count() << " ms to complete the operation" << std::endl;
    
    return 0;
}