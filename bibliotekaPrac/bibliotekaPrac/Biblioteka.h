#include <string>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <array>
#include <stdexcept>
#include <cstring>  // strtok, etc
#include <sstream>
#include <utility>
#include <windows.h>
#include <filesystem>
#include <map>
#include <boost/algorithm/string.hpp>
#include <limits>

extern const std::string lineId[];
extern const int MINIMALNY_ROK;
extern const int ILE_WARTOSCI_PRACA;

class Praca;

class Biblioteka {

    public:

    Biblioteka() {
        bool startEmpty = false;
    }

    std::vector<std::pair<int, Praca>> listaPrac;

    int getLastId(std::vector<std::pair<int, Praca>>&);

    void wyswietlLiczbePrac(std::vector<std::pair<int, Praca>>);

    void editAgain(bool&);

    // Inicjalizuje menu biblioteki
    void menu(Biblioteka & biblioteka);

    void wypiszPrace(Praca & praca);

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

    // Wyszukuje 
    void szukaj();

    // Wyswietla liczbe prac w bibliotece
    void ilePrac();

    // Wyswietla liczbe prac dla danego promotora
    void ilePracPromotora();

    // Wyswietla najczesciej wystepujace slowa kluczowe
    void najczSlowaKluczowe();

};

