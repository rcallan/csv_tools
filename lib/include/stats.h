//
//  stats.h
//

#ifndef ____stats__
#define ____stats__

#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

namespace stats
{
  double get_min_element(vector<double>& values);
  
  double get_max_element(vector<double>& values);
  
  double get_median_value(vector<double>& values);
  
  double get_mean_value(vector<double>& values);
  
  double get_standard_deviation(vector<double>& values);
  
  double get_correlation_coefficient(vector<double>& xvals, vector<double>& yvals);
};

#endif /* defined(____stats__) */

