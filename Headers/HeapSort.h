#ifndef AIZO_PROJEKT1_HEAPSORT_H
#define AIZO_PROJEKT1_HEAPSORT_H

#include <iostream>
#include "SortAlgorithm.h"

using namespace std;

// klasa reprezentująca sortowanie przez kopcowanie
template<typename T> class HeapSort : public SortAlgorithm<T>
{
private:
    // funkcja pomocnicza do budowania kopca
    // przyjmuje tablicę, jej rozmiar i indeks 'i' obecnego rodzica, od którego rozpoczyna się proces porównywania
    void heapify(T* data, int n, int i)
    {
        int largest = i; // indeks rodzica
        int left = (2*i)+1; // indeks lewego potomka
        int right = (2*i)+2; // indeks prawego potomka

        // sprawdzenie, czy lewe dziecko jest większe niż rodzic.
        if(left<n && data[left]>data[largest])
        {
            largest = left;
        }

        // sprawdzenie, czy prawe dziecko jest większe niż rodzic.
        if(right<n && data[right]>data[largest])
        {
            largest = right;
        }

        // jeśli któryś z dzieci jest większy, zamień go z rodzicem i kontynuuj kopcowanie.
        if(largest!=i)
        {
            swap(data[i], data[largest]);
            heapify(data, n, largest); // rekurencyjne wywołanie heapify, by sprawdzić czy po zmianie rodzica zachowane zostały właściwości kopca
                                         // czyli wywołujemy heapify tylko że tym razem indeks rodzica to indeks elementu, który zamieniliśmy
        }
    }

public:
    void sort(T* data, int size) override
    {
        // budowanie kopca (reorganizacja tablicy)
        // zaczynamy od połowy tablicy, bo dalej niż połowa są tylko liście i potem zmniejszamy indeks aż dojdziemy do korzenia
        for(int i=(size/2)-1; i>=0; i--)
        {
            heapify(data, size, i);
        }

        // proces usuwania największego elementu z kopca (sortowania tablicy)
        for (int i=size-1; i>0; i--)
        {
            swap(data[0], data[i]); // przeniesienie korzenia na koniec
            heapify(data, i, 0); // ponowne wywołanie funkcji heapify na zredukowanym kopcu
        }
    }
};

#endif //AIZO_PROJEKT1_HEAPSORT_H
