//
//  ml.cpp
//

#include "ml.h"

namespace ml
{
  void get_initial_centers(size_t n, int k, size_t* initialIndex)
  {
    for (int i = 0; i < k; ++i)
    {
      size_t temp = rand() % n;
      int j;
      for (j = 0; j < i; ++j)
      {
        if (temp == initialIndex[j])
        {
          --i; j = -1;
          break;
        }
      }
      if (j != -1) 
        initialIndex[i] = temp;
    }
  }

  inline void copy_des_to_double(double* dst, double* src, int length)
  {
    for (int i = 0; i < length; ++i)
      dst[i] = src[i];
  }

  inline double dis_des_to_double(double* dst, double* src, int length)
  {
    double dis = 0.0;
    for (int i = 0; i < length; ++i)
    {
      double d = dst[i] - src[i];
      dis += d * d;
    }
    dis = sqrt(dis);
    return dis;
  }

  void multi_compute_assignment(size_t num, int dim, int k, double** des, double* means, int* assignment, double* error_out, size_t* numChange)
  {
    double error = 0.0;
    for (size_t i = 0; i < num; ++i)
    {
      double minDis = numeric_limits<double>::max();
      int minIndex = -1;
      for (int j = 0; j < k; ++j)
      {
        double tempDis = dis_des_to_double(means + j * dim, des[i], dim);

        if (minDis > tempDis)
        {
          minDis = tempDis;
          minIndex = j;
        }
      }
      error += minDis;
      if (assignment[i] != minIndex)
      {
        assignment[i] = minIndex;
        (*numChange)++;
      }
    }
    *error_out = error;
  }

  size_t compute_assignment(size_t num, int dim, int k, double** p, double* means, int* assignment, double& errorOut, int numThreads)
  {
    size_t numChange = 0;
    double error = 0.0;
    if (numThreads == 1 || num < numThreads * 100)
    {
      for (size_t i = 0; i < num; ++i)
      {
        double minDis = numeric_limits<double>::max();
        int minIndex = -1;
        for (int j = 0; j < k; ++j)
        {
          double tempDis = dis_des_to_double(means + j * dim, p[i], dim);

          if (minDis > tempDis)
          {
            minDis = tempDis;
            minIndex = j;
          }
        }
        errorOut += minDis;
        if (assignment[i] != minIndex)
        {
          assignment[i] = minIndex;
          numChange++;
        }
      }
    }
    else
    {
      std::vector<thread> threads;
      size_t numPoints = num / numThreads;
      size_t count = 0;
      size_t* changes = new size_t[numThreads];
      double* errorVector = new double[numThreads];
      for (int i = 0; i < numThreads; ++i)
      {
        changes[i] = 0;
        errorVector[i] = 0.0;
      }

      for (int i = 0; i < numThreads; ++i)
      {
        size_t totalNum = 0;
        if (i == numThreads - 1)
          totalNum = num - (numThreads - 1) * numPoints;
        else
          totalNum = numPoints;
        threads.push_back(thread(multi_compute_assignment, totalNum, dim, k, p + count, means, assignment + count, &errorVector[i], &changes[i]));
        count += numPoints;
      }
      for_each(threads.begin(), threads.end(), mem_fn(&thread::join));
      for (int i = 0; i < numThreads; ++i)
      {
        numChange += changes[i];
        error += errorVector[i];
      }
    }
    errorOut = error;

    return numChange;
  }

  void multi_des_accumulate(size_t num, int dim, int k, double** p, int* currentAssignments, double* totals, size_t* counts)
  {

    for (size_t i = 0; i < num; ++i)
    {
      int label = currentAssignments[i];
      counts[label]++;
      for (int j = 0; j < dim; ++j)
      {
        totals[label * dim + j] += p[i][j];
      }
    }
  }

  void compute_means(size_t num, int dim, int k, double** p, int* currentAssignments, double* currentMeans, int numThreads)
  {
    size_t* counts = new size_t[k];
  // initialize counts and mean values
    for (int i = 0; i < k; ++i)
    {
      counts[i] = 0;
      for (int j = 0; j < dim; ++j)
        currentMeans[i * dim + j] = 0;
    }

    if (numThreads == 1)
    {
      for (size_t i = 0; i < num; ++i)
      {
        int label = currentAssignments[i];
        counts[label]++;
        for (int j = 0; j < dim; ++j)
          currentMeans[label * dim + j] += (double)p[i][j];
      }
    }
    else
    {
      vector<double*> sub_totals(numThreads);
      vector<size_t*> sub_counts(numThreads);
      for (int i = 0; i < numThreads; ++i)
      {
        sub_totals[i] = new double[dim * k];
        sub_counts[i] = new size_t[k];
        for (int j = 0; j < dim * k; ++j)
          sub_totals[i][j] = 0.0;
        for (int j = 0; j < k; ++j)
          sub_counts[i][j] = 0;
      }
      std::vector<thread> threads;
      size_t off = 0;
      for (int i = 0; i < numThreads; ++i)
      {
        size_t featureNum = num / numThreads;
        if (i == numThreads - 1)
          featureNum = num - (numThreads - 1) * featureNum;
        threads.push_back(thread(multi_des_accumulate, featureNum, dim, k, p + off, currentAssignments + off, sub_totals[i], sub_counts[i]));
        off += featureNum;
      }
      for_each(threads.begin(), threads.end(), mem_fn(&thread::join));
      for (int i = 0; i < numThreads; ++i)
      {
        for (int j = 0; j < k * dim; ++j)
          currentMeans[j] += sub_totals[i][j];
        for (int j = 0; j < k; ++j)
          counts[j] += sub_counts[i][j];
      }
      for (int i = 0; i < numThreads; ++i)
      {
        delete[] sub_counts[i];
        delete[] sub_totals[i];
      }
    }

    for (int i = 0; i < k; ++i)
    {
      if (counts[i] == 0) continue;
      for (int j = 0; j < dim; ++j)
      {
        currentMeans[i * dim + j] /= counts[i];
      }
    }

    delete[] counts;

  }

  double kmeans(size_t num, int dim, int k, double** p, double* means, int* assignment, int numThreads)
  {
    if (num < k)
    {
      cerr << "number of keys should be greater or equal to the number of clusters";
      exit(1);
    }

    double minDistance = numeric_limits<double>::max();
    double* currentMeans;
    size_t* initialIndex;
    int* currentAssignments;
    double pctChangeThreshold = 0.05;
    int totalIterations = 1;

    currentMeans = new double[k * dim];
    initialIndex = new size_t[k];
    currentAssignments = new int[num];

    if (currentMeans == NULL || initialIndex == NULL || currentAssignments == NULL)
    {
      cerr << "an error occurred when trying to allocate memory for kmeans variable";
      exit(1);
    }

    while(totalIterations-- > 0)
    {
      double dis = 0;
      get_initial_centers(num, k, initialIndex);
      for (int i = 0; i < k; ++i)
      {
        copy_des_to_double(currentMeans + i * dim, p[initialIndex[i]], dim);
      }

      for (size_t i = 0; i < num; ++i)
      {
        currentAssignments[i] = -1;
      }

      size_t numChange = compute_assignment(num, dim, k, p, currentMeans, currentAssignments, dis, numThreads);

      double percentChange = (double) numChange / num;
      assert(num == numChange);

      int iterations = 0;

      while (percentChange > pctChangeThreshold)
      {
      // recompute the means
        compute_means(num, dim, k, p, currentAssignments, currentMeans, numThreads);

      // recompute the assignments
        numChange = compute_assignment(num, dim, k, p, currentMeans, currentAssignments, dis, numThreads);
        percentChange = (double) numChange / num;
        ++iterations;
      }

      cout << "used " << iterations << " iterations for get the clusters" << endl;

      compute_means(num, dim, k, p, currentAssignments, currentMeans, numThreads);
      if (dis < minDistance)
      {
        minDistance = dis;
        memcpy(means, currentMeans, sizeof(double) * k * dim);
        memcpy(assignment, currentAssignments, sizeof(double) * k * dim);
      }
    }

    delete[] currentMeans;
    delete[] initialIndex;
    delete[] currentAssignments;

    return 1.0;

  }
}


