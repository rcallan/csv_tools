//
//  csv_operations.cpp
//

#include "csv_operations.h"
#include "string_operations.h"
#include "stats.h"

#define ARRAY_SIZE(array) (sizeof((array))/sizeof((array[0])))

typedef csv_file DataType;

namespace csv_operations
{
  // returns the indices that can be used to split the data up into equally sized pieces
  vector<int> get_bounds(int size, int numRows, int numColumns, int numSubsets)
  {
    vector<int> bounds(numSubsets);
    int numSubsetRows = numRows / numSubsets;
    int subsetSize = numSubsetRows * numColumns;
    int numRowsInLastSubset = numSubsetRows + numRows % numSubsetRows;
    
    //cout << "number of rows in last subset is " << numRowsInLastSubset << endl;
    
    for (int i = 0; i < numSubsets - 1; ++i)
    {
      bounds[i] = subsetSize * (i + 1);
    }
    
    subsetSize = numRowsInLastSubset * numColumns;
    bounds[numSubsets - 1] = size;
    
    return bounds;
  }
  
  // checks for infinite values in the csv file
  void verify_data_format(const DataType &csvFile)
  {
    for (int i = 0; i < csvFile.get_num_rows(); ++i)
    {
      for (int j = 0; j < csvFile.get_num_columns(); ++j)
      {
        if (csvFile.values(i, j) == "inf")
        {
          cerr << "input data should not contain infinite values" << endl;
          exit(1);
        }
      }
    }
  }
  
  // throws an exception if denominator is zero (currently not being used because c++11 handles
  // this case on its own)
  inline double double_div_er(double numerator, double denominator)
  {
    if (denominator == 0)
      throw std::overflow_error("divide by zero exception");
    
    return numerator / denominator;
  }
  
  DataType::Ptr do_arith_operation_subset(DataType::Ptr updatedcsvFile, function<double(double, double)> myoper,
                                          int firstRow, int lastRow, int firstCol, int secondCol)
  {
    int newNumColumns = updatedcsvFile->get_num_columns();
    int numRows = updatedcsvFile->get_num_rows();
    updatedcsvFile->set_num_columns(newNumColumns);
    
    updatedcsvFile->values.data_.resize(newNumColumns);
    updatedcsvFile->values.data_[newNumColumns - 1].resize(numRows);
    
    const DataType& csvFile = *updatedcsvFile;
    
    for (int i = firstRow; i < lastRow; ++i)
    {
      updatedcsvFile->values(i, newNumColumns - 1) = to_string(myoper(stod(csvFile.values(i, firstCol)),
                                                                      stod(csvFile.values(i, secondCol))));
    }
    
    return updatedcsvFile;
  }
  
  DataType::Ptr perform_column_op_subset(DataType::Ptr csvFile, function<double(double, double)> myoper,
                                         int firstRow, int lastRow, vector<string> colsToUse)
  {
    int firstCol = stoi(colsToUse[0]);
    int secondCol = stoi(colsToUse[1]);
    
    int numColumns = csvFile->get_num_columns();
    
    if (firstCol < 0 || firstCol > numColumns - 1
        || secondCol < 0 || secondCol > numColumns - 1)
    {
      throw std::out_of_range("one of the column indices is out of range");
    }
    
    return do_arith_operation_subset(csvFile, myoper, firstRow, lastRow, firstCol, secondCol);
  }
  
  DataType::Ptr perform_column_op(DataType::Ptr csvFile, function<double(double, double)> myoper, vector<string> colsToUse)
  {
    int firstCol = stoi(colsToUse[0]);
    int secondCol = stoi(colsToUse[1]);
    
    int numRows = csvFile->get_num_rows();
    int numColumns = csvFile->get_num_columns();
    
    if (firstCol < 0 || firstCol > numColumns - 1
        || secondCol < 0 || secondCol > numColumns - 1)
    {
      throw std::out_of_range("one of the column indices is out of range");
    }
    
    return do_arith_operation_subset(move(csvFile), myoper, 0, numRows, firstCol, secondCol);
  }
  
  // output the column index, minimum, maximum, median, and average values
  void show_single_column_stats(vector<double> column, int col_idx, string otherStat)
  {
    double columnSize = column.size();
    
    cout << "column " << col_idx << " - ";
    if (otherStat == "none")
    {
      cout << stats::get_min_element(column) << ", " << stats::get_max_element(column) << ", " << stats::get_median_value(column)
      << ", and " << stats::get_mean_value(column) << endl;
    }
    else if (otherStat == "standard_deviation")
    {
      cout << stats::get_standard_deviation(column) << endl;
    }
    
  }
  
  void show_multiple_column_stats(const DataType &csvFile, vector<string> colsToUse, string otherStat)
  {
    int numColumns = csvFile.get_num_columns();
    int numColstoUse = colsToUse.size();
    int columnIndex;
    
    // output stats for columns
    if (otherStat == "none")
    {
      cout << "stats (min, max, median, and average) for specified columns are" << endl;
    }
    else if (otherStat == "standard_deviation")
    {
      cout << "standard deviations for specified columns are" << endl;
    }
    else if (otherStat == "correlation_coefficient")
    {
      if (numColstoUse != 2)
      {
        throw std::invalid_argument("two columns should be specified to get correlation coefficient");
      }
      
      int firstColIdx = stoi(colsToUse[0]);
      int secondColIdx = stoi(colsToUse[1]);
      
      vector<double> firstCol = csvFile.get_column(firstColIdx);
      vector<double> secondCol = csvFile.get_column(secondColIdx);
      
      double correlationCoefficient = stats::get_correlation_coefficient(firstCol, secondCol);
      
      cout << "the correlation between columns " << firstColIdx
      << " and " << secondColIdx << " is " << correlationCoefficient << endl;
      return;
    }
    
    vector<double> currentColumn;
    for (int j = 0; j < numColstoUse; ++j)
    {
      columnIndex = stoi(colsToUse[j]);
      if (columnIndex < 0 || columnIndex > numColumns - 1)
      {
        throw std::invalid_argument("one of the column indices is out of range");
      }
      currentColumn = csvFile.get_column(columnIndex);
      show_single_column_stats(currentColumn, columnIndex, otherStat);
    }
  }
  
  // removes columns that are no longer desired
  void edit_columns(DataType::Ptr& csvFile, vector<string> colsToUse)
  {
    int numRows = csvFile->get_num_rows();
    int numColumns = csvFile->get_num_columns();
    int numOutputCols = colsToUse.size();
    
    unsigned count = 0;
    
    unordered_set<string> columns(make_move_iterator(colsToUse.begin()), make_move_iterator(colsToUse.end()));
    
    csvFile->values.data_.erase(remove_if(csvFile->values.data_.begin(), csvFile->values.data_.end(),
                                          [&](vector<string> a) { return columns.count(to_string(count++)) == 0; } ),
                                csvFile->values.data_.end());
    
    
    csvFile->set_num_rows(numRows);
    csvFile->set_num_columns(numOutputCols);
  }
  
  void print_csv_values(const DataType& csvFile)
  {
    
    int numColumns = csvFile.get_num_columns();
    int numRows = csvFile.get_num_rows();
    
    for (int i = 0; i < numRows; ++i)
    {
      for (int j = 0; j < numColumns; ++j)
      {
        cout << csvFile.values(i, j);
        if (j < numColumns - 1)
        {
          cout << ", ";
        }
      }
      cout << endl;
      
    }
    
  }
  
  vector<double>::const_iterator my_find(vector<double>::const_iterator first, vector<double>::const_iterator last,
                                         int &index, const double& val)
  {
    while (first!=last)
    {
      if (*first==val)
      {
        return first;
      }
      ++index;
      ++first;
    }
    return last;
  }
  
  // can perform inner and outer joins
  DataType::Ptr join_data_sets(const DataType &csvFile, const DataType &csvFile2, vector<string> colsToUse,
                               string operation)
  {
    int numRows = csvFile.get_num_rows();
    int numColumns = csvFile.get_num_columns();
    int numRows2 = csvFile2.get_num_rows();
    int numColumns2 = csvFile2.get_num_columns();
    int numColstoUse = colsToUse.size();
    int colIndex = stoi(colsToUse[0]);
    int colIndex2;
    
    if (numColstoUse > 1)
    {
      colIndex2 = stoi(colsToUse[1]);
    }
    else if (numColstoUse == 1)
    {
      colIndex2 = colIndex;
    }
    
    if (colIndex < 0 || colIndex > numColumns - 1
        || colIndex2 < 0 || colIndex2 > numColumns2 - 1)
    {
      throw std::invalid_argument("one of the column indices is out of range");
    }
    
    cout << "indices of columns are " << colIndex << " and " << colIndex2 << " for first "
    << "and second input files, respectively"<< endl;
    
    vector<double> currentCol = csvFile.get_column(colIndex);
    vector<double> currentCol2 = csvFile2.get_column(colIndex2);
    DataType::Ptr outputCsvFile(new DataType());
    int numOutputRows = 0;
    
    outputCsvFile->values.data_.resize(numColumns + numColumns2);
    
    unordered_set<int> rowSet;
    vector<double>::const_iterator indexIterator;
    int rowIndex;
    
    
    if (operation == "inner_join")
    {
      cout << "performing an inner join on the specified columns of the input data sets" << endl;
      
      for (int i = 0; i < numRows; ++i)
      {
        rowIndex = 0;
        // for each row in the specified column of the first csv file, check if there are
        // any rows in the specified column of the second csv file that have matching values
        indexIterator = my_find(currentCol2.cbegin(), currentCol2.cend(), rowIndex, currentCol[i]);
        while (indexIterator != currentCol2.end())
        {
          ++numOutputRows;
          // add the current row of the first csv file to the output csv file
          for (int j = 0; j < numColumns; ++j)
          {
            outputCsvFile->values.data_[j].push_back(csvFile.values(i, j));
          }
          // add the corresponding row of the second csv file to the output csv file
          for (int j = 0; j < numColumns2; ++j)
          {
            outputCsvFile->values.data_[numColumns + j].push_back(csvFile2.values(rowIndex, j));
          }
          // check if there are any other matching values in the specified column of the second csv file
          indexIterator = my_find(indexIterator + 1, currentCol2.cend(), rowIndex, currentCol[i]);
        }
      }
    }
    else if (operation == "outer_join")
    {
      cout << "performing an outer join on the specified columns of the input data sets" << endl;
      
      // for each value in the specified column of the first csv file, check if there are
      // any rows in the specified column of the second csv file that have matching values
      for (int i = 0; i < numRows; ++i)
      {
        rowIndex = 0;
        indexIterator = my_find(currentCol2.cbegin(), currentCol2.cend(), rowIndex, currentCol[i]);
        if (indexIterator == currentCol2.end())
        {
          // if no matching values are found, we add the current row of the first csv file,
          // as well as a row of n "null" values to the output csv file, where n is the
          // number of columns in the second csv file
          ++numOutputRows;
          for (int j = 0; j < numColumns; ++j)
          {
            outputCsvFile->values.data_[j].push_back(csvFile.values(i, j));
          }
          for (int j = 0; j < numColumns2; ++j)
          {
            outputCsvFile->values.data_[numColumns + j].emplace_back("null");
          }
        }
        else
        {
          // if a matching value is found, we add the current row of the first csv file,
          // as well as the corresponding row of the second csv file, to the output csv file
          while (indexIterator != currentCol2.end())
          {
            ++numOutputRows;
            // add the current row of the first csv file to the output csv file
            for (int j = 0; j < numColumns; ++j)
            {
              outputCsvFile->values.data_[j].push_back(csvFile.values(i, j));
            }
            // add the corresponding row of the second csv file to the output csv file
            rowSet.insert(rowIndex);
            for (int j = 0; j < numColumns2; ++j)
            {
              outputCsvFile->values.data_[numColumns + j].push_back(csvFile2.values(rowIndex, j));
            }
            // check if there are any other matching values in the specified column of the second csv file
            indexIterator = my_find(indexIterator + 1, currentCol2.cend(), rowIndex, currentCol[i]);
          }
        }
        
      }
      for (int i = 0; i < numRows2; ++i)
      {
        // if we have already dealt with the current row of the second csv file, then we skip to the next row
        if (rowSet.count(i) > 0)
        {
          continue;
        }
        else
        {
          // for each value in the specified column of the second csv file that was not used when looping through
          // the specified column of the first csv file, we add another row to the output csv file
          ++numOutputRows;
          for (int j = 0; j < numColumns; ++j)
          {
            outputCsvFile->values.data_[j].emplace_back("null");
          }
          for (int j = 0; j < numColumns2; ++j)
          {
            outputCsvFile->values.data_[numColumns + j].push_back(csvFile2.values(i, j));
          }
        }
      }
    }
    
    cout << "operation completed\n\n";
    
    outputCsvFile->set_num_rows(numOutputRows);
    outputCsvFile->set_num_columns(numColumns + numColumns2);
    
    return outputCsvFile;
  }
  
}
