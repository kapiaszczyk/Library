#include "UI_messages.h"
#include "Praca.h"

void coutInputIndicator() {
    std::cout << ">> ";
}

void printTypeList(const std::vector<std::string> dozwoloneTypy) {
    for (unsigned int i = 0; i < dozwoloneTypy.size(); i++) std::cout << ">> " << dozwoloneTypy[i] << std::endl;
}

void messageFoundInID() {
    std::cout << ">> Znaleziono w pracach o ID: ";
}

void editMessageInitial() {
    std::cout << ">> Podaj ID pracy, ktora chcesz edytowac\n";
    coutInputIndicator();
}

void editMessage() {
    std::cout << ">> Ktora wartosc chcesz edytowac?\n";
    separatorLine();
    std::cout << "[1] Typ pracy\n";
    std::cout << "[2] Tytul\n";
    std::cout << "[3] Nazwisko autora\n";
    std::cout << "[4] Imie autora\n";
    std::cout << "[5] Rok powstania\n";
    std::cout << "[6] Slowo kluczowe\n";
    std::cout << "[7] Streszczenie\n";
    std::cout << "[8] Anuluj edycje pracy\n" << std::flush;

    coutInputIndicator();

}

void menuMessage() {

    std::cout << ">> Wybierz funkcje programu. Aby wyjsc z programu, nacisnij 7.\n";
    std::cout << "[1] Dodawanie pracy\n";
    std::cout << "[2] Edycja pracy\n";
    std::cout << "[3] Wyswietlanie listy prac w formacie skroconym\n";
    std::cout << "[4] Wyswietlanie listy prac w formacie pelnym\n";
    std::cout << "[5] Wyszukiwanie pracy\n";
    std::cout << "[6] Dodatkowe funkcje\n";
    std::cout << "[7] Wyjscie z programu\n" << std::flush;
    coutInputIndicator();

}

void searchMenuMessage() {

    std::cout << ">> Na podstawie jakiego kryterium chcesz wyszukac prace?\n";
    std::cout << "[1] Nazwisko autora\n";
    std::cout << "[2] Nazwisko promotora\n";
    std::cout << "[3] Tytul\n";
    std::cout << "[4] Slowo kluczowe\n";
    std::cout << "[5] Streszczenie\n";
    std::cout << "[6] Rok powstania\n";
    std::cout << "[7] Anuluj wyszukiwanie\n" << std::flush;
    coutInputIndicator();

}

void subMenuMessage() {
    std::cout << ">> Wybierz dodatkowe funkcje programu. Aby wyjsc z submenu, nacisnij 4\n";
    std::cout << "[1] Wyswietlanie liczby wszystkich prac\n";
    std::cout << "[2] Wyswietlanie liczby prac dla poszczegolnych promotorow\n";
    std::cout << "[3] Wyswietlanie 10 slow kluczowych\n";
    std::cout << "[4] Wyjscie z dodatkowych funkcji\n" << std::flush;
    coutInputIndicator();
}


 void errorLibraryEmpty() {
     std::cout << ">> Nie mozna wyswietlic/wczytac zawartosci biblioteki, poniewaz jest ona pusta. Dodaj prace, aby umozliwic wyswietlanie/wczytanie jej zawartosci.\n";
 }

void typPracyMessage(int x) {
    switch (x) {
    case 0:
        std::cout << ">> Dodaj typ pracy:\n" << std::flush;
        break;
    case 1:
        std::cout << ">> Niedozwolony typ pracy.\n";
        break;
    case 2:
        std::cout << ">> Dozwolone typy pracy to:\n" << std::flush;
        printTypeList(DOZWOLONE_TYPY_PRAC);
        break;
    default:
        break;
    }
}

void separatorLine() {
    std::cout << "------------------------------\n";
}
