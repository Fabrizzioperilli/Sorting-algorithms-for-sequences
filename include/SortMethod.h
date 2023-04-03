/**
 * @file SortMethod.h
 * @author Fabrizzio Daniell Perilli Martin alu0101138589@ull.edu.es
 * @brief This a abstract class that contains the basic methods for the sorting algorithms.
 * @version 0.1
 * @date 2023-04-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <vector>
#include <iostream>
#pragma once

template <class Key>
class SortMethod
{
protected:
  unsigned size_;
  std::vector<Key> seq_;

public:
  SortMethod() {}
  SortMethod(std::vector<Key>, unsigned);
  virtual void Sort() = 0;
  void Write(int);
};


/**
 * @brief Construct a new Sort Method< Key>:: Sort Method object
 * 
 * @tparam Key 
 * @param seq 
 * @param size 
 */
template <class Key>
SortMethod<Key>::SortMethod(std::vector<Key> seq, unsigned size)
{
  seq_ = seq;
  size_ = size;
}


/**
 * @brief Write the sequence in the console.
 * 
 * @tparam Key 
 * @param count 
 */
template <class Key>
void SortMethod<Key>::Write(int count)
{
  std::cout << "i: " << count << " -->";
  for (unsigned i = 0; i < size_; i++)
  {
    if (i == 0)
      std::cout << " | ";
    std::cout << seq_[i] << " | ";
  }
  std::cout << std::endl;
}