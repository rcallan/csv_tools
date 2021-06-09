//
//  csvml.cpp
//

#include "ml.h"
#include "parameters.h"
#include "csv_file.h"
#include <chrono>
#include <string>
#include <pthread.h>

using namespace std;

void showHelp()
{
  cout << "usage- showcsv [--path <path>] [--print_values off || on]\n\n" 
  "The showcsv tool prints the number of rows and columns and (optionally) all " 
  "the values of the csv file to the standard output.\n";
}

double** copy_2d_vector_to_2d_array(const std::vector<std::vector<string>>& src)
{
  int numKeys = src[0].size();
  int numDim = src.size();
  int total = numKeys * numDim;

  double** p = new double*[numKeys];
  p[0] = new double[total];

  for (int i = 1; i < numKeys; ++i)
  {
    p[i] = &p[0][i * numDim];
  }
  for (int i = 0; i < numKeys; ++i)
  {
    for (int j = 0; j < numDim; ++j)
    {
      p[i][j] = stod(src[j][i]);
    }
  }

  return p;
}

int main(int argc, char** argv)
{

  parameters::parameter_set parameterSet = parameters::parse_arguments(argc, argv);

  if (parameterSet.showHelp == true)
  {
    showHelp();
    return 0;
  }
  
  parameters::verify_parameters(parameterSet);
  
  csv_file::Ptr csvFile(csv_file::read_data(parameterSet.filePath));
  
  csvFile->printSize("input file");

  double** p = copy_2d_vector_to_2d_array(csvFile->values.data_);

  int numKeys = csvFile->get_num_rows();
  int numDim = csvFile->get_num_columns();
  int total = numKeys * numDim;

  int numClusters = 5;

  int* assignments = new int[total];
  double* means = new double[numClusters * numDim];

  int numThreads = parameterSet.numThreads;

  cout << "using " << numThreads << " thread(s) for computations" << endl;

  auto start = chrono::steady_clock::now();

  ml::kmeans(numKeys, numDim, numClusters, p, means, assignments, numThreads);

  auto end = chrono::steady_clock::now();

  auto diff = end - start;

  for (int i = 0; i < numClusters * numDim; ++i)
  {
    cout << means[i] << " ";
    if ((i + 1) % numDim == 0)
      cout << endl;
  }

  cout << "computing the means for the clusters took " << chrono::duration <double, milli> (diff).count() << " ms" << endl;

  return 0;
}


