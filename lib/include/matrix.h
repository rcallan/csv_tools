//
//  matrix.h
//

#ifndef ____matrix__
#define ____matrix__

#include <vector>

template<typename T>
class matrix
{
public:
  matrix();
  matrix(unsigned nrows, unsigned ncols);
  // use a bad_size object if either size if zero
  class wrong_size { };
  
  T& operator() (unsigned i, unsigned j);
  const T& operator() (unsigned i, unsigned j) const;
  
  // use a bounds_violation object if i or j is too large
  class bounds_violation { };
  
  unsigned nrows() const;
  unsigned ncols() const;
  
  void resize_matrix(unsigned nrows, unsigned ncols);
  
//private:
public:
  std::vector<std::vector<T>> data_;
};

template<typename T>
inline unsigned matrix<T>::nrows() const
{
  return data_[0].size();
}

template<typename T>
inline unsigned matrix<T>::ncols() const
{
  return data_.size();
}

template<typename T>
inline void matrix<T>::resize_matrix(unsigned nrows, unsigned ncols)
{
  //if (nrows == 0 || ncols == 0)
  //  throw wrong_size();
  data_.resize(ncols);
  for (unsigned i = 0; i < nrows; ++i)
    data_[i].resize(nrows);
}

template<typename T>
inline T& matrix<T>::operator() (unsigned row, unsigned col)
{
  if (row >= nrows() || col >= ncols()) throw bounds_violation();
  return data_[col][row];
}

template<typename T>
inline const T& matrix<T>::operator() (unsigned row, unsigned col) const
{
  if (row >= nrows() || col >= ncols()) throw bounds_violation();
  return data_[col][row];
}

template<typename T>
matrix<T>::matrix() : data_(0) { }

template<typename T>
matrix<T>::matrix(unsigned nrows, unsigned ncols)
: data_(ncols)
{
  if (nrows == 0 || ncols == 0)
    throw wrong_size();
  for (unsigned i = 0; i < nrows; ++i)
    data_[i].resize(nrows);
}


#endif /* defined(____matrix__) */
