/**
 * @file Insertion.h
 * @author @author Fabrizzio Daniell Perilli Martin alu0101138589@ull.edu.es
 * @brief This file contains the Insertion class.
 * @version 0.1
 * @date 2023-04-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "SortMethod.h"
#include "../src/FunctionsSort.cc"



template <class Key>
class Insertion : public SortMethod<Key>
{
public:
  Insertion(std::vector<Key>, unsigned, bool = false);
  void Sort() override;
};

/**
 * @brief Construct a new Insertion< Key>:: Insertion object
 * 
 * @tparam Key 
 * @param seq 
 * @param size 
 * @param trace 
 */
template <class Key>
Insertion<Key>::Insertion(std::vector<Key> seq, unsigned size, bool trace) : SortMethod<Key>(seq, size, trace) {}


/**
 * @brief Sort the sequence using the Insertion algorithm.
 * 
 * @tparam Key 
 */
template <class Key>
void Insertion<Key>::Sort()
{
  insertionSortMethod(this->seq_, this->size_, this->trace_);
}
