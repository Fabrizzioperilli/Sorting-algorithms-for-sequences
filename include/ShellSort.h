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

template <class Key>
class ShellSort : public SortMethod<Key>
{
public:
  ShellSort(std::vector<Key>, unsigned);
  void Sort() override;
};

/**
 * @brief Construct a new Shell Sort< Key>:: Shell Sort object
 * 
 * @tparam Key 
 * @param seq 
 * @param size 
 */
template <class Key>
ShellSort<Key>::ShellSort(std::vector<Key> seq, unsigned size) : SortMethod<Key>(seq, size) {}


/**
 * @brief Sort the sequence using the ShellSort algorithm.
 * 
 * @tparam Key 
 */
template <class Key>
void ShellSort<Key>::Sort()
{
  int count = 0;
  int alfa = this->size_ / 2;
  int aux, pos;
  std::cout << "Alfa: " << alfa << std::endl;
  while (alfa > 0)
  {
    for (size_t i = alfa; i < this->size_; i++)
    {
      pos = i;
      aux = this->seq_[i];
      while (pos >= alfa && aux < this->seq_[pos - alfa])
      {
        std::swap(this->seq_[pos], this->seq_[pos - alfa]);
        pos -= alfa;
      }
      this->Write(count);
      count++;
    }
    alfa /= 2;
    if (alfa > 0)
      std::cout << "Alfa: " << alfa << std::endl;
  }
}