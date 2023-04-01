#include <vector>
#include <iostream>
#pragma once

template <class Key>
class SortMethod
{
protected:
  unsigned size_;
  std::vector<Key> seq_;

public:
  SortMethod() {}
  SortMethod(std::vector<Key>, unsigned);
  virtual void Sort() = 0;
  void Write(int);
};

template <class Key>
SortMethod<Key>::SortMethod(std::vector<Key> seq, unsigned size)
{
  seq_ = seq;
  size_ = size;
}

template <class Key>
void SortMethod<Key>::Write(int count)
{
  std::cout << "i: " << count << " -->";
  for (unsigned i = 0; i < size_; i++)
  {
    if (i == 0)
      std::cout << " | ";
    std::cout << seq_[i] << " | ";
  }
  std::cout << std::endl;
}