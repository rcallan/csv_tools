//
//  CsvFile.cpp
//

#include "CsvFile.h"
#include "StringOperations.h"
#include "stats.h"

#define ARRAY_SIZE(array) (sizeof((array))/sizeof((array[0])))

CsvFile* CsvFile::read_data(char* path)
{
  std::ifstream file (path);
  std::string value;
  CsvFile* csvFile = new CsvFile();
  unsigned numRows = 0;
  unsigned numColumns = 0;
  
  while (file.good())
  {
    // unsigned numItemsinRow = 0;
    ++numRows;
    std::getline(file, value, '\n');
    
    if (numRows == 1)
    {
      numColumns = (unsigned)count(value.begin(), value.end(), ',') + 1;
      csvFile->values.data_.resize(numColumns);
    }
    
    if (value.find(',') != std::string::npos)
    {
      // ++numItemsinRow;
      string_operations::split_line(value, ",", csvFile->values.data_);
    }
    else if (numRows > 1)
    {
      --numRows;
    }
    else
    {
      csvFile->values.data_[0].push_back(std::move(value));
    }
  }
  
  csvFile->set_num_rows(numRows);
  csvFile->set_num_columns(numColumns);
  return csvFile;
}

void CsvFile::write_data(CsvFile::PtrC csvFile, char* path)
{
  std::ofstream output_file (path);
  unsigned numRows = csvFile->get_num_rows();
  unsigned numColumns = csvFile->get_num_columns();
  
  for (unsigned i = 0; i < numRows; ++i)
  {
    for (unsigned j = 0; j < numColumns; ++j)
    {
      output_file << csvFile->values(i, j);
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

void CsvFile::write_data_subset(
  CsvFile::PtrC csvFile, 
  std::ofstream& outputFile,
  unsigned firstRow, 
  unsigned lastRow, 
  bool isFinalSubset)
{
  unsigned numRows = csvFile->get_num_rows();
  unsigned numColumns = csvFile->get_num_columns();
  for (unsigned i = firstRow; i < lastRow; ++i)
  {
    for (unsigned j = 0; j < numColumns; ++j)
    {
      outputFile << csvFile->values(i, j);
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

