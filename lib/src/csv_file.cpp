//
//  csv_file.cpp
//

#include "csv_file.h"
#include "string_operations.h"
#include "stats.h"

#define ARRAY_SIZE(array) (sizeof((array))/sizeof((array[0])))

typedef csv_file DataType;

DataType * csv_file
::read_data(char* path)
{
  ifstream file (path);
  string value;
  DataType * csvFile = new DataType();
  unsigned numRows = 0;
  unsigned numColumns = 0;
  
  while (file.good())
  {
    ++numRows;
    csvFile->values.data_.push_back(vector<string>());
    getline(file, value, '\n');
    
    if (numRows == 1)
    {
      numColumns = (unsigned)count(value.begin(), value.end(), ',') + 1;
      csvFile->values.data_.resize(numColumns);
    }
    
    if (value.find(',') != string::npos)
    {
      string_operations::split_line(value, ",", csvFile->values.data_);
    }
    else
    {
      csvFile->values.data_[0].push_back(value);
    }
  }
  
  csvFile->set_num_rows(numRows);
  csvFile->set_num_columns(numColumns);
  return csvFile;
}

void csv_file
::write_data(const DataType &csvFile, char* path)
{
  ofstream output_file (path);
  unsigned numRows = csvFile.get_num_rows();
  unsigned numColumns = csvFile.get_num_columns();
  
  for (unsigned i = 0; i < numRows; ++i)
  {
    for (unsigned j = 0; j < numColumns; ++j)
    {
      output_file << csvFile.values(i, j);
      if (j < numColumns - 1)
      {
        output_file << ",";
      }
    }
    if (i < numRows - 1)
    {
      output_file << "\n";
    }
  }
  output_file.close();
}

void csv_file
::write_data_subset(const DataType &csvFile, ofstream &outputFile,
                    unsigned firstRow, unsigned lastRow, bool isFinalSubset)
{
  unsigned numRows = csvFile.get_num_rows();
  unsigned numColumns = csvFile.get_num_columns();
  for (unsigned i = firstRow; i < lastRow; ++i)
  {
    for (unsigned j = 0; j < numColumns; ++j)
    {
      outputFile << csvFile.values(i, j);
      if (j < numColumns - 1)
      {
        outputFile << ",";
      }
    }
    if (i < numRows - 1 || !isFinalSubset)
    {
      outputFile << "\n";
    }
  }
}

