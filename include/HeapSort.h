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

template <class Key>
class HeapSort : public SortMethod<Key>
{
public:
  HeapSort(std::vector<Key>, unsigned);
  void Sort() override;
};

/**
 * @brief Construct a new Heap Sort< Key>:: Heap Sort object
 * 
 * @tparam Key 
 * @param seq 
 * @param size 
 */
template <class Key>
HeapSort<Key>::HeapSort(std::vector<Key> seq, unsigned size) : SortMethod<Key>(seq, size) {}


/**
 * @brief Sort the sequence using the HeapSort algorithm.
 * 
 * @tparam Key 
 */
template <class Key>
void HeapSort<Key>::Sort()
{
  int count = 0;

  for (size_t i = 1; i < this->size_; i++)
  {
    int pos = i;
    while (pos > 0)
    {
      int father = (pos - 1) / 2;
      if (this->seq_[pos] > this->seq_[father])
      {
        std::swap(this->seq_[pos], this->seq_[father]);
        pos = father;
      }
      else
        break;
    }
    this->Write(count);
    count++;
  }
  for (int i = this->size_ - 1; i > 0; i--)
  {
    std::swap(this->seq_[0], this->seq_[i]);
    int pos = 0;
    int son = 2 * pos + 1;
    while (son < i)
    {
      if (son + 1 < i)
      {
        if (this->seq_[son] < this->seq_[son + 1])
          son++;
      }
      if (this->seq_[pos] < this->seq_[son])
      {
        std::swap(this->seq_[pos], this->seq_[son]);
        pos = son;
        son = 2 * pos + 1;
      }
      else
        break;
    }
    this->Write(count);
    count++;
  }
}