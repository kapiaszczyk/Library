#define NOMINMAX

#include <limits>
#include <algorithm>
#include <vector>
#include <map>
#include <string>

#include <iostream>
#include <fstream>

#include <filesystem>                                   // Checks if the source file is empty
#include <boost/algorithm/string.hpp>                   // To lowercase, splitting words to a vector

extern const std::string IDENTYFIKATORY_DANYCH[];
extern const int MINIMALNY_ROK;
extern const int ILE_WARTOSCI_PRACA;

class Praca;

class Biblioteka {

    public:

    Biblioteka() {
        bool startEmpty = false;
    }

    std::vector<std::pair<int, Praca>> listaPrac;

    // Przekazuje ostatnio u¿yte ID
    int getLastId(std::vector<std::pair<int, Praca>>&);

    // Wyswietla liczbe prac przechowywana w danym momencie w bibliotece
    void wyswietlLiczbePrac(std::vector<std::pair<int, Praca>>);

    // Funkcja umozliwiajace edytowanie wielu elementu pracy
    void editAgain(bool&);

    // Sprawdza, czy plik wejsciowy jest pusty
    bool isLibraryEmpty(Biblioteka biblioteka);

    // Inicjalizuje menu biblioteki
    void menu(Biblioteka & biblioteka);

    void wypiszPrace(Praca & praca);

    // Funkcja sprawdza, jaka wartosc zawiera dana linia w pliku
    int checkValue(std::string line, const std::string id[]);

    // Wczytuje wszystkie prace
    void wczytajPrace(std::vector<std::pair<int, Praca>>&);

    // Wyswietla skrocona liste prac
    void wyswSkrocone(std::vector<std::pair<int, Praca>>);

    // Wyswietla pelna liste prac
    void wyswPelne(std::vector<std::pair<int, Praca>>);

    // Funkcja pozwalajace dodac nowa prace
    void dodajPrace();

    // Funkcja zapisujaca prace w pliku i w bibliotece
    void zapiszPrace(std::vector<std::pair<int, Praca>>&);

    // Pozwala edytowac wybrana prace
    void edytujPrace(std::vector<std::pair<int, Praca>>&);

    // Wyszukuje ID prac wg wybranego kryterium
    void szukaj();

    // Wyswietla liczbe prac w bibliotece
    void ilePrac();

    // Wyswietla liczbe prac dla danego promotora
    void ilePracPromotora();

    // Wyswietla najczesciej wystepujace slowa kluczowe
    void najczSlowaKluczowe();

};

