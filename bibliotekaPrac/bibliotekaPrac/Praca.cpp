#include "Praca.h"
#include "UI_messages.h"

// #include "additionalFunctions.h"

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>
#include <boost/algorithm/string/case_conv.hpp>

void Praca::clearCin() {
    std::cin.clear();
    std::cin.ignore();
}

// Funkcja przypisujaca id
void Praca::dodajIdPracy(int lastID) {
    Praca::idPraca = lastID + 1;
}

// Funkcja przypisujaca typ pracy
std::string Praca::addTypPracy() {

    typPracyMessage(initial);
    typPracyMessage(allowedValues);

    std::string temp = "";

    while (!Praca::validateType(temp, dozwoloneTypy)) {

        std::cin >> temp;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        boost::algorithm::to_lower(temp);

        if (!Praca::validateType(temp, dozwoloneTypy)) {

            typPracyMessage(error);
            typPracyMessage(allowedValues);
            Praca::clearCin();

        }

    }

    return temp;
}



// Wypisuje wszystkie dane obiektu Praca
void Praca::printPraca(int id) {
    std::cout
        << idPraca << std::endl
        << typPracy << std::endl
        << tytul << std::endl
        << nazwiskoAutora << std::endl
        << imionaAutora << std::endl
        << inicjalyAutora << std::endl
        << rok << std::endl
        << imionaPromotora << std::endl
        << slowaKluczowe << std::endl
        << streszczenie << std::endl;
}

// Sprawdza, czy rok spe³nia wymagania
 bool validateYear(int input) {

    if (input == 0 || input < MINIMALNY_ROK) return false;
    return true;

}

 bool Praca::validateType(std::string input, const std::vector<std::string> dozwoloneTypy) {
    return std::find(dozwoloneTypy.begin(), dozwoloneTypy.end(), input) != dozwoloneTypy.end();
}

 void Praca::getInicjal(std::string imionaAutora, std::string& inicjalyAutora, const char COMA) {

    std::vector<std::string> imiona{};

    std::stringstream sstream(imionaAutora);
    std::string word;
    std::string tempString;

    while (std::getline(sstream, word, COMA)) {
        imiona.push_back(word);
    }

    for (int i = 0; i < imiona.size(); i++) {
        std::cout << imiona[i] << " " << imiona[i].substr(0, 1) << std::endl;
        tempString += imiona[i].substr(0, 1) + ". ";
    }

    inicjalyAutora = tempString;

}

 std::string Praca::addStreszczenie() {

    std::string temp = "";

    std::cout << "Dodaj streszczenie" << std::endl;

    std::getline(std::cin, temp);

    if (temp != "" && temp.size() > 1000) {

        std::cout << "Maksymalna ilosc znakow to 1000!" << std::endl;

        while (temp != "") {

            std::getline(std::cin, temp);

        }
    }

    return temp;

}

 std::string Praca::addSlowaKluczowe() {
    std::string temp = "";

    std::cout << "Dodaj slowa kluczowe oddzielone srednikami" << std::endl;

    std::getline(std::cin, temp);

    return temp;
}

 std::string Praca::addImionaPromotora() {

    std::string temp = "";

    while (temp == "") {

        std::cout << "Dodaj imiona promotora oddzielone przecinkami" << std::endl;

        std::getline(std::cin, temp);

        if (temp == "") {

            std::cout << "Imiona promotora nie moga byc puste!" << std::endl;

            temp = "";

            Praca::clearCin();
        }


    }
    return temp;
}

 std::string Praca::addNazwiskoPromotora() {

    std::string temp = "";

    while (temp == "") {

        std::cout << "Dodaj nazwisko promotora" << std::endl;

        std::getline(std::cin, temp);

        if (temp == "") {

            std::cout << "Nazwisko promotora nie moze byc puste!" << std::endl;
            temp = "";

            Praca::clearCin();
        }

    }

    return temp;

}

 int Praca::addRok() {

    int temp = 0;

    while (!validateYear(temp)) {

        std::cout << "Dodaj rok" << std::endl;

        std::cin >> temp;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (!validateYear(temp)) {

            std::cout << "Minimalny rok to " << MINIMALNY_ROK << std::endl;
            temp = 0;

            Praca::clearCin();

        }


    }

    return temp;
}

 std::string Praca::addImionaAutora() {

    std::string temp = "";

    while (temp == "") {

        std::cout << "Dodaj imiona autora oddzielone przecinkami" << std::endl;

        std::getline(std::cin, temp);

        if (temp == "") {
            std::cout << "Imiona autora nie moga byc puste!" << std::endl;
            temp = "";

            Praca::clearCin();
        }

    }

    getInicjal(temp, Praca::inicjalyAutora, COMA);

    return temp;
}

 std::string Praca::addNazwiskoAutora() {

    std::string temp = "";

    while (temp == "") {

        std::cout << "Dodaj nazwisko autora " << std::endl;

        std::cin >> temp;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (temp == "") {
            std::cout << "Nazwisko autora nie moze byc puste!" << std::endl;
            temp = "";

            Praca::clearCin();
        }

    }

    return temp;
}

 std::string Praca::addTytul() {

    std::string temp = "";

    while (temp == "") {

        std::cout << "Dodaj tytul pracy" << std::endl;

        std::getline(std::cin, temp);


        if (temp == "") {

            std::cout << "Tytul pracy nie moze byc pusty!" << std::endl;
            temp = "";

            Praca::clearCin();
        }

    }


    return temp;
}

