//
//  string_operations.h
//

#ifndef ____string_operations__
#define ____string_operations__

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

namespace string_operations
{
  
  void split_line(string& line, string delim, vector<vector<string>>& values);
  
  void split_line(string& line, string delim, vector<string>& values);
  
};

#endif /* defined(____string_operations__) */

