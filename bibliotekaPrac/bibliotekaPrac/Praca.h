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
        initial, error, allowedValue
    };

    Praca() 
    {
        std::cout << "Praca constructor called" << std::endl;        
    }

    // Funkcje dodajace poszczegolne pola pracy

        // Funkcja przypisujaca id
        void dodajIdPracy(int lastID);

        // Funkcja przypisujaca typ pracy
        std::string addTypPracy();

        // Funkcja przypisujaca tytul pracy
        std::string addTytul();

        // Funkcja przypisujaca nazwisko autora
        std::string addNazwiskoAutora();

        // Funkcja przypisujaca imiona autora
        std::string addImionaAutora();

        // Funkcja generujaca inicjaly autora
        void getInicjal(std::string, std::string& inicjalyAutora, const char);

        // Funkcja przypisujaca rok
        int addRok();

        // Funkcja przypisujaca nazwisko promotora
        std::string addNazwiskoPromotora();

        // Funkcja przypisujaca imiona promotora
        std::string addImionaPromotora();

        // Funkcja przypisujaca slowa kluczowe
        std::string addSlowaKluczowe();

        // Funkcja przypisujaca streszczenie
        std::string addStreszczenie();

    // Inne funkcje



    void printPraca(int id);

    std::string printSelected(int choice) {

        switch (choice) {
        case (0):
            return std::to_string(idPraca);
            break;
        default:
            return "NaN";
            break;
        }
    }

    int returnIdPracy() {
        return idPraca;
    }

    bool validateType(std::string, const std::vector<std::string>);

   

};

#endif