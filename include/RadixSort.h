#include "SortMethod.h"
#include <algorithm>

template <class Key>
class RadixSort : public SortMethod<Key>
{
public:
  RadixSort(std::vector<Key>, unsigned);
  void Sort() override;
};

template <class Key>
RadixSort<Key>::RadixSort(std::vector<Key> seq, unsigned size) : SortMethod<Key>(seq, size) {}

template <class Key>
void RadixSort<Key>::Sort()
{
  int count = 0;
  auto max = *std::max_element(this->seq_.begin(), this->seq_.end());

  for (int exp = 1; max / exp > 0; exp *= 10)
  {
    int output[this->size_];
    int i, bucket[10] = {0};

    for (i = 0; i < (int)this->size_; i++)
      bucket[(this->seq_[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
      bucket[i] += bucket[i - 1];

    for (i = this->size_ - 1; i >= 0; i--)
    {
      output[bucket[(this->seq_[i] / exp) % 10] - 1] = this->seq_[i];
      bucket[(this->seq_[i] / exp) % 10]--;
    }

    for (i = 0; i < (int)this->size_; i++)
      this->seq_[i] = output[i];

    this->Write(count);
    count++;
  }
}
