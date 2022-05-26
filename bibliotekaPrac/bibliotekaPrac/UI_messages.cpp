#include <iostream>
#include <vector>
#include "UI_messages.h"
#include "Praca.h"

void printTypeList(const std::vector<std::string> dozwoloneTypy) {
    for (unsigned int i = 0; i < dozwoloneTypy.size(); i++) std::cout << dozwoloneTypy[i] << std::endl;
}

void editMessage() {
    std::cout << "Ktora wartosc chcesz edytowac?" << std::endl;
    std::cout << "[1] Nazwisko autora" << std::endl;
    std::cout << "[2] Nazwisko promotora" << std::endl;
    std::cout << "[3] Tytul" << std::endl;
    std::cout << "[4] Slowo kluczowe" << std::endl;
    std::cout << "[5] Streszczenie" << std::endl;
    std::cout << "[3] Rok powstania" << std::endl;
}

void menuMessage() {

    std::cout << "Wybierz funkcje programu. Aby wyjsc z programu, nacisnij X." << std::endl;
    std::cout << "[1] Dodawanie pracy" << std::endl;
    std::cout << "[2] Edycja pracy" << std::endl;
    std::cout << "[3] Wyswietlanie listy prac w formacie skroconym" << std::endl;
    std::cout << "[4] Wyswietlanie listy prac w formacie pelnym" << std::endl;
    std::cout << "[5] Wyszukiwanie pracy" << std::endl;
    std::cout << "[6] Dodatkowe funkcje" << std::endl;
    std::cout << "[X] Wyjscie z programu" << std::endl;

}

void searchMenuMessage() {

    std::cout << "Na podstawie jakiego kryterium chcesz wyszukac prace?" << std::endl;
    std::cout << "[1] Nazwisko autora" << std::endl;
    std::cout << "[2] Nazwisko promotora" << std::endl;
    std::cout << "[3] Tytul" << std::endl;
    std::cout << "[4] Slowo kluczowe" << std::endl;
    std::cout << "[5] Streszczenie" << std::endl;
    std::cout << "[6] Rok powstania" << std::endl;
    std::cout << "[X] Wyjscie z wyszukiwania" << std::endl;

}

void subMenuMessage() {
    std::cout << "Wybierz dodatkowe funkcje programu. Aby wyjsc z submenu, nacisnij X" << std::endl;
    std::cout << "[1] Wyswietlanie liczby wszystkich prac" << std::endl;
    std::cout << "[2] Wyswietlanie liczby prac dla poszczegolnych promotorow" << std::endl;
    std::cout << "[3] Wyswietlanie 10 slow kluczowych" << std::endl;
    std::cout << "[4] Wyswietlanie 10 slow kluczowych" << std::endl;
    std::cout << "[X] Wyjscie z dodatkowych funkcji" << std::endl;
}

void typPracyMessage(Praca::messageFlag flag) {
    switch (flag) {
    case Praca::initial:
        std::cout << "Dodaj typ pracy." << std::endl;
        break;
    case Praca::error:
        std::cout << "Niedozwolony typ pracy." << std::endl;
        break;
    case Praca::allowedValues:
        std::cout << " Dozwolone typy pracy to: " << std::endl;
        printTypeList(dozwoloneTypy);
        break;
    default:
        break;
    }
}