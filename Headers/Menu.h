#ifndef AIZO_PROJEKT1_MENU_H
#define AIZO_PROJEKT1_MENU_H

#include <iostream>
#include <string>

using namespace std;

class Menu
{
public:
    Menu();
    void displayMainMenu(); // menu głowne z wyborem typu danych
    void displayLoadDataMenu(); // menu z opcjami wczytywania danych
    void displayTestOptionMenu(); // czy tablica całkowicie losowa (oryginalna) czy na częściowo posortowana
    void displayPartialSortMenu(); // jeśli częsciowo posortowana, to czy rosnąco czy malejąco
    void displayPartialPercentMenu(); // wybór jaka część tablicy ma być częściowo posortowana
    void displayActionMenu(); // menu z wyborem akcji, czyli albo wyświetlenie tablicy albo sortowanie
    void displaySortingMenu(); // menu z wyborem algorytmu sortowania
    void displayQuickSortMenu(); // wybór miejsca pivota dla sortowania szybkiego
    void displayShellSortMenu(); // wybór odstępów dla algorytmu Shella
    int getChoice() const; // pobranie wyboru od użytkownika
};

#endif //AIZO_PROJEKT1_MENU_H
