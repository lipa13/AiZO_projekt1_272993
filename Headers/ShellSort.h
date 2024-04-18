#ifndef AIZO_PROJEKT1_SHELLSORT_H
#define AIZO_PROJEKT1_SHELLSORT_H

#include <iostream>
#include "SortAlgorithm.h"

using namespace std;

// klasa reprezentująca sortowanie algorytmem Shella
template<typename T> class ShellSort : public SortAlgorithm<T>
{
private:
    int gapSequence; // flaga warunkująca wzór wykorzystany w sortowaniu

public:
    void sort(T* data, int size) override
    {
        if(gapSequence==1) // Shell, 1959 - sekwencja odstępów o złożoności O(N^2): N/2, N/4,..., 1
        {
            // pętla zewnętrzna ustalająca wielkość odstępów
            for(int gap=size/2; gap>0; gap/=2)
            {
                // dla każdego odstępu wykonujemy sortowanie przez wstawianie
                for(int i=gap; i<size; i++)
                {
                    T tmp = data[i]; // zapisujemy wartość bieżącego elementu
                    int j;

                    // przesuwamy elementy większe niż tmp o ustalony odstęp w prawo
                    for(j=i; j>=gap && data[j-gap]>tmp; j-=gap)
                    {
                        data[j] = data[j-gap];
                    }

                    data[j] = tmp; // wstawienie tmp w odpowiednie miejsce
                }
            }
        }
        else if (gapSequence==2) // Knuth, 1973 - sekwencja odstępów o złożoności O(N^(3/2)): 1, 4, 13, 40, 121, ...
        {
            int gap = 1; // na początku odstęp równy 1

            // obliczamy maksymalny odstęp mniejszy niż jedna trzecia rozmiaru tablicy
            while(gap<size/3) // gap<size/3, żeby gap nie był za duży, bo by wpływało na efektywność algorytmu
            {
                gap = (gap*3)+1;
            }

            // dla każdego wcześniej obliczonego odstępu wykonujemy sortowanie przez wstawianie
            for (; gap>0; gap=(gap-1)/3)
            {
                for (int i=gap; i<size; i++)
                {
                    T tmp = data[i];
                    int j;

                    // przesuwamy elementy większe niż tmp o ustalony odstęp w prawo
                    for (j=i; j>=gap && data[j-gap]>tmp; j-=gap)
                    {
                        data[j] = data[j-gap];
                    }

                    data[j] = tmp; // wstawienie tmp w odpowiednie miejsce
                }
            }
        }
    }

    void setGapSequence(int gs)
    {
        gapSequence = gs;
    }
};


#endif //AIZO_PROJEKT1_SHELLSORT_H
