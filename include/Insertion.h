#include "SortMethod.h"

template <class Key>
class Insertion : public SortMethod<Key>
{
public:
  Insertion(std::vector<Key>, unsigned);
  void Sort() override;
};

template <class Key>
Insertion<Key>::Insertion(std::vector<Key> seq, unsigned size) : SortMethod<Key>(seq, size) {}

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
