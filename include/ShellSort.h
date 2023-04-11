/**
 * @file ShellSort.h
 * @author Fabrizzio Daniell Perilli Martin alu0101138589@ull.edu.es
 * @brief This file contains the ShellSort class.
 * @version 0.1
 * @date 2023-04-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "SortMethod.h"
#include "FuntionsSort.h"

template <class Key>
class ShellSort : public SortMethod<Key>
{
public:
  ShellSort(std::vector<Key>, unsigned, bool = false);
  void Sort() override;
};

/**
 * @brief Construct a new Shell Sort< Key>:: Shell Sort object
 * 
 * @tparam Key 
 * @param seq 
 * @param size 
 * @param trace
 */
template <class Key>
ShellSort<Key>::ShellSort(std::vector<Key> seq, unsigned size, bool trace) : SortMethod<Key>(seq, size, trace) {}


/**
 * @brief Sort the sequence using the ShellSort algorithm.
 * 
 * @tparam Key 
 */
template <class Key>
void ShellSort<Key>::Sort()
{
  shellSortMethod(this->seq_, this->size_, this->trace_);
}