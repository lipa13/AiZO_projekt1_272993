#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "../Headers/Menu.h"
#include "../Headers/Array.h"
#include "../Headers/InsertionSort.h"
#include "../Headers/HeapSort.h"
#include "../Headers/ShellSort.h"
#include "../Headers/QuickSort.h"
#include "../Headers/SortingTester.h"

using namespace std;

Menu menu;
SortingTester tester;
int choice;
bool backToMainMenu = false; // flaga warunkująca powrót do menu głównego
bool backToArrayOption = false; // flaga warunkująca powrót do menu wyboru opcji badania

// wybór opcji sortowania dla sortowania szybkiego
template<typename T> void chooseQuickSort(Array<T>& array)
{
    while(true)
    {
        menu.displayQuickSortMenu();
        choice = menu.getChoice();

        if(choice==1) // pivot skrajnie lewy
        {
            QuickSort<T> quickSort;
            tester.testSort(array, quickSort, "Quick Sort");
            break;
        }
        else if(choice==2) // pivot skrajnie prawy
        {
            QuickSort<T> quickSort;
            quickSort.setPivotPos('p');
            tester.testSort(array, quickSort, "Quick Sort");
            break;
        }
        else if(choice==3) // pivot środkowy
        {
            QuickSort<T> quickSort;
            quickSort.setPivotPos('s');
            tester.testSort(array, quickSort, "Quick Sort");
            break;
        }
        else if(choice==4) // pivot losowy
        {
            QuickSort<T> quickSort;
            quickSort.setPivotPos('l');
            tester.testSort(array, quickSort, "Quick Sort");
            break;
        }
        else if(choice==5) // cofnij
        {
            break;
        }
        else
        {
            cout << "\nNieznana opcja. Sprobuj ponownie.\n";
        }
    }
}

// wybór opcji sortowania dla algorytmu Shella
template<typename T> void chooseShellSort(Array<T>& array)
{
    while(true)
    {
        menu.displayShellSortMenu();
        choice = menu.getChoice();

        if(choice==1) // Shell, 1959 - sekwencja odstępów o złożoności O(N^2): N/2, N/4,..., 1
        {
            ShellSort<T> shellSort;
            shellSort.setGapSequence(1);
            tester.testSort(array, shellSort, "Shell Sort");
            break;
        }
        else if(choice==2) // Knuth, 1973 - sekwencja odstępów o złożoności O(N^(3/2)): 1, 4, 13, 40, 121, ...
        {
            ShellSort<T> shellSort;
            shellSort.setGapSequence(2);
            tester.testSort(array, shellSort, "Shell Sort");
            break;
        }
        else if(choice==3) // cofnij
        {
            break;
        }
        else
        {
            cout << "\nNieznana opcja. Sprobuj ponownie.\n";
        }
    }
}

// wybór alogrytmu sortowania
template<typename T> void chooseSorting(Array<T>& array)
{
    while(true)
    {
        menu.displaySortingMenu();
        choice = menu.getChoice();

        if(choice==1) // sortowanie przez wstawianie
        {
            InsertionSort<T> insertionSort;
            tester.testSort(array, insertionSort, "Insertion Sort");
            break;
        }
        else if(choice==2) // sortowanie przez kopcowanie
        {
            HeapSort<T> heapSort;
            tester.testSort(array, heapSort, "Heap Sort");
            break;
        }
        else if(choice==3) // sortowanie Shella
        {
            chooseShellSort(array);
            break;
        }
        else if(choice==4) // sortowanie szybkie
        {
            chooseQuickSort(array);
            break;
        }
        else
        {
            cout << "\nNieznana opcja. Sprobuj ponownie.\n";
        }
    }
}

// wybór akcji na tablicy
template<typename T> void chooseAction(Array<T>& array)
{
    while(!backToArrayOption)
    {
        menu.displayActionMenu();
        choice = menu.getChoice();

        if(choice==1) // wyświetlenie tablicy
        {
            array.display();
        }
        else if(choice==2) // sortowanie tablicy
        {
            chooseSorting(array);
        }
        else if(choice==3) // powrót do menu głównego
        {
            backToArrayOption=true;
        }
        else
        {
            cout << "\nNieznana opcja. Sprobuj ponownie.\n";
        }
    }
}

// wybór jaki procent ma zostać posortowane częściowo
template<typename T> void choosePartialSortPercent(Array<T>& array)
{
    while(true)
    {
        if(backToArrayOption)
        {
            break;
        }

        menu.displayPartialPercentMenu();
        choice = menu.getChoice();

        if(choice==1) // 33% tablicy posortowane
        {
            tester.setSortType("asc33");
            sort(array.getData(), array.getData() + array.getSize()); // sortujemy całość rosnąco

            // mieszamy ostatnie 2/3 tablicy
            auto begin = array.getData()+array.getSize()/3;
            auto end = array.getData()+array.getSize();
            shuffle(begin, end, default_random_engine(chrono::system_clock::now().time_since_epoch().count()));

            chooseAction(array);
        }
        else if(choice==2) // 66% tablicy posortowane
        {
            tester.setSortType("asc66");
            sort(array.getData(), array.getData() + array.getSize()); // sortujemy całość rosnąco

            // mieszamy ostatnie 1/3 tablicy
            auto begin = array.getData()+array.getSize()*2/3;
            auto end = array.getData()+array.getSize();
            shuffle(begin, end, default_random_engine(chrono::system_clock::now().time_since_epoch().count()));

            chooseAction(array);
        }
        else if(choice==3) // cała posortowana tablica
        {
            tester.setSortType("asc");
            sort(array.getData(), array.getData() + array.getSize()); // posortowanie tablicy rosnąco
            chooseAction(array);
        }
        else if(choice==4) // cofnij do poprzedniego wyboru
        {
            break;
        }
        else
        {
            cout << "\nNieznana opcja. Sprobuj ponownie.\n";
        }
    }
}

// wybór opcji sortowania częściowego
template<typename T> void choosePartialSortOption(Array<T>& array)
{
    while(true)
    {
        if(backToArrayOption)
        {
            break;
        }

        menu.displayPartialSortMenu();
        choice = menu.getChoice();

        if(choice==1) // tablica częsciowo posortowana rosnąco
        {
            choosePartialSortPercent(array);
        }
        else if(choice==2) // tablica częsciowo posortowana malejąco
        {
            tester.setSortType("desc");
            sort(array.getData(), array.getData() + array.getSize()); // posortowanie tablicy rosnąco
            reverse(array.getData(), array.getData() + array.getSize()); // odwórcenie tablicy, żeby była posortowana malejąco
            chooseAction(array);
        }
        else if(choice==3) // cofnięcie do poprzedniego wyboru
        {
            break;
        }
        else
        {
            cout << "\nNieznana opcja. Sprobuj ponownie.\n";
        }
    }

}

// wybranie na jakiej tablicy chcemy przeprowadzić badanie - całkowicie losowej czy częsciowo posortowanej
template<typename T> void chooseArrayOption(Array<T>& array)
{
    while(!backToMainMenu)
    {
        backToArrayOption = false;
        menu.displayTestOptionMenu();
        choice = menu.getChoice();

        if(choice==1) // zostajemy przy aktualnej tablicy
        {
            chooseAction(array);
        }
        else if(choice==2) // cześciowo posortowana tablica
        {
            choosePartialSortOption(array);
        }
        else if(choice==3) // wyjscie do menu głównego
        {
            backToMainMenu=true;
        }
        else
        {
            cout << "\nNieznana opcja. Sprobuj ponownie.\n";
        }
    }
}

// generowanie danych losowych
template<typename T> void generateData(int size)
{
    Array<T> array;
    array.generateRandomData(size);
    chooseArrayOption(array);
}

// wczytywanie z pliku
template<typename T> void loadFromFile(const string& path)
{
    Array<T> array;
    if(!array.loadDataFromFile(path))
    {
        cout << "\nNie udalo sie wczytac danych.\n";
        return;
    }
    cout << "\nDane poprawnie wczytane.\n";
    //chooseArrayOption
    chooseAction(array);
}

// wywołanie menu z opcjami do wczytywania danych
template<typename T> void chooseLoadData()
{
    while(!backToMainMenu)
    {
        menu.displayLoadDataMenu();
        choice = menu.getChoice();

        if(choice==1) // wczytywanie z pliku
        {
            string path;
            cout << "\nPodaj pelna sciezke pliku: ";
            cin >> path;
            loadFromFile<T>(path);
        }
        else if(choice==2) // generowanie losowe
        {
            int size;
            cout << "\nPodaj rozmiar tablicy: ";
            cin >> size;
            generateData<T>(size);
        }
        else if(choice==3)
        {
            backToMainMenu=true;
        }
        else
        {
            cout << "\nNieznana opcja. Sprobuj ponownie.\n";
        }
    }
}

// funkcja wyboru typu danych - wywołanie menu głównego
void chooseDataType()
{
    do
    {
        tester.setSortType("");
        backToMainMenu=false;
        menu.displayMainMenu();
        choice = menu.getChoice();

        if(choice==1) // typ int
        {
            chooseLoadData<int>();
        }
        else if(choice==2) // typ float
        {
            chooseLoadData<float>();
        }
        else if(choice==3)
        {
            break;
        }
        else
        {
            cout << "\nNieznana opcja. Sprobuj ponownie.\n";
        }
    }while(true);
}

int main()
{
    srand(time(NULL)); // ustawienie ziarna generatora liczb losowych
    chooseDataType(); // rozpoczęcie programu
    return 0;
}

