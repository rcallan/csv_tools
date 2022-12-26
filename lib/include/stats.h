//
//  stats.h
//

#ifndef ____stats__
#define ____stats__

#include <vector>
#include <numeric>
#include <algorithm>



namespace stats
{
  double get_min_element(std::vector<double>& values);
  
  double get_max_element(std::vector<double>& values);
  
  double get_median_value(std::vector<double>& values);
  
  double get_mean_value(std::vector<double>& values);
  
  double get_standard_deviation(std::vector<double>& values);
  
  double get_correlation_coefficient(std::vector<double>& xvals, std::vector<double>& yvals);
};

#endif /* defined(____stats__) */

