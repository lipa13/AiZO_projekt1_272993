#include "../Headers/Menu.h"
#include <iostream>
#include <limits>

using namespace std;

Menu::Menu(){}

void Menu::displayMainMenu()
{
    cout << "\n=== MENU GLOWNE ===\n";
    cout << "WYBIERZ TYP DANYCH W TABLICY\n";
    cout << "1. int\n";
    cout << "2. float\n";
    cout << "3. Zakoncz program\n";
}

void Menu::displayLoadDataMenu()
{
    cout << "\n=== WCZYTYWANIE DANYCH ===\n";
    cout << "1. Wczytaj tablice z pliku\n";
    cout << "2. Generuj losowa tablice\n";
    cout << "3. Powrot do menu glownego\n";
}

void Menu::displayTestOptionMenu()
{
    cout << "\n=== NA JAKIEJ TABLICY CHCESZ PRACOWAC? ===\n";
    cout << "1. Aktualnej tablicy\n";
    cout << "2. Czesciowo posortowanej tablicy\n";
    cout << "3. Powrot do menu glownego\n";
}

void Menu::displayPartialSortMenu()
{
    cout << "\n=== JAK POSORTOWAC CZESCIOWO TABLICE? ===\n";
    cout << "1. Rosnaco\n";
    cout << "2. Malejaco\n";
    cout << "3. Cofnij\n";
}

void Menu::displayPartialPercentMenu()
{
    cout << "\n=== JAKI PROCENT TABLICY MA ZOSTAC POSORTOWANY? ===\n";
    cout << "1. 33% tablicy posortowane\n";
    cout << "2. 66% tablicy posortowane\n";
    cout << "3. 100% tablicy posortowane\n";
    cout << "4. Cofnij\n";
}

void Menu::displayActionMenu()
{
    cout << "\n=== OPERACJE NA TABLICY ===\n";
    cout << "1. Wyswietl tablice do badan\n";
    cout << "2. Sortuj tablice\n";
    cout << "3. Powrot do opcji badania\n";
}

void Menu::displaySortingMenu()
{
    cout << "\n=== ALGORYTMY SORTOWANIA ===\n";
    cout << "1. Sortowanie przez wstawianie\n";
    cout << "2. Sortowanie przez kopcowanie\n";
    cout << "3. Sortowanie Shella\n";
    cout << "4. Sortowanie szybkie\n";
}

void Menu::displayQuickSortMenu()
{
    cout << "\n=== PIVOT ===\n";
    cout << "1. Skrajnie lewy\n";
    cout << "2. Skrajnie prawy\n";
    cout << "3. Srodkowy\n";
    cout << "4. Losowy\n";
    cout << "5. Cofnij\n";
}

void Menu::displayShellSortMenu()
{
    cout << "\n=== JAKIE ODSTEPY ===\n";
    cout << "1. Shell, 1959\n";
    cout << "2. Knuth, 1973\n";;
    cout << "3. Cofnij\n";
}

int Menu::getChoice() const
{
    int choice;

    // pętla, która będzie kontynuowana do momentu poprawnego wprowadzenia danych
    while(true)
    {
        cout << "\nWybierz opcje: ";
        cin >> choice;

        // warunek sprawdzający czy zostały poprawnie wpisane dane
        if(cin.fail())
        {
            cin.clear(); // usunięcie flagi błędu
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignorowanie pozostałych danych w buforze do końca linii
            cout << "\nNieprawidlowe dane. Wprowadz liczbe!!!";
        }
        else
        {
            break; // koniec pętli po wpisaniu poprawnych danych
        }
    }

    return choice;
}
