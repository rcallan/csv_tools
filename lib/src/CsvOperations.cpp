//
//  csv_operations.cpp
//

#include "CsvOperations.h"
#include "StringOperations.h"
#include "stats.h"
#include <sstream>
#include <utility>

#define ARRAY_SIZE(array) (sizeof((array))/sizeof((array[0])))

namespace csv_operations
{
  // returns the indices that can be used to split the data up into equally sized pieces
  std::vector<unsigned> get_bounds(unsigned size, unsigned numRows, unsigned numColumns, unsigned numSubsets)
  {
    std::vector<unsigned> bounds(numSubsets);
    unsigned numSubsetRows = numRows / numSubsets;
    unsigned subsetSize = numSubsetRows * numColumns;
    unsigned numRowsInLastSubset = numSubsetRows + numRows % numSubsetRows;
    
    //std::cout << "number of rows in last subset is " << numRowsInLastSubset << std::endl;
    
    for (unsigned i = 0; i < numSubsets - 1; ++i)
    {
      bounds[i] = subsetSize * (i + 1);
    }
    
    subsetSize = numRowsInLastSubset * numColumns;
    bounds[numSubsets - 1] = size;
    
    return bounds;
  }
  
  // checks for infinite values in the csv file
  void verify_data_format(const CsvFile& csvFile)
  {
    for (unsigned i = 0; i < csvFile.get_num_rows(); ++i)
    {
      for (unsigned j = 0; j < csvFile.get_num_columns(); ++j)
      {
        if (csvFile.values(i, j) == "inf")
        {
          //todo: maybe add a new exception class for this
          throw std::invalid_argument("input data should not contain infinite values");
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
  
  template <typename T>
  std::string to_string_with_precision(const T a_value, const int n = 5)
  {
      std::stringstream out;
      out.precision(n);
      out << std::fixed << a_value;
      return out.str();
  }

  CsvFile::Ptr do_arith_operation_subset(
    CsvFile::Ptr updatedcsvFile, 
    std::function<double(double, double)> myoper,
    unsigned firstRow, 
    unsigned lastRow, 
    unsigned firstCol, 
    unsigned secondCol)
  {
    unsigned newNumColumns = updatedcsvFile->get_num_columns() + 1;
    unsigned numRows = updatedcsvFile->get_num_rows();
    updatedcsvFile->set_num_columns(newNumColumns);
    
    updatedcsvFile->values.data_.resize(newNumColumns);
    updatedcsvFile->values.data_[newNumColumns - 1].resize(numRows);
    
    const CsvFile& csvFile = *updatedcsvFile;
    
    for (unsigned i = firstRow; i < lastRow; ++i)
    {
      // we truncate to two decimal places for now - could probably add an option for specifying the output type or precision if it's a floating point value

      updatedcsvFile->values(i, newNumColumns - 1) = to_string_with_precision(myoper(stod(csvFile.values(i, firstCol)),
                                                                                      stod(csvFile.values(i, secondCol))), 2);
      
    }

    // parallel::Range range(firstRow, lastRow);
    // PerformColumnOpSubsetBody p(updatedcsvFile, myoper, firstRow, lastRow, firstCol, secondCol);
    // parallel::parallel_for_(range, p);

    return updatedcsvFile;
  }
  
  CsvFile::Ptr perform_column_op_subset(
    CsvFile::Ptr csvFile, 
    std::function<double(double, double)> myoper,
    unsigned firstRow, 
    unsigned lastRow, 
    std::vector<std::string>& colsToUse)
  {
    unsigned firstCol = stoi(colsToUse[0]);
    unsigned secondCol = stoi(colsToUse[1]);
    
    unsigned numColumns = csvFile->get_num_columns();
    
    if (firstCol < 0 || firstCol > numColumns - 1
        || secondCol < 0 || secondCol > numColumns - 1)
    {
      throw std::out_of_range("one of the column indices is out of range");
    }
    
    return do_arith_operation_subset(csvFile, myoper, firstRow, lastRow, firstCol, secondCol);
  }
  
  CsvFile::Ptr perform_column_op(CsvFile::Ptr csvFile, std::function<double(double, double)> myoper, std::vector<std::string>& colsToUse)
  {
    unsigned firstCol = stoi(colsToUse[0]);
    unsigned secondCol = stoi(colsToUse[1]);
    
    unsigned numRows = csvFile->get_num_rows();
    unsigned numColumns = csvFile->get_num_columns();
    
    if (firstCol < 0 || firstCol > numColumns - 1
        || secondCol < 0 || secondCol > numColumns - 1)
    {
      throw std::out_of_range("one of the column indices is out of range");
    }
    
    return do_arith_operation_subset(move(csvFile), myoper, 0, numRows, firstCol, secondCol);
  }
  
  // output the column index, minimum, maximum, median, and average values
  void show_single_column_stats(std::vector<double>& column, unsigned col_idx, std::string& otherStat)
  {

    std::cout << "column " << col_idx << " - ";
    if (otherStat == "none")
    {
      std::cout << stats::get_min_element(column) << ", " << stats::get_max_element(column) << ", " << stats::get_median_value(column)
      << ", and " << stats::get_mean_value(column) << std::endl;
    }
    else if (otherStat == "standard_deviation")
    {
      std::cout << stats::get_standard_deviation(column) << std::endl;
    }
    
  }
  
  void show_multiple_column_stats(const CsvFile& csvFile, std::vector<std::string>& colsToUse, std::string& otherStat)
  {
    unsigned numColumns = csvFile.get_num_columns();
    unsigned numColstoUse = colsToUse.size();
    unsigned columnIndex;

    // could probably add enum classes for things like this
    
    // output stats for columns
    if (otherStat == "none")
    {
      std::cout << "stats (min, max, median, and average) for specified columns are" << std::endl;
    }
    else if (otherStat == "standard_deviation")
    {
      std::cout << "standard deviations for specified columns are" << std::endl;
    }
    else if (otherStat == "correlation_coefficient")
    {
      if (numColstoUse != 2)
      {
        throw std::invalid_argument("two columns should be specified to get correlation coefficient");
      }
      
      unsigned firstColIdx = stoi(colsToUse[0]);
      unsigned secondColIdx = stoi(colsToUse[1]);
      
      std::vector<double> firstCol = csvFile.get_column(firstColIdx);
      std::vector<double> secondCol = csvFile.get_column(secondColIdx);
      
      double correlationCoefficient = stats::get_correlation_coefficient(firstCol, secondCol);
      
      std::cout << "the correlation between columns " << firstColIdx
      << " and " << secondColIdx << " is " << correlationCoefficient << std::endl;
      return;
    }
    
    std::vector<double> currentColumn;
    for (unsigned j = 0; j < numColstoUse; ++j)
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

  void edit_columns(CsvFile::Ptr csvFile, std::vector<std::string>& colsToUse)
  {
    unsigned numOutputCols = colsToUse.size();

    std::vector<std::vector<std::string>> result(numOutputCols);
    std::transform(std::cbegin(colsToUse), std::cend(colsToUse), std::begin(result), 
                      [&data = std::as_const(csvFile->values.data_)](std::string pos) { return data[std::stoi(pos)]; });
    csvFile->values.data_ = std::move(result);
    
    csvFile->set_num_columns(numOutputCols);
  }
  
  void print_csv_values(CsvFile::Ptr csvFile)
  {
    
    unsigned numColumns = csvFile->get_num_columns();
    unsigned numRows = csvFile->get_num_rows();
    
    for (unsigned i = 0; i < numRows; ++i)
    {
      for (unsigned j = 0; j < numColumns; ++j)
      {
        std::cout << csvFile->values(i, j);
        if (j < numColumns - 1)
        {
          std::cout << ", ";
        }
      }
      std::cout << std::endl;
      
    }
    
  }
  
  std::vector<double>::const_iterator my_find(
    std::vector<double>::const_iterator first, 
    std::vector<double>::const_iterator last,
    unsigned index, 
    const double val)
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
  CsvFile::Ptr join_data_sets(
    const CsvFile& csvFile, 
    const CsvFile& csvFile2, 
    std::vector<std::string>& colsToUse,
    std::string& operation)
  {
    unsigned numColstoUse = colsToUse.size();
    unsigned colIndex = stoi(colsToUse[0]);
    unsigned colIndex2;
    
    if (numColstoUse > 1)
    {
      colIndex2 = stoi(colsToUse[1]);
    }
    else if (numColstoUse == 1)
    {
      colIndex2 = colIndex;
    }

    unsigned numRows = csvFile.get_num_rows();
    unsigned numColumns = csvFile.get_num_columns();
    unsigned numRows2 = csvFile2.get_num_rows();
    unsigned numColumns2 = csvFile2.get_num_columns();

    if (colIndex < 0 || colIndex > numColumns - 1
        || colIndex2 < 0 || colIndex2 > numColumns2 - 1)
    {
      throw std::invalid_argument("one of the column indices is out of range");
    }
    
    std::cout << "indices of columns are " << colIndex << " and " << colIndex2 << " for first "
    << "and second input files, respectively"<< std::endl;
    
    std::vector<double> currentCol = csvFile.get_column(colIndex);
    std::vector<double> currentCol2 = csvFile2.get_column(colIndex2);
    CsvFile::Ptr outputCsvFile(new CsvFile());
    unsigned numOutputRows = 0;
    
    outputCsvFile->values.data_.resize(numColumns + numColumns2);
    
    std::unordered_set<unsigned> rowSet;
    std::vector<double>::const_iterator indexIterator;
    unsigned rowIndex;
    
    
    if (operation == "inner_join")
    {
      std::cout << "performing an inner join on the specified columns of the input data sets" << std::endl;
      
      for (unsigned i = 0; i < numRows; ++i)
      {
        rowIndex = 0;
        // for each row in the specified column of the first csv file, check if there are
        // any rows in the specified column of the second csv file that have matching values
        indexIterator = my_find(currentCol2.cbegin(), currentCol2.cend(), rowIndex, currentCol[i]);
        while (indexIterator != currentCol2.end())
        {
          ++numOutputRows;
          // add the current row of the first csv file to the output csv file
          for (unsigned j = 0; j < numColumns; ++j)
          {
            outputCsvFile->values.data_[j].push_back(csvFile.values(i, j));
          }
          // add the corresponding row of the second csv file to the output csv file
          for (unsigned j = 0; j < numColumns2; ++j)
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
      std::cout << "performing an outer join on the specified columns of the input data sets" << std::endl;
      
      // for each value in the specified column of the first csv file, check if there are
      // any rows in the specified column of the second csv file that have matching values
      for (unsigned i = 0; i < numRows; ++i)
      {
        rowIndex = 0;
        indexIterator = my_find(currentCol2.cbegin(), currentCol2.cend(), rowIndex, currentCol[i]);
        if (indexIterator == currentCol2.end())
        {
          // if no matching values are found, we add the current row of the first csv file,
          // as well as a row of n "null" values to the output csv file, where n is the
          // number of columns in the second csv file
          ++numOutputRows;
          for (unsigned j = 0; j < numColumns; ++j)
          {
            outputCsvFile->values.data_[j].push_back(csvFile.values(i, j));
          }
          for (unsigned j = 0; j < numColumns2; ++j)
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
            for (unsigned j = 0; j < numColumns; ++j)
            {
              outputCsvFile->values.data_[j].push_back(csvFile.values(i, j));
            }
            // add the corresponding row of the second csv file to the output csv file
            rowSet.insert(rowIndex);
            for (unsigned j = 0; j < numColumns2; ++j)
            {
              outputCsvFile->values.data_[numColumns + j].push_back(csvFile2.values(rowIndex, j));
            }
            // check if there are any other matching values in the specified column of the second csv file
            indexIterator = my_find(indexIterator + 1, currentCol2.cend(), rowIndex, currentCol[i]);
          }
        }
        
      }
      for (unsigned i = 0; i < numRows2; ++i)
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
          for (unsigned j = 0; j < numColumns; ++j)
          {
            outputCsvFile->values.data_[j].emplace_back("null");
          }
          for (unsigned j = 0; j < numColumns2; ++j)
          {
            outputCsvFile->values.data_[numColumns + j].push_back(csvFile2.values(i, j));
          }
        }
      }
    }
    
    std::cout << "operation completed\n\n";
    
    outputCsvFile->set_num_rows(numOutputRows);
    outputCsvFile->set_num_columns(numColumns + numColumns2);
    
    return outputCsvFile;
  }
  
}
