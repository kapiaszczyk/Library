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

public:

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

    void printTypeList(const std::vector<std::string>);

    bool validateType(std::string, const std::vector<std::string>);

    std::string addTypPracy();

    std::string addTytul();

    std::string addNazwiskoAutora();

    std::string addImionaAutora();

    void getInicjal(std::string, std::string& inicjalyAutora, const char);

    int addRok();

    std::string addNazwiskoPromotora();

    std::string addImionaPromotora();

    std::string addSlowaKluczowe();

    std::string addStreszczenie();

};

#endif