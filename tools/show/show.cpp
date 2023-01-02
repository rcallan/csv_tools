//
//  showcsv.cpp
//

#include "CsvOperations.h"
#include "StringOperations.h"
#include "parameters.h"
#include <argparse/argparse.hpp>

// #include <sys/sysctl.h>

void showHelp()
{
  std::cout << "usage- showcsv [--path <path>] [--print_values off || on]\n\n" 
  "The showcsv tool prints the number of rows and columns and (optionally) all " 
  "the values of the csv file to the standard output.\n";
}

int main(int argc, char** argv)
{
  parameters::ParameterSet pset = parameters::parse_arguments(argc, argv);

  // trying out this argument parser package - would probably like to switch over to this or
  // something like it for parsing
  argparse::ArgumentParser program("show", "0.2.0");
  program.add_argument("-h", "--help")
    .default_value(false)
    .implicit_value(true)
    .nargs(0);

  program.add_argument("-p", "--path")
    .default_value("")
    .nargs(1);

  try {
    program.parse_args(argc, argv);
  }
  catch (const std::runtime_error& err) {
    std::cerr << err.what() << std::endl;
    std::cerr << program;
    std::exit(1);
  }

  if (program["--help"] == true)
  {
    showHelp();
    return 0;
  }
  
  parameters::verify_parameters(pset);

  CsvFile::Ptr csvFile(CsvFile::read_data(pset.filePath));
  
  csvFile->printSize("input file");
  
  if (pset.printValues)
    csv_operations::print_csv_values(csvFile);
  
  return 0;
}

