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
#include <memory>
#include "csv_file.h"

using namespace std;


namespace csv_operations
{
  
  vector<int> get_bounds(int size, int numRows, int numColumns, int numSubsets);
  
  void verify_data_format(const csv_file &csvFile);
  
  csv_file::Ptr do_arith_operation_subset(csv_file::Ptr csvFile, function<double(double, double)> myoper,
                                          int firstRow, int lastRow, int firstCol, int secondCol);
  
  csv_file::Ptr perform_column_op_subset(csv_file::Ptr csvFile, function<double(double, double)> myoper,
                                         int firstRow, int lastRow, vector<string> colsToUse);
  
  csv_file::Ptr perform_column_op(csv_file::Ptr csvFile, function<double(double, double)> myoper,
                                  vector<string> colsToUse);
  
  void show_single_column_stats(vector<double> values, int col_idx, string otherStat);
  
  void show_multiple_column_stats(const csv_file &csvFile, vector<string> colsToUse, string otherStat);
  
  void edit_columns(csv_file::Ptr& csvFile, vector<string> colsToUse);
  
  void print_csv_values(const csv_file& csvFile);
  
  csv_file::Ptr join_data_sets(const csv_file &csvFile, const csv_file &csvFile2, vector<string> colToUse,
                               string operation);
  
  
};


#endif /* defined(____csv_operations__) */
