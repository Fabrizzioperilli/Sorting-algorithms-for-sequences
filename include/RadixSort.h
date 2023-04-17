/**
 * @file RadixSort.h
 * @author Fabrizzio Daniell Perilli Martin alu0101138589@ull.edu.es
 * @brief This file contains the RadixSort class.
 * @version 0.1
 * @date 2023-04-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "SortMethod.h"
#include "../src/FunctionsSort.cc"

template <class Key>
class RadixSort : public SortMethod<Key>
{
public:
  RadixSort(std::vector<Key>, unsigned, bool = false);
  void Sort() override;
};


/**
 * @brief Construct a new Radix Sort< Key>:: Radix Sort object
 * 
 * @tparam Key 
 * @param seq 
 * @param size 
 * @param trace
 */
template <class Key>
RadixSort<Key>::RadixSort(std::vector<Key> seq, unsigned size, bool trace) : SortMethod<Key>(seq, size, trace) {}


/**
 * @brief Sort the sequence using the RadixSort algorithm.
 * 
 * @tparam Key 
 */
template <class Key>
void RadixSort<Key>::Sort()
{
  radixSortMethod(this->seq_, this->size_, this->trace_);
}
