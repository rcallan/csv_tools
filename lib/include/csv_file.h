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
  csv_file(int numRows_, int numColumns_)
  : numRows(numRows_), numColumns(numColumns_) {}
  csv_file(int numRows_, int numColumns_, matrix<string> values_)
  : values(values_), numRows(numRows_), numColumns(numColumns_) {}
  
  /*
  ~csv_file()
  {
    cout << "deleting csv file object" << endl;
  }
  */
  
  void set_num_rows(int numRows_) { numRows = numRows_; }
  void set_num_columns(int numColumns_) { numColumns = numColumns_; }
  int get_num_rows() const { return numRows; }
  int get_num_columns() const { return numColumns; }
  
  typedef shared_ptr<csv_file> Ptr;
  
  void resize(int numRows_, int numColumns_)
  {
    numRows = numRows_;
    numColumns = numColumns_;
    values.resize_matrix(numRows, numColumns);
  }
  
  vector<double> get_column(int colIndex) const
  {
    vector<double> column(numRows);
    for (int i = 0; i < numRows; ++i)
    {
      column[i] = stod(values(i, colIndex));
    }
    return column;
  }
  
  vector<double> get_row(int rowIndex) const
  {
    vector<double> row(numColumns);
    for (int i = 0; i < numColumns; ++i)
    {
      row[i] = stod(values(rowIndex, i));
    }
    return row;
  }
  
  matrix<string> values;
  
  static csv_file * read_data(char* filePath);
  
  static void write_data(const csv_file &csvFile, char* path);
  
  static void write_data_subset(const csv_file &csvFile, ofstream &outputFile,
                                int firstRow, int lastRow, bool finalSubset);
  
private:
  int numRows;
  int numColumns;
  
};

#endif /* defined(____csv_file__) */
