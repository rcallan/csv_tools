//
//  csv_operations.h
//

#ifndef ____csv_operations__
#define ____csv_operations__

#include <iostream>
#include <string>
#include <fstream>
#include <unordered_set>
#include <functional>
#include <vector>
#include <algorithm>
#include "CsvFile.h"


namespace csv_operations
{
  
  std::vector<unsigned> get_bounds(unsigned size, unsigned numRows, unsigned numColumns, unsigned numSubsets);
  
  void verify_data_format(const CsvFile& csvFile);
  
  CsvFile::Ptr do_arith_operation_subset(
    CsvFile::Ptr csvFile, 
    std::function<double(double, double)> myoper,
    unsigned firstRow, 
    unsigned lastRow, 
    unsigned firstCol, 
    unsigned secondCol);

  CsvFile::Ptr perform_column_op_subset(
    CsvFile::Ptr csvFile, 
    std::function<double(double, double)> myoper,
    unsigned firstRow, 
    unsigned lastRow, 
    std::vector<std::string>& colsToUse);
  
  CsvFile::Ptr perform_column_op(
    CsvFile::Ptr csvFile, 
    std::function<double(double, double)> myoper,
    std::vector<std::string>& colsToUse);
  
  void show_single_column_stats(std::vector<double>& values, unsigned col_idx, std::string& otherStat);
  
  void show_multiple_column_stats(const CsvFile& csvFile, std::vector<std::string>& colsToUse, std::string& otherStat);
  
  void edit_columns(CsvFile::Ptr csvFile, std::vector<std::string>& colsToUse);
  
  void print_csv_values(CsvFile::Ptr csvFile);
  
  CsvFile::Ptr join_data_sets(const CsvFile& csvFile, 
    const CsvFile& csvFile2, 
    std::vector<std::string>& colToUse,
    std::string& operation);
  
  
}


#endif /* defined(____csv_operations__) */
