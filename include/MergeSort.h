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

template <class Key>
MergeSort<Key>::MergeSort(std::vector<Key> seq, unsigned size) : SortMethod<Key>(seq, size) {}

template <class Key>
void MergeSort<Key>::Sort()
{
  Divide(0, this->size_ - 1);
  this->Write(count);
  count++;
}

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