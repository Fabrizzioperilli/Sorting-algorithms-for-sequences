/**
 * @file HeapSort.h
 * @author Fabrizzio Daniell Perilli Martin alu0101138589@ull.edu.es
 * @brief This file contains the HeapSort class.
 * @version 0.1
 * @date 2023-04-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "SortMethod.h"
#include "../src/FunctionsSort.cc"


template <class Key>
class HeapSort : public SortMethod<Key>
{
public:
  HeapSort(std::vector<Key>, unsigned, bool = false);
  void Sort() override;
};

/**
 * @brief Construct a new Heap Sort< Key>:: Heap Sort object
 * 
 * @tparam Key 
 * @param seq 
 * @param size 
 * @param trace
 */
template <class Key>
HeapSort<Key>::HeapSort(std::vector<Key> seq, unsigned size, bool trace) : SortMethod<Key>(seq, size, trace) {}


/**
 * @brief Sort the sequence using the HeapSort algorithm.
 * 
 * @tparam Key 
 */
template <class Key>
void HeapSort<Key>::Sort()
{
  heapSortMethod(this->seq_, this->size_, this->trace_);
}