#include <string>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <array>
#include <array>
#include <stdexcept>
#include <cstring>  // strtok, etc
#include <sstream>
#include <windows.h>

#include "Praca.h"
#include "Biblioteka.h"

// Constants
const int MINIMALNY_ROK = 2000;
const int ILE_TYPOW_PRAC = 3;
const int ILE_WARTOSCI_PRACA = 11;
const char COMA = ',';
const char SEMICOLON = ';';

const std::string lineId[] = { "ID", "TP", "TT", "AN", "AI", "II", "YY", "PN", "PI", "SK", "ST" };
const std::vector<std::string> dozwoloneTypy = { "mgr", "inz", "lic" };

int main() {

    //Biblioteka biblioteka;

    //biblioteka.Biblioteka::wczytajPrace(biblioteka.Biblioteka::listaPrac);
    //biblioteka.Biblioteka::menu(biblioteka);

    Praca newPraca;



    //Sleep(36000);


    return 0;
   
}
