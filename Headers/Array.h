#ifndef AIZO_PROJEKT1_ARRAY_H
#define AIZO_PROJEKT1_ARRAY_H

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <type_traits>
#include <random>

using namespace std;

// klasa reprezentująca nasz obiekt badań(tablicę), pozwalająca na przechowywanie danych różnego typu
template<typename T> class Array
{
private:
    T* data; // wskaźnik na dynamicznie alokowaną tablicę danych
    int size; // rozmiar tablicy

public:
    // konstruktor inicjalizujący wskaźnik danych na nullptr i rozmiar na 0
    Array() : data(nullptr), size(0) {}

    // destruktor zwalniający zaalokowaną dynamicznie pamięć
    ~Array()
    {
        delete[] data;
    }

    // metoda generująca losowe dane w tablicy
    void generateRandomData(int newSize)
    {
        delete[] data; // usunięcie starego zestawu danych, jeśli taki istnieje
        size = newSize; // ustawienie nowego rozmiaru tablicy podanego przez użytkownika
        data = new T[size]; // zaalokowanie pamięci dla nowej tablicy danych

        // generowanie losowych danych w zależności od typu T (int lub float)
        // początkowo było to robione funckją rand(), ale nie sprawdza się ona przy dużych tablicach
        // bo daje dużo powtarzających się wartości
        random_device rd; // użycie random_device do generowania ziarna dla silnika losowości
        mt19937 gen(rd()); // inicjalizajca slinika losowości

        if(is_integral<T>::value)
        {
            uniform_int_distribution<int> dis(0, size*10); // zakres losowania dla int
            for(int i=0; i<size; i++)
            {
                data[i] = dis(gen);
            }
        }
        else if(is_floating_point<T>::value)
        {
            uniform_real_distribution<float> dis(0.0, 100.0); // zakres losowania dla float
            for (int i=0; i<size; i++)
            {
                data[i] = dis(gen);
            }
        }
    }

    // metoda wczytująca dane z pliku
    bool loadDataFromFile(const string& path)
    {
        ifstream file(path); // otworzenie pliku

        // sprawdzenie, czy plik jest otwarty
        if(!file.is_open())
        {
            return false; // jeśli nie to zwraca false
        }

        int newSize; // zmienna przechowująca rozmiar tablicy pobrany z pliku

        // próba odczytu rozmiaru tablicy z pliku
        if(!(file>>newSize))
        {
            cout << "\nNie udalo sie wczytc rozmiaru tablicy\n";
            return false; // jeśli się nie powiodło, zwraca false
        }

        delete[] data; // wyczyszczenie danych jeśli takie istniały
        size = newSize; // ustawienie nowego rozmiaru tablicy
        data = new T[size]; // alokacja pamięci dla nowej tablicy

        // wczytanie danych z pliku
        for(int i=0; i<size; i++)
        {
            if(!(file>>data[i]))
            {
                cout<<"\nNieprawidlowy typ danych w pliku!!!";
                delete[] data; // w przypadku błędu czyści zaalokowaną pamięć
                data = nullptr;
                size = 0;
                file.close(); // zamknięcie pliku przed zwróceniem false
                return false;
            }
        }

        file.close(); // zamknięcie pliku po wczytaniu danych
        return true; // zwraca true, jeśli wczytanie danych się powiodło
    }

    // metoda wyświetlająca zawartość tablicy
    void display() const
    {
        cout << "\n{";

        for (int i = 0; i < size; i++)
        {
            cout << data[i] << (i < size - 1 ? ", " : "");

            /*if ((i + 1) % 5 == 0) // po wyświetleniu 5 elementów przechodzi do nowej linii
            {
                cout << "\n";
            }*/
        }
        cout << "}\n";
    }

    // metoda zwracająca dane(wskaźnik na dynamiczną tablicę danych)
    T* getData()
    {
        return data;
    }

    // metoda zwracająca rozmiar tablicy
    int getSize() const
    {
        return size;
    }
};

#endif //AIZO_PROJEKT1_ARRAY_H