//
//  std::string_operations.cpp
//

#include "StringOperations.h"

namespace string_operations
{
  
  // splits an std::string into pieces based on specified delimiter
  void split_line(std::string& line, std::string&& delim, std::vector<std::vector<std::string>>& values)
  {
    size_t pos = 0;
    unsigned columnIndex = 0;
    while ((pos = line.find(delim, 0)) != std::string::npos)
    {
      values[columnIndex].emplace_back(line.substr(0, pos));
      line = line.substr(pos + 1);
      ++columnIndex;
    }
    if (!line.empty())
    {
      line.erase(remove(line.begin(), line.end(), '\r'), line.end());
      values[columnIndex].push_back(std::move(line));
    }
  }
  
  void split_line(std::string& line, std::string&& delim, std::vector<std::string>& values)
  {
    size_t pos = 0;
    std::string p;
    while ((pos = line.find(delim, 0)) != std::string::npos)
    {
      p = line.substr(0, pos);
      values.push_back(std::move(p));
      line = line.substr(pos + 1);
    }
    if (!line.empty())
    {
      line.erase(remove(line.begin(), line.end(), '\r'), line.end());
      values.push_back(std::move(line));
    }
  }
  
}