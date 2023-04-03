/**
 * @file main.cc
 * @author Fabrizzio Daniell Perilli Martin alu0101138589@ull.edu.es
 * @brief This file contains the main function of the program.
 * @version 0.1
 * @date 2023-04-03
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

#include "../include/SortMethod.h"
#include "../include/Insertion.h"
#include "../include/MergeSort.h"
#include "../include/ShellSort.h"
#include "../include/HeapSort.h"
#include "../include/RadixSort.h"

int main()
{
    std::vector<long> seq;
    unsigned option_alg, sequence_size, option_value_seq;
    int option_menu;
    do
    {
        seq.clear();
        std::cout << "---Sorting algorithms for sequences.---" << std::endl;
        std::cout << "Enter the size of sequence: ";
        std::cin >> sequence_size;

        if (sequence_size <= 0)
        {
            std::cout << "The sequence size must be greater than 0." << std::endl;
            exit(EXIT_FAILURE);
        }

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
            std::cout << "Wrong option. Enter option again" << std::endl;
            exit(EXIT_FAILURE);
            break;
        }
        do
        {
            std::cout << "\nChoose the algorithm you want to use." << std::endl;
            std::cout << "[1] Insertion " << std::endl;
            std::cout << "[2] MergeSort " << std::endl;
            std::cout << "[3] ShellSort " << std::endl;
            std::cout << "[4] HeapSort " << std::endl;
            std::cout << "[5] RadixSort " << std::endl;
            std::cout << "Option: ";
            std::cin >> option_alg;

            SortMethod<long> *v;
            switch (option_alg)
            {
            case 1:
                v = new Insertion<long>(seq, sequence_size);
                break;
            case 2:
                v = new MergeSort<long>(seq, sequence_size);
                break;
            case 3:
                v = new ShellSort<long>(seq, sequence_size);
                break;
            case 4:
                v = new HeapSort<long>(seq, sequence_size);
                break;
            case 5:
                v = new RadixSort<long>(seq, sequence_size);
                break;
            default:
                std::cout << "Wrong option. Enter option again" << std::endl;
                exit(EXIT_FAILURE);
                break;
            }

            std::cout << "\nOriginal sequence: ";
            for (size_t i = 0; i < sequence_size; i++)
            {
                if (i == 0)
                    std::cout << " | ";
                std::cout << seq[i] << " | ";
            }
            std::cout << std::endl;

            std::cout << "\nSorted sequence: " << std::endl;

            auto start = std::chrono::high_resolution_clock::now();
            v->Sort();
            auto end = std::chrono::high_resolution_clock::now();

            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
            std::cout << "\nTime taken by function: " << duration.count() << " ms" << std::endl;

            std::cout << std::endl;
            std::cout << "[1] Use other algorithm" << std::endl;
            std::cout << "[2] Use other sequence" << std::endl;
            std::cout << "[0] Exit" << std::endl;
            std::cout << "Option: ";
            std::cin >> option_menu;

        } while (option_menu == 1);
    } while (option_menu == 2);

    return 0;
}