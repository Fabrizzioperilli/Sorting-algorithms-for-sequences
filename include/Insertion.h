/**
 * @file Insertion.h
 * @author @author Fabrizzio Daniell Perilli Martin alu0101138589@ull.edu.es
 * @brief 
 * @version 0.1
 * @date 2023-04-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "SortMethod.h"

template <class Key>
class Insertion : public SortMethod<Key>
{
public:
  Insertion(std::vector<Key>, unsigned);
  void Sort() override;
};

/**
 * @brief Construct a new Insertion< Key>:: Insertion object
 * 
 * @tparam Key 
 * @param seq 
 * @param size 
 */
template <class Key>
Insertion<Key>::Insertion(std::vector<Key> seq, unsigned size) : SortMethod<Key>(seq, size) {}


/**
 * @brief Sort the sequence using the Insertion algorithm.
 * 
 * @tparam Key 
 */
template <class Key>
void Insertion<Key>::Sort()
{
  int count = 0;
  int pos, aux;
  for (size_t i = 0; i < this->size_; i++)
  {
    pos = i;
    aux = this->seq_[i];
    while (pos > 0 && aux < this->seq_[pos - 1])
    {
      std::swap(this->seq_[pos], this->seq_[pos - 1]);
      pos--;
    }
    this->seq_[pos] = aux;
    this->Write(count);
    count++;
  }
}
