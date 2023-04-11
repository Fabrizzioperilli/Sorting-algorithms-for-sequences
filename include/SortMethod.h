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

#pragma once
#include <vector>
#include <iostream>

template <class Key>
class SortMethod
{
protected:
  unsigned size_;
  std::vector<Key> seq_;
  bool trace_;

public:
  SortMethod();
  SortMethod(std::vector<Key>&, unsigned, bool = false);
  virtual void Sort() = 0;
};


/**
 * @brief Construct a new Sort Method< Key>:: Sort Method object
 * 
 * @tparam Key 
 */
template <class Key>
SortMethod<Key>::SortMethod() {}


/**
 * @brief Construct a new Sort Method< Key>:: Sort Method object
 * 
 * @tparam Key 
 * @param seq 
 * @param size 
 * @param trace 
 */
template <class Key>
SortMethod<Key>::SortMethod(std::vector<Key>& seq, unsigned size, bool trace)
{
  seq_ = seq;
  size_ = size;
  trace_ = trace;
}