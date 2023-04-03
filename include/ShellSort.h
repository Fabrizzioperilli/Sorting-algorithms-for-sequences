#include "SortMethod.h"

template <class Key>
class ShellSort : public SortMethod<Key>
{
public:
  ShellSort(std::vector<Key>, unsigned);
  void Sort() override;
};

template <class Key>
ShellSort<Key>::ShellSort(std::vector<Key> seq, unsigned size) : SortMethod<Key>(seq, size) {}

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