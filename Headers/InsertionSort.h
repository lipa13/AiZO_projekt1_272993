#ifndef AIZO_PROJEKT1_INSERTIONSORT_H
#define AIZO_PROJEKT1_INSERTIONSORT_H

#include <iostream>
#include "SortAlgorithm.h"

// klasa reprezentująca sortowanie algorytmem przez wstawianie
template<typename T> class InsertionSort : public SortAlgorithm<T>
{
public:
    void sort(T* data, int size) override
    {
        for(int i=1; i<size; i++)
        {
            T key = data[i]; // bieżący element do wstawiania
            int j = i; // indeks elementu poprzedniego, z którym porównujemy

            while(j>0 && data[j-1]>key)
            {
                data[j] = data[j-1];
                j--;
            }

            data[j] = key;
        }
    }
};

#endif //AIZO_PROJEKT1_INSERTIONSORT_H
