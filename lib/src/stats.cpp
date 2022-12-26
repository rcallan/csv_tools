//
//  stats.cpp
//

#include "stats.h"
#include <math.h>
#include <stdexcept>

namespace stats
{
  // returns the minimum value of a double array
  double get_min_element(std::vector<double>& values)
  {
    double min = std::numeric_limits<double>::max();
    unsigned valuesSize = values.size();
    
    for (unsigned i = 0; i < valuesSize; ++i) 
    {
      if (values[i] < min)
      {
        min = values[i];
      }
    }
    return min;
  }
  
  // returns the maximum value of a double array
  double get_max_element(std::vector<double>& values)
  {
    double max = std::numeric_limits<double>::min();
    unsigned valuesSize = values.size();
    
    for (unsigned i = 0; i < valuesSize; ++i) 
    {
      if (values[i] > max)
      {
        max = values[i];
      }
    }
    return max;
  }
  
  // returns the median value of a double std::vector
  double get_median_value(std::vector<double>& values)
  {
    unsigned valuesSize = values.size();
    sort(values.begin(), values.begin() + valuesSize);
    
    double median;
    if (valuesSize % 2 == 0)
    {
      median = (values[valuesSize / 2] + values[valuesSize / 2 - 1]) / 2;
    }
    else
    {
      median = values[valuesSize / 2];
    }
    return median;
  }
  
  double get_mean_value(std::vector<double>& values)
  {
    return accumulate(values.begin(), values.end(), 0.0) / values.size();
  }
  
  double get_standard_deviation(std::vector<double>& values)
  {
    double size = values.size();
    
    double mean = get_mean_value(values);
    double sumOfSquareDifferences = 0;
    for (unsigned i = 0; i < size; ++i)
    {
      sumOfSquareDifferences += (values[i] - mean) * (values[i] - mean);
    }
    double standard_devation = sqrt(1 / size * sumOfSquareDifferences);
    
    return standard_devation;
  }
  
  // returns the pearson correlation coefficient for two double std::vectors
  double get_correlation_coefficient(std::vector<double>& xvals, std::vector<double>& yvals)
  {
    unsigned xvalsSize = xvals.size();
    unsigned yvalsSize = yvals.size();
    if (xvalsSize != yvalsSize)
    {
      throw std::invalid_argument("the sets of values should be of equal length");
    }
    
    double xvalsMean = get_mean_value(xvals);
    double yvalsMean = get_mean_value(yvals);
    double xvalsStandardDeviation = get_standard_deviation(xvals);
    double yvalsStandardDeviation = get_standard_deviation(yvals);
    
    double numerator = 0;
    for (unsigned i = 0; i < xvalsSize; ++i)
    {
      numerator += (xvals[i] - xvalsMean) * (yvals[i] - yvalsMean);
    }
    
    return numerator / (xvalsSize * xvalsStandardDeviation * yvalsStandardDeviation);
    
  }
}



