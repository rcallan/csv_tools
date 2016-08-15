//
//  ml.h
//

#ifndef ____ml__
#define ____ml__

#include <iostream>
#include <limits>
#include <vector>
#include <cstring>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <thread>

using namespace std;

namespace ml
{
  void get_initial_centers(size_t n, int k, size_t* initialIndex);

  inline void copy_des_to_double(double* dst, double* src, int length);

  inline double dis_des_to_double(double* dst, double* src, int length);

  void multi_compute_assignment(size_t num, int dim, int k, double** des, double* means, int* assignment, double* error_out, size_t* numChange);

  size_t compute_assignment(size_t num, int dim, int k, double** p, double* means, int* assignment, double& errorOut, int numThreads);

  void multi_des_accumulate(size_t num, int dim, int k, double** p, int* currentAssignments, double* totals, size_t* counts);

  void compute_means(size_t num, int dim, int k, double** p, int* currentAssignments, double* currentMeans, int numThreads);

  double kmeans(size_t num, int dim, int k, double** p, double* means, int* assignment, int numThreads);

  
}

#endif /* defined(____ml__) */

