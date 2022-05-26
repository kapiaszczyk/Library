#pragma once
#ifndef PRACA_HPP_SEEN
#define PRACA_HPP_SEEN

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <boost/algorithm/string/case_conv.hpp>

extern const char COMA;
extern const char SEMICOLON;
extern const int MINIMALNY_ROK;
extern const int ILE_WARTOSCI_PRACA;
extern const std::vector<std::string> dozwoloneTypy;

class ID;

class Praca {

private:

    int idPraca = 0;
    int rok = 0;

    std::string typPracy;
    std::string tytul;
    std::string nazwiskoAutora;
    std::string imionaAutora;
    std::string inicjalyAutora;
    std::string nazwiskoPromotora;
    std::string imionaPromotora;
    std::string slowaKluczowe;
    std::string streszczenie;

public:

    enum messageFlag {
        initial, error, allowedValues
    };

    Praca() 
    {
        std::cout << "Praca constructor called" << std::endl;        
    }

    // Main Praca class member functions

        // Funkcja przypisujaca id
        void dodajIdPracy(int lastID);

        // Funkcja przypisujaca typ pracy
        void addTypPracy();

        // Funkcja przypisujaca tytul pracy
        void addTytul();

        // Funkcja przypisujaca nazwisko autora
        void addNazwiskoAutora();

        // Funkcja przypisujaca imiona autora
        void addImionaAutora();

        // Funkcja generujaca inicjaly autora
        void getInicjal(std::string, std::string& inicjalyAutora, const char);

        // Funkcja przypisujaca rok
        void addRok();

        // Funkcja przypisujaca nazwisko promotora
        void addNazwiskoPromotora();

        // Funkcja przypisujaca imiona promotora
        void addImionaPromotora();

        // Funkcja przypisujaca slowa kluczowe
        void addSlowaKluczowe();

        // Funkcja przypisujaca streszczenie
        void addStreszczenie();

    // Misc functions

        void printPraca(int id);

        std::string printSelected(int choice);

        int returnIdPracy();

        bool validateType(std::string, const std::vector<std::string>);

        bool validateYear(int input);

        void clearCin();

};

#endif