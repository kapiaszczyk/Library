#include <string>
#include <vector>

#include "Praca.h"
#include "Biblioteka.h"

// Constants
const int MINIMALNY_ROK = 2000;
const int ILE_TYPOW_PRAC = 3;
const int ILE_WARTOSCI_PRACA = 11;
const char COMA = ',';
const char SEMICOLON = ';';
const std::string IDENTYFIKATORY_DANYCH[] = { "ID", "TP", "TT", "AN", "AI", "II", "YY", "PN", "PI", "SK", "ST" };
const std::vector<std::string> DOZWOLONE_TYPY_PRAC = { "mgr", "inz", "lic" };

int main() {

    Biblioteka biblioteka;

    biblioteka.Biblioteka::wczytajPrace(biblioteka.Biblioteka::listaPrac);
    biblioteka.Biblioteka::menu(biblioteka);
    biblioteka.Biblioteka::zapiszPrace(biblioteka.Biblioteka::listaPrac);

    return 0;
   
}
