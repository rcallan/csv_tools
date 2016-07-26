//
//  csv_file.h
//

#ifndef ____csv_file__
#define ____csv_file__

#include <iostream>
#include <string>
#include <fstream>
#include <memory>
#include "matrix.h"
#include <vector>

using namespace std;

class csv_file
{
public:
  
  csv_file()
  : values(), numRows(0), numColumns(0) {}
  csv_file(unsigned numRows_, unsigned numColumns_)
  : numRows(numRows_), numColumns(numColumns_) {}
  csv_file(unsigned numRows_, unsigned numColumns_, matrix<string> values_)
  : values(values_), numRows(numRows_), numColumns(numColumns_) {}
  
  // ~csv_file() 
  // { 
  //   cout << "deleted csv file object" << endl;
  // }
  
  void set_num_rows(unsigned numRows_) { numRows = numRows_; }
  void set_num_columns(unsigned numColumns_) { numColumns = numColumns_; }
  unsigned get_num_rows() const { return numRows; }
  unsigned get_num_columns() const { return numColumns; }
  
  typedef shared_ptr<csv_file> Ptr;
  
  void resize(unsigned numRows_, unsigned numColumns_)
  {
    numRows = numRows_;
    numColumns = numColumns_;
    values.resize_matrix(numRows, numColumns);
  }

  void printSize(string fileName)
  {
    cout << "size of " + fileName + " is " << numRows << " rows by " 
    << numColumns << " columns" << endl;
  }

  vector<double> get_column(unsigned colIndex) const
  {
    vector<double> column(numRows);
    for (unsigned i = 0; i < numRows; ++i)
    {
      column[i] = stod(values(i, colIndex));
    }
    return column;
  }
  
  vector<double> get_row(unsigned rowIndex) const
  {
    vector<double> row(numColumns);
    for (unsigned i = 0; i < numColumns; ++i)
    {
      row[i] = stod(values(rowIndex, i));
    }
    return row;
  }
  
  matrix<string> values;
  
  static csv_file * read_data(char* filePath);
  
  static void write_data(const csv_file &csvFile, char* path);
  
  static void write_data_subset(const csv_file &csvFile, ofstream &outputFile,
                                unsigned firstRow, unsigned lastRow, bool finalSubset);
  
private:
  unsigned numRows;
  unsigned numColumns;
  
};

#endif /* defined(____csv_file__) */
