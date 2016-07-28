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
#include "csv_file.h"
#include "parallel.h"

using namespace std;

namespace csv_operations
{
  
  vector<unsigned> get_bounds(unsigned size, unsigned numRows, unsigned numColumns, unsigned numSubsets);
  
  void verify_data_format(const csv_file& csvFile);
  
  csv_file::Ptr do_arith_operation_subset(csv_file::Ptr csvFile, function<double(double, double)> myoper,
                                          unsigned firstRow, unsigned lastRow, unsigned firstCol, unsigned secondCol);

  class PerformColumnOpSubsetBody : public parallel::ParallelLoopBody
  {
  public:
    PerformColumnOpSubsetBody(csv_file::Ptr _csvFile, function<double(double, double)> _myoper,
                                          unsigned _firstRow, unsigned _lastRow, unsigned _firstCol, unsigned _secondCol)
    {
      csvFile = _csvFile;
      myoper = _myoper;
      firstRow = _firstRow;
      lastRow = _lastRow;
      firstCol = _firstCol;
      secondCol = _secondCol;

      newNumColumns = csvFile->get_num_columns();
    }

    csv_file::Ptr csvFile; 
    function<double(double, double)> myoper; 
    unsigned firstRow; 
    unsigned lastRow; 
    unsigned firstCol; 
    unsigned secondCol;

    unsigned newNumColumns;

    void operator()( const parallel::Range& range ) const
    {
      for (unsigned i = range.start; i < range.end; ++i)
      {
        csvFile->values(i, newNumColumns - 1) = to_string(myoper(stod(csvFile->values(i, firstCol)),
                                                                  stod(csvFile->values(i, secondCol))));
      }
    }
    
  };

  csv_file::Ptr perform_column_op_subset(csv_file::Ptr csvFile, function<double(double, double)> myoper,
                                         unsigned firstRow, unsigned lastRow, vector<string> colsToUse);
  
  csv_file::Ptr perform_column_op(csv_file::Ptr csvFile, function<double(double, double)> myoper,
                                  vector<string> colsToUse);
  
  void show_single_column_stats(vector<double>& values, unsigned col_idx, string otherStat);
  
  void show_multiple_column_stats(const csv_file& csvFile, vector<string> colsToUse, string otherStat);
  
  void edit_columns(csv_file::Ptr csvFile, vector<string> colsToUse);
  
  void print_csv_values(const csv_file::Ptr csvFile);
  
  csv_file::Ptr join_data_sets(const csv_file& csvFile, const csv_file& csvFile2, vector<string> colToUse,
                               string operation);
  
  
};


#endif /* defined(____csv_operations__) */
