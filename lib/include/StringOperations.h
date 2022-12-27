//
//  std::string_operations.h
//

#ifndef ____string_operations__
#define ____string_operations__

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>



namespace string_operations
{

  void split_line(std::string& line, std::string&& delim, std::vector<std::vector<std::string>>& values);

  void split_line(std::string& line, std::string&& delim, std::vector<std::string>& values);
  
}

#endif /* defined(____string_operations__) */

