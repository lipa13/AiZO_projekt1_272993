#ifndef AIZO_PROJEKT1_QUICKSORT_H
#define AIZO_PROJEKT1_QUICKSORT_H

#include <iostream>
#include <cstdlib>
#include "SortAlgorithm.h"

using namespace std;

// klasa reprezentująca sortowanie szybkie
template<typename T> class QuickSort : public SortAlgorithm<T>
{
private:
    char pivotPos;

    // wksaźnik do funkcji wyboru pivota (wskaźnik do wartości naszego pivota)
    using PivotChooser = T(*)(T* data, int left, int right);

    // metody wyznaczające wartość pivota
    static T choosePivotRight(T* data, int left, int right)
    {
        return data[right];
    }

    static T choosePivotMiddle(T* data, int left, int right)
    {
        return data[left + (right-left)/2];
    }

    static T choosePivotRandom(T* data, int left, int right)
    {
        return data[left + rand()%(right-left+1)];
    }

    static T choosePivotLeft(T* data, int left, int right)
    {
        return data[left];
    }

    // metoda w której wykonuje się sortowanie i zwraca ona indeks podziału tablicy
    int partition(T* data, int left, int right, PivotChooser pivotChooser)
    {
        int l = left; // lewy skrajny indeks
        int r = right; // prawy skrajny indeks
        T pivot = pivotChooser(data, left, right); // zmienna przechowująca wartość pivota

        while(true)
        {
            while(data[l]<pivot) ++l; // przesuwamy l, aż znajdziemy wartość większą od pivota
            while(data[r]>pivot) --r; // przesuwamy r, aż znajdziemy wartość mniejszą od pivota

            if(l<r) // jeśli indeks zapisany w l jest mniejszy niż indeks zapisany w r to zamieniamy liczby pozycjami i kontynuujemy pętlę
            {
                swap(data[l], data[r]);
                ++l;
                --r;
            }
            else
            {
                if(r==right)
                {
                    --r;
                }
                return r;
            }
        }

    }

    void quickSort(T *data, int l, int r, PivotChooser pivotChooser)
    {
        if(l<r)
        {
            int m = partition(data, l, r, pivotChooser);
            quickSort(data, l, m, pivotChooser);
            quickSort(data, m + 1, r, pivotChooser);
        }
    }

public:

    void sort(T* data, int size) override
    {
        PivotChooser pivotChooser = choosePivotLeft; // domyślnie pivot skrajnie lewy
        if(pivotPos == 'p') pivotChooser = choosePivotRight; // pivot skrajnie prawy
        else if(pivotPos == 's') pivotChooser = choosePivotMiddle; // pivot środkowy
        else if(pivotPos == 'l') pivotChooser = choosePivotRandom; // pivot losowy

        quickSort(data, 0, size - 1, pivotChooser);
    }

    void setPivotPos(char pp)
    {
        pivotPos=pp;
    }
};


#endif //AIZO_PROJEKT1_QUICKSORT_H
