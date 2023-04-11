/**
 * @file FuntionsSort.h
 * @author Fabrizzio Daniell Perilli Martin
 * @brief This file contains the functions that are used in method Sort of the derived classes.
 * @version 0.1
 * @date 2023-04-11
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once
#include <vector>
#include <iostream>
#include <algorithm>

template <class Key>
void divide(std::vector<Key> &, int, int, bool, int);

template <class Key>
void heapify(std::vector<Key> &, int, int, bool, int);

template <class Key>
void deltasort(int, std::vector<Key> &, int, bool, int);

/**
 * @brief Overload the operator << to print the sequence.
 *
 * @tparam Key
 * @param os
 * @param seq
 * @return std::ostream&
 */
template <class Key>
std::ostream &operator<<(std::ostream &os, const std::vector<Key> &seq)
{
  for (unsigned i = 0; i < seq.size(); i++)
  {
    if (i == 0)
      os << "| ";
    os << seq[i] << " | ";
  }
  os << std::endl;
  return os;
}

/**
 * @brief Sort the sequence using the Insertion algorithm.
 *
 * @tparam Key
 * @param seq
 * @param size
 * @param trace
 */
template <class Key>
void insertionSortMethod(std::vector<Key> &seq, unsigned size, bool trace = false)
{
  int pos, aux;
  for (size_t i = 0; i < size; i++)
  {
    pos = i;
    aux = seq[i];
    while (pos > 0 && aux < seq[pos - 1])
    {
      std::swap(seq[pos], seq[pos - 1]);
      pos--;
    }
    seq[pos] = aux;
    if (trace)
      std::cout << "i: " << i << " --> " << seq;
  }
  if (!trace)
    std::cout << seq;
}

/**
 * @brief Merge the two parts of the sequence.
 *
 * @tparam Key
 * @param seq
 * @param ini
 * @param mid
 * @param fin
 * @param trace
 * @param count
 */
template <class Key>
void merge(std::vector<Key> &seq, int ini, int mid, int fin, bool trace, int count)
{
  int i, j, k;
  int n1 = mid - ini + 1;
  int n2 = fin - mid;
  std::vector<Key> L(n1), R(n2);

  for (i = 0; i < n1; i++)
    L[i] = seq[ini + i];
  for (j = 0; j < n2; j++)
    R[j] = seq[mid + 1 + j];

  i = 0;
  j = 0;
  k = ini;

  while (i < n1 && j < n2)
  {
    if (L[i] <= R[j])
    {
      seq[k] = L[i];
      i++;
    }
    else
    {
      seq[k] = R[j];
      j++;
    }
    k++;
  }
  while (i < n1)
  {
    seq[k] = L[i];
    i++;
    k++;
  }
  while (j < n2)
  {
    seq[k] = R[j];
    j++;
    k++;
  }
  if (trace)
    std::cout << "i: " << count << " --> " << seq;
  count++;
}

/**
 * @brief Sort the sequence using the MergeSort algorithm.
 *
 * @tparam Key
 * @param seq
 * @param size
 * @param trace
 */
template <class Key>
void mergeSortMethod(std::vector<Key> &seq, unsigned size, bool trace)
{
  int count = 0;
  divide(seq, 0, size - 1, trace, count);
  if (!trace)
    std::cout << seq;
}

/**
 * @brief Divide the sequence in two parts and call the Merge function.
 *
 * @tparam Key
 * @param seq
 * @param ini
 * @param fin
 * @param trace
 * @param count
 */
template <class Key>
void divide(std::vector<Key> &seq, int ini, int fin, bool trace, int count)
{
  if (ini < fin)
  {
    if (trace)
      std::cout << "i: " << count << " --> " << seq;
    count++;

    int mid = (ini + fin) / 2;
    divide(seq, ini, mid, trace, count);
    divide(seq, mid + 1, fin, trace, count);
    merge(seq, ini, mid, fin, trace, count);
  }
}

/**
 * @brief Heapsort algorithm.
 *
 * @tparam Key
 * @param seq
 * @param size
 * @param trace
 */
template <class Key>
void heapSortMethod(std::vector<Key> &seq, unsigned size, bool trace)
{
  int count = 0;
  for (int i = size / 2 - 1; i >= 0; i--)
    heapify(seq, size, i, trace, count);

  for (int i = size - 1; i >= 0; i--)
  {
    std::swap(seq[0], seq[i]);
    heapify(seq, i, 0, trace, count);
  }
  if (!trace)
    std::cout << seq;
}

/**
 * @brief Heapify algorithm.
 *
 * @tparam Key
 * @param seq
 * @param size
 * @param i
 * @param trace
 */
template <class Key>
void heapify(std::vector<Key> &seq, int size, int i, bool trace, int count)
{
  while (2 * i + 1 < size)
  {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int max = left;
    if (right < size && seq[right] > seq[left])
      max = right;
    if (seq[i] >= seq[max])
      break;
    std::swap(seq[i], seq[max]);
    i = max;

    count++;
    if (trace)
      std::cout << "i: " << i << " --> " << seq;
  }
}

/**
 * @brief Sort the sequence using the RadixSort algorithm.
 *
 * @tparam Key
 * @param seq
 * @param size
 * @param trace
 */
template <class Key>
void radixSortMethod(std::vector<Key> &seq, unsigned size, bool trace)
{
  int count = 0;
  auto max = *std::max_element(seq.begin(), seq.end());

  for (int exp = 1; max / exp > 0; exp *= 10)
  {
    int output[size];
    int i, bucket[10] = {0};

    for (i = 0; i < (int)size; i++)
      bucket[(seq[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
      bucket[i] += bucket[i - 1];

    for (i = size - 1; i >= 0; i--)
    {
      output[bucket[(seq[i] / exp) % 10] - 1] = seq[i];
      bucket[(seq[i] / exp) % 10]--;
    }

    for (i = 0; i < (int)size; i++)
      seq[i] = output[i];

    if (trace)
    {
      std::cout << "i: " << count << " --> " << seq;
      count++;
    }
  }

  if (!trace)
    std::cout << seq;
}

/**
 * @brief Sort the sequence using the ShellSort algorithm.
 *
 * @tparam Key
 * @param seq
 * @param size
 * @param alfa
 * @param trace
 */
template <class Key>
void shellSortMethod(std::vector<Key> &seq, int size, bool trace)
{
  int delta = size;
  int count = 0;
  float alfa = 0.0;
  do
  {
    std::cout << "Introduce the alfa value (0 < alfa < 1) : ";
    std::cin >> alfa;
    if (alfa <= 0 || alfa >= 1)
      std::cout << "The value must be between 0 and 1" << std::endl;
  } while (alfa <= 0 || alfa >= 1);

  while (delta > 1)
  {
    delta = delta * alfa;
    deltasort(delta, seq, size, trace, count);
    count++;
  }
  if (!trace)
    std::cout << seq;
}

/**
 * @brief Sort the sequence using the deltasort  algorithm for the ShellSort algorithm.
 *
 * @tparam Key
 * @param delta
 * @param seq
 * @param size
 * @param trace
 * @param count
 */
template <class Key>
void deltasort(int delta, std::vector<Key> &seq, int size, bool trace, int count)
{
  int j;
  for (int i = delta; i < size; i++)
  {
    Key x = seq[i];
    j = i;
    while (j >= delta && seq[j - delta] > x)
    {
      seq[j] = seq[j - delta];
      j = j - delta;
    }
    count++;
    if (trace)
      std::cout << "i: " << count << " --> " << seq;
    seq[j] = x;
  }
}