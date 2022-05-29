#pragma once
#ifndef PRACA_HPP_SEEN
#define PRACA_HPP_SEEN

#include <limits>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <boost/algorithm/string.hpp>
#include <boost/regex.hpp>                      // deleting duplicate spaces

extern const char COMA;
extern const char SEMICOLON;
extern const int MINIMALNY_ROK;
extern const int ILE_WARTOSCI_PRACA;
extern const std::vector<std::string> DOZWOLONE_TYPY_PRAC;

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

    Praca() {}

    // Main get functions

        // Funkcja przypisujaca id
        void addIdPracy(int ID, bool creatingNew);

        // Funkcja przypisujaca typ pracy
        void addTypPracy(std::string externaValue);

        // Funkcja przypisujaca tytul pracy
        void addTytul(std::string externaValue);

        // Funkcja przypisujaca nazwisko autora
        void addNazwiskoAutora(std::string externaValue);

        // Funkcja przypisujaca imiona autora
        void addImionaAutora(std::string externaValue);

        // Funkcja generujaca inicjaly autora
        void getInicjal(std::string, const char, std::string externaValue);

        // Funkcja przypisujaca rok
        void addRok(int externaValue);

        // Funkcja przypisujaca nazwisko promotora
        void addNazwiskoPromotora(std::string externaValue);

        // Funkcja przypisujaca imiona promotora
        void addImionaPromotora(std::string externaValue);

        // Funkcja przypisujaca slowa kluczowe
        void addSlowaKluczowe(bool, std::string externaValue);

        // Funkcja przypisujaca streszczenie
        void addStreszczenie(bool addingNew, std::string externaValue);

    // Main read functions

        // Funkcja przekazujaca ID pracy
        int readIdPracy();

        // Funkcja przekazujaca typ pracy
        std::string readTypPracy();

        // Funkcja przekazujaca tytul pracy
        std::string readTytul();

        // Funkcja przekazujaca nazwisko autora
        std::string readNazwiskoAutora();

        // Funkcja przekazujaca imiona autora
        std::string readImionaAutora();

        // Funkcja przekazujaca inicjaly autora
        std::string readInicjal();

        // Funkcja przekazujaca rok
        int readRok();

        // Funkcja przekazujaca nazwisko promotora
        std::string readNazwiskoPromotora();

        // Funkcja przekazujaca imiona promotora
        std::string readImionaPromotora();

        // Funkcja przekazujaca slowa kluczowe
        std::string readSlowaKluczowe();
        
        // Funkcja przekazujaca streszczenie kluczowe
        std::string readStreszczenie();

    // Edit member data functions

        // Edytowanie typu pracy
        void editTypPracy();

        void editTytul();

        void editNazwiskoAutora();
	
        void editImionaAutora();
		
        void getInicjal(std::string imionaAutora, const char COMA);

		void editRok();

		void editNazwiskoPromotora();

		void editImionaPromotora();

		void editSlowaKluczowe();

		void editStreszczenie();


    // Misc functions

        // Wypisuje wszystkie dane pracy
        void printPraca(int id);

        // Sprawdza, czy rok spe³nia wymagania
        bool validateYear(int input);

        // Sprawdza, czy typ pracy spelnia wymagania
        bool validateType(std::string input, const std::vector<std::string>);

        // Funkcja resetuje strumien wejscia
        void clearCin();

};

#endif