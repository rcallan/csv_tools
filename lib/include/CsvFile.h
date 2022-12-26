//
//  CsvFile.h
//

#ifndef ____CsvFile__
#define ____CsvFile__

#include <iostream>
#include <string>
#include <fstream>
#include <memory>
#include "matrix.h"
#include <vector>



class CsvFile
{
public:
  CsvFile() = default;
  explicit CsvFile(unsigned numRows_, unsigned numColumns_) : numRows(numRows_), numColumns(numColumns_) { }
  explicit CsvFile(unsigned numRows_, unsigned numColumns_, matrix<std::string>& values_)
    : values(values_), numRows(numRows_), numColumns(numColumns_) { }
  
  // ~CsvFile() 
  // { 
  //   std::cout << "deleted csv file object" << std::endl;
  // }
  
  void set_num_rows(unsigned numRows_) { numRows = numRows_; }
  void set_num_columns(unsigned numColumns_) { numColumns = numColumns_; }
  unsigned get_num_rows() const { return numRows; }
  unsigned get_num_columns() const { return numColumns; }
  
  typedef std::shared_ptr<CsvFile> Ptr;
  typedef std::shared_ptr<const CsvFile> PtrC;
  
  void resize(unsigned numRows_, unsigned numColumns_)
  {
    numRows = numRows_;
    numColumns = numColumns_;
    values.resize_matrix(numRows, numColumns);
  }

  void printSize(std::string fileName) const
  {
    std::cout << "size of " + fileName + " is " << numRows << " rows by " 
    << numColumns << " columns" << std::endl;
  }

  std::vector<double> get_column(unsigned colIndex) const
  {
    if (numRows == 0 || numColumns == 0)
    {
      throw std::out_of_range("number of columns or rows should probably not be zero");
    }
    std::vector<double> column(numRows);
    for (unsigned i = 0; i < numRows; ++i)
    {
      column[i] = stod(values(i, colIndex));
    }
    return column;
  }
  
  std::vector<double> get_row(unsigned rowIndex) const
  {
    std::vector<double> row(numColumns);
    for (unsigned i = 0; i < numColumns; ++i)
    {
      row[i] = stod(values(rowIndex, i));
    }
    return row;
  }
  
  matrix<std::string> values {};
  
  static CsvFile* read_data(char* filePath);
  
  static void write_data(CsvFile::PtrC csvFile, char* path);
  
  static void write_data_subset(
    CsvFile::PtrC csvFile, 
    std::ofstream& outputFile,
    unsigned firstRow, 
    unsigned lastRow, 
    bool finalSubset);
  
private:
  unsigned numRows {};
  unsigned numColumns {};
  
};

#endif /* defined(____CsvFile__) */
