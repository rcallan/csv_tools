//
//  string_operations.cpp
//

#include "StringOperations.h"

namespace string_operations
{
  
  // splits a string into pieces based on specified delimiter
  void split_line(string& line, string delim, vector<vector<string>>& values)
  {
    size_t pos = 0;
    unsigned columnIndex = 0;
    while ((pos = line.find(delim, 0)) != string::npos)
    {
      values[columnIndex].emplace_back(line.substr(0, pos));
      line = line.substr(pos + 1);
      ++columnIndex;
    }
    if (!line.empty())
    {
      line.erase(remove(line.begin(), line.end(), '\r'), line.end());
      values[columnIndex].push_back(line);
    }
  }
  
  void split_line(string& line, string delim, vector<string>& values)
  {
    size_t pos = 0;
    string p;
    while ((pos = line.find(delim, 0)) != string::npos)
    {
      p = line.substr(0, pos);
      values.push_back(p);
      line = line.substr(pos + 1);
    }
    if (!line.empty())
    {
      line.erase(remove(line.begin(), line.end(), '\r'), line.end());
      values.push_back(line);
    }
  }
  
}