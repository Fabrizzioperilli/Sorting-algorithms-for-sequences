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

#include "../include/SortMethod.h"

template <class Key>
class MergeSort : public SortMethod<Key>
{
public:
  MergeSort(std::vector<Key>, unsigned);
  void Sort() override;

private:
  void Merge(int, int, int);
  void Divide(int, int);
  int count = 0;
};

/**
 * @brief Construct a new Merge Sort< Key>:: Merge Sort object
 * 
 * @tparam Key 
 * @param seq 
 * @param size 
 */
template <class Key>
MergeSort<Key>::MergeSort(std::vector<Key> seq, unsigned size) : SortMethod<Key>(seq, size) {}


/**
 * @brief Sort the sequence using the MergeSort algorithm.
 * 
 * @tparam Key 
 */
template <class Key>
void MergeSort<Key>::Sort()
{
  Divide(0, this->size_ - 1);
  this->Write(count);
  count++;
}


/**
 * @brief Divide the sequence in two parts and call the Merge function.
 * 
 * @tparam Key 
 * @param ini 
 * @param fin 
 */
template <class Key>
void MergeSort<Key>::Divide(int ini, int fin)
{

  if (ini < fin)
  {
    int middle = ini + (fin - ini) / 2;
    Divide(ini, middle);
    Divide(middle + 1, fin);
    Merge(ini, middle, fin);
    this->Write(count);
    count++;
  }
}


/**
 * @brief Merge of the sequence.
 * 
 * @tparam Key 
 * @param ini 
 * @param middle 
 * @param fin 
 */
template <class Key>
void MergeSort<Key>::Merge(int ini, int middle, int fin)
{
  int i, j, k;
  int n1 = middle - ini + 1;
  int n2 = fin - middle;

  std::vector<Key> L(n1), R(n2);

  for (i = 0; i < n1; i++)
    L[i] = this->seq_[ini + i];
  for (j = 0; j < n2; j++)
    R[j] = this->seq_[middle + 1 + j];

  i = 0;
  j = 0;
  k = ini;

  while (i < n1 && j < n2)
  {
    if (L[i] <= R[j])
    {
      this->seq_[k] = L[i];
      i++;
    }
    else
    {
      this->seq_[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1)
  {
    this->seq_[k] = L[i];
    i++;
    k++;
  }

  while (j < n2)
  {
    this->seq_[k] = R[j];
    j++;
    k++;
  }

  this->Write(count);
  count++;
}