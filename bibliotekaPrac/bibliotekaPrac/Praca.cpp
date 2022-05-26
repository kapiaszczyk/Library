#include "Praca.h"
#include "UI_messages.h"

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>
#include <boost/algorithm/string/case_conv.hpp>

// Funkcja przypisujaca id
void Praca::dodajIdPracy(int lastID) {
    Praca::idPraca = lastID + 1;
}

// Funkcja przypisujaca typ pracy
void Praca::addTypPracy() {

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

    Praca::typPracy = temp;

}

// Funkcja przypisujaca tytul do pracy
void Praca::addTytul() {

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


    Praca::tytul =  temp;
}

// Funkcja przypisujaca nazwisko autora do pracy
void Praca::addNazwiskoAutora() {

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

    Praca::nazwiskoAutora = temp;
}

// Funkcja przypisujaca imiona autora do pracy
void Praca::addImionaAutora() {

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

    Praca::imionaAutora = temp;
}

// Funkcja generujaca inicjaly
void Praca::getInicjal(std::string imionaAutora, std::string &inicjalyAutora, const char COMA) {

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

    Praca::inicjalyAutora = tempString;

}

// Funkcja przypisujaca rok do pracy
void Praca::addRok() {

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

    Praca::rok = temp;
}

// Funkcja przypisujaca nazwisko promotora do pracy
void Praca::addNazwiskoPromotora() {

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

    Praca::nazwiskoPromotora = temp;

}

// Funkcja przypisujaca imiona promotora do pracy
 void Praca::addImionaPromotora() {

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
    Praca::imionaPromotora = temp;
}

 // Funkcja przypisujaca slowa kluczowe do pracy
 void Praca::addSlowaKluczowe() {
    std::string temp = "";

    std::cout << "Dodaj slowa kluczowe oddzielone srednikami" << std::endl;

    std::getline(std::cin, temp);

    Praca::slowaKluczowe = temp;
}

 // Funkcja przypisujaca streszczenie do pracy
 void Praca::addStreszczenie() {

     std::string temp = "";

     std::cout << "Dodaj streszczenie" << std::endl;

     std::getline(std::cin, temp);

     if (temp != "" && temp.size() > 1000) {

         std::cout << "Maksymalna ilosc znakow to 1000!" << std::endl;

         while (temp != "") {

             std::getline(std::cin, temp);

         }
     }

     Praca::streszczenie = temp;

 }

// MISC FUNCTIONS

// Wypisuje wszystkie dane pracy
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

 // Sprawdza, czy typ pracy spelnia wymagania
 bool Praca::validateType(std::string input, const std::vector<std::string> dozwoloneTypy) {
    return std::find(dozwoloneTypy.begin(), dozwoloneTypy.end(), input) != dozwoloneTypy.end();
}

 // Funkcja resetuje strumien wejscia
 void Praca::clearCin() {
     std::cin.clear();
     std::cin.ignore();
 }

 // Funkcja drukujaca dane Pracy
 std::string Praca::printSelected(int choice) {

     switch (choice) {
     case (0):
         return std::to_string(Praca::idPraca);
         break;
     default:
         return "NaN";
         break;
     }
 }

 // Funkcja przekazuje wartosc id Pracy
 int Praca::returnIdPracy() {
     return Praca::idPraca;
 }