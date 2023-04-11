/**
 * @file MergeSort.h
 * @author Fabrizzio Daniell Perilli Martin alu0101138589@ull.edu.es
 * @brief This file contains the MergeSort class.
 * @version 0.1
 * @date 2023-04-03
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "SortMethod.h"
#include "FuntionsSort.h"

template <class Key>
class MergeSort : public SortMethod<Key>
{
public:
  MergeSort(std::vector<Key>, unsigned, bool = false);
  void Sort() override;
};


/**
 * @brief Construct a new Merge Sort< Key>:: Merge Sort object
 *
 * @tparam Key
 * @param seq
 * @param size
 * @param trace
 */
template <class Key>
MergeSort<Key>::MergeSort(std::vector<Key> seq, unsigned size, bool trace) : SortMethod<Key>(seq, size, trace) {}


/**
 * @brief Sort the sequence using the MergeSort algorithm.
 *
 * @tparam Key
 */
template <class Key>
void MergeSort<Key>::Sort()
{
  mergeSortMethod(this->seq_, this->size_, this->trace_);
}