#ifndef AIZO_PROJEKT1_SORTINGTESTER_H
#define AIZO_PROJEKT1_SORTINGTESTER_H

#include <iostream>
#include "Array.h"
#include "SortAlgorithm.h"
#include <string>
#include <chrono>
#include <algorithm>
#include <random>

using namespace std;

class SortingTester
{
private:
    string sortType;

    template<typename T> void prepareData(Array<T>& a)
    {
        int size = a.getSize();

        sort(a.getData(), a.getData() + size); // sortujemy całą tablicę rosnąco, bo ten krok jest wykorzystywany
                                                // w każdym innym sortowaniu częsciowym

        if(sortType=="asc33")
        {
            // mieszamy ostatnie 2/3 tablicy
            auto begin = a.getData()+size/3;
            auto end = a.getData()+size;
            shuffle(begin, end, default_random_engine(chrono::system_clock::now().time_since_epoch().count()));
        }
        else if(sortType=="asc66")
        {
            // mieszamy ostatnie 1/3 tablicy
            auto begin = a.getData()+size*2/3;
            auto end = a.getData()+size;
            shuffle(begin, end, default_random_engine(chrono::system_clock::now().time_since_epoch().count()));
        }
        else if(sortType=="desc")
        {
            // odwracamy tablicę posortowaną rosnąco, by uzyskać tablicę malejącą
            reverse(a.getData(), a.getData() + size);
        }
    }

public:
    // funkcja testująca algorytm sortowania; przyjmuje tablicę, algorytm i nazwę algorytmu jako argumenty
    template<typename T> void testSort(Array<T>& array, SortAlgorithm<T>& algorithm, const string& algorithmName, int numberOfTests=100)
    {
        int size = array.getSize(); // pobranie rozmiaru tablicy
        T* dataCopy = new T[size]; // stworzenie nowej tablicy dynamicznej, do której włożymy kopię danych z oryginału

        // WSTĘPNA WERYFIKACJA POPRAWNOŚCI ALGORYTMU SORTOWANIA - dla wcześniej wygenerowanje tablicy testowej
        copy(array.getData(), array.getData() + size, dataCopy); // kopiowanie danych z oryginału
        algorithm.sort(dataCopy, size); // sortowanie kopii danych

        if(is_sorted(dataCopy, dataCopy + size))
        {
            cout << "\nTablica zostala posortowana poprawnie.";
        }
        else
        {
            cout << "\nWystapil blad! Tablica nie jest posortowana poprawnie.";
        }

        cout << "\nCzy chcesz wyswietlic posortowana tablice? (t/n): ";
        char choice;
        cin >> choice;

        if(choice == 't' || choice == 'T')
        {
            cout << "\n{";

            for (int i = 0; i < size; i++)
            {
                cout << dataCopy[i] << (i<size-1 ? ", " : ""); // wyświetlanie elementów tablicy
            }
            cout << "}\n";
        }

        delete[] dataCopy; // zwolnienie zaalokowanej pamięci dla kopii danych do wstępnego sortowania

        // TESTOWANIE SPRAWNOŚCI ALGORYTMU - 100 testów, za każdym razem dla nowej tablicy, wynik uśredniony
        double totalTime = 0; // zmienna do przechowywania łącznego czasu sortowania

        for(int test=0; test<numberOfTests; test++)
        {
            Array<T> testArray; // utworzenie nowej tablicy do testów
            testArray.generateRandomData(size); // wygenerowanie zestawu danych

            if(!sortType.empty())
            {
                prepareData(testArray); // wstępne ustawienie danych do testów
            }

            auto start = chrono::high_resolution_clock::now(); // pierwszy pomiar - start
            algorithm.sort(testArray.getData(), testArray.getSize()); // sortowanie danych
            auto end = chrono::high_resolution_clock::now(); // drugi pomiar - koniec

            chrono::duration<double, milli> singleSortTime = end - start; // obliczenie czasu trwania sortowania z precyzją do milisekund
            totalTime += singleSortTime.count(); // dodanie czasu z aktualnego srtowania do łącznego czasu
        }

        // wyświetlenie łącznego czasu sortowania
        cout << "\nSredni czas sortowania algorytmem " << algorithmName << " po wykonaniu " << numberOfTests <<" testow dla "
        << numberOfTests << " losowo wygenerowanych zestawow danych wynosi: " << totalTime/numberOfTests << " ms\n";
    }

    void setSortType(string st)
    {
        sortType = st;
    }
};

#endif //AIZO_PROJEKT1_SORTINGTESTER_H
