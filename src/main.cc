#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../include/SortMethod.h"
#include "../include/Insertion.h"

int main()
{
    std::vector<long> seq;
    unsigned option_alg, sequence_size, option_value_seq;

    std::cout << "---Sorting algorithms for sequences.---" << std::endl;
    std::cout << "Enter the size of sequence: ";
    std::cin >> sequence_size;

    std::cout << "Do you want insert the sequence values manually or randomly? " << std::endl;
    std::cout << "[1] Manual " << std::endl;
    std::cout << "[2] Random " << std::endl;
    std::cout << "Option:  ";
    std::cin >> option_value_seq;

    switch (option_value_seq)
    {
    case 1:
        std::cout << "Insert values: " << std::endl;
        long value;
        for (size_t i = 0; i < sequence_size; i++)
        {
            std::cout << "i[" << i << "]: ";
            std::cin >> value;
            seq.push_back(value);
        }
        break;
    case 2:
        srand(time(NULL));
        for (size_t i = 0; i < sequence_size; i++)
            seq.push_back(rand() % (9999 - 1000 + 1) + 1000);
        break;
    default:
        break;
    }

    std::cout << "Choose the algorithm you want to use." << std::endl;
    std::cout << "[1] Insertion." << std::endl;
    std::cout << "[2] MergeSort." << std::endl;
    std::cout << "[3] ShellSort." << std::endl;
    std::cout << "[4] HeapSort." << std::endl;
    std::cout << "[5] RadixSort." << std::endl;
    std::cout << "Option: ";
    std::cin >> option_alg;

    SortMethod<long> *v;
    switch (option_alg)
    {
    case 1:
        v = new Insertion<long>(seq, sequence_size);
        break;
    default:
        std::cout << "Wrong option. Enter option again" << std::endl;
        break;
    }
    v->Sort();

    return 0;
}