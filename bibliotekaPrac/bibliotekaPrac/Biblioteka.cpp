#include "Biblioteka.h"
#include "additionalFunctions.h"
#include "Praca.h"

#include <string>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <array>
#include <stdexcept>
#include <cstring>  // strtok, etc
#include <sstream>


bool cmp(std::pair<int, Praca> a, std::pair<int, Praca> b) {
    return a.first < b.first;
    // test
}

int Biblioteka::getLastId(std::vector<std::pair<int, Praca>>& listaPrac) {

    std::sort(listaPrac.begin(), listaPrac.end(), cmp);

    std::cout << listaPrac.back().first << std::endl;

    return listaPrac.back().first;

}

// Inicjalizuje menu biblioteki
void Biblioteka::menu(Biblioteka & biblioteka) {

    int choice{};
    bool subMenu = false;

    menuMessage();

    std::cin >> choice;

    switch (choice) {
    case 1:
        std::cout << "Dodawanie prac" << std::endl;
        biblioteka.dodajPrace();
        break;

    case 2:
        std::cout << "Edycja pracy" << std::endl;
        break;
    case 3:
        std::cout << "Wyswietlanie listy prac w formacie skroconym" << std::endl;

        break;
    case 4:
        std::cout << "Wyswietlanie listy prac w formacie pelnym" << std::endl;
        break;
    case 5:
        std::cout << "Wyszukiwanie pracy" << std::endl;
        break;
    case 6:
        std::cout << "Dodatkowe funkcje" << std::endl;
        subMenu = true;
        break;
    }

    if (subMenu) {

        int choice{};

        subMenuMessage();

        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Wyswietlanie liczby wszystkich prac" << std::endl;
            break;
        case 2:
            std::cout << "Wyswietlanie liczby prac dla poszczegolnych promotorow" << std::endl;
            break;
        case 3:
            std::cout << "Wyswietlanie 10 slow kluczowych" << std::endl;
            break;
        default:
            std::cout << "Wybiez jedna z trzech funkcji" << std::endl;
            break;

        }
    }

}

int Biblioteka::checkValue(std::string line, const std::string id[]) {

    std::string lineId = "";

    if (true) {
        for (int i = 0; i < ILE_WARTOSCI_PRACA; ++i) {
            if (line.substr(0, 2) == id[i]) return i;
            if (line == "") return -1;
        }
    }
}

//void Biblioteka::wypiszPrace(Praca & praca) {
//    std::cout   << praca.idPraca << std::endl
//                << praca.typPracy << std::endl
//                << praca.tytul << std::endl
//                << praca.nazwiskoAutora << std::endl
//                << praca.imionaAutora << std::endl
//                << praca.inicjalyAutora << std::endl
//                << praca.rok << std::endl
//                << praca.imionaPromotora << std::endl
//                << praca.slowaKluczowe << std::endl
//                << praca.streszczenie << std::endl;
//}

// Wczytuje wszystkie prace
//void Biblioteka::wczytajPrace(std::vector<std::pair<int, Praca>>& listaPrac) {
//
//    Praca nowaPraca;
//
//    std::ifstream stream("prace.txt");
//    stream.seekg(0);
//
//    std::string tempLine;
//
//    int counter = 0;
//
//    while (!stream.eof())
//    {
//        std::getline(stream, tempLine);
//
//        switch (checkValue(tempLine, lineId)) {
//        case 0:
//            tempLine.erase(0, 3);
//            nowaPraca.Praca::idPraca = stol(tempLine);
//            counter++;
//            break;
//        case 1:
//            tempLine.erase(0, 3);
//            nowaPraca.Praca::typPracy = tempLine;
//            counter++;
//            break;
//        case 2:
//            tempLine.erase(0, 3);
//            nowaPraca.Praca::tytul = tempLine;
//            counter++;
//            break;
//        case 3:
//            tempLine.erase(0, 3);
//            nowaPraca.Praca::nazwiskoAutora = tempLine;
//            counter++;
//            break;
//        case 4:
//            tempLine.erase(0, 3);
//            nowaPraca.Praca::imionaAutora = tempLine;
//            counter++;
//            break;
//        case 5:
//            tempLine.erase(0, 3);
//            nowaPraca.Praca::inicjalyAutora = tempLine;
//            counter++;
//            break;
//        case 6:
//            tempLine.erase(0, 3);
//            nowaPraca.Praca::rok = stol(tempLine);
//            counter++;
//            break;
//        case 7:
//            tempLine.erase(0, 3);
//            nowaPraca.Praca::nazwiskoPromotora = tempLine;
//            counter++;
//            break;
//        case 8:
//            tempLine.erase(0, 3);
//            nowaPraca.Praca::imionaPromotora = tempLine;
//            counter++;
//            break;
//        case 9:
//            tempLine.erase(0, 3);
//            nowaPraca.Praca::slowaKluczowe = tempLine;
//            counter++;
//            break;
//        case 10:
//            tempLine.erase(0, 3);
//            nowaPraca.Praca::streszczenie = tempLine;
//            counter++;
//            break;
//        default:
//            // std::cout << "Blad podczas wczytywania danych" << std::endl;
//            break;
//        }
//
//        if (counter == ILE_WARTOSCI_PRACA) {
//            listaPrac.push_back(std::make_pair(nowaPraca.idPraca, nowaPraca));
//            // wypiszPrace(nowaPraca);
//            counter = 0;
//        }
//    }
//
//
//
//
//}

// Wyswietla skrocona liste prac
void Biblioteka::wyswSkrocone() {

}

// Wyswietla pelna liste prac
void Biblioteka::wyswPelne(std::vector<std::pair<int, Praca>>& listaPrac, int vectorSize) {

}

// Funkcja pozwalajace dodac nowa prace
void Biblioteka::dodajPrace() {

    Praca nowaPraca;
    std::cout << "Dodano nowa instancje praca" << std::endl;

    nowaPraca.Praca::dodajIdPracy(Biblioteka::getLastId(listaPrac));
    std::cout << "Do pracy przypisano ID" << std::endl;
    std::cout << "ID tej pracy: " << nowaPraca.Praca::printSelected(0) << std::endl;

    nowaPraca.Praca::addTypPracy();
    nowaPraca.Praca::addTytul();
    nowaPraca.Praca::addNazwiskoAutora();
    nowaPraca.Praca::addImionaAutora();

    nowaPraca.Praca::addRok();
    nowaPraca.Praca::addNazwiskoPromotora();
    nowaPraca.Praca::addImionaPromotora();
    nowaPraca.Praca::addSlowaKluczowe();
    nowaPraca.Praca::addStreszczenie();

    listaPrac.push_back(std::make_pair(nowaPraca.Praca::returnIdPracy(), nowaPraca));
    // zapiszPrace(listaPrac);
}

// Funkcja zapisujaca prace w pliku i w bibliotece
// void Biblioteka::zapiszPrace(std::vector<std::pair<int, Praca>>& listaPrac) {
//
//    std::sort(listaPrac.begin(), listaPrac.end(), cmp);
//
//    std::ofstream myfile("prace.txt", std::ofstream::out | std::ofstream::trunc);
//
//    for (int i = 0; i < listaPrac.size(); i++) {
//        myfile  << "ID " << listaPrac[i].second.idPraca << '\n'
//                << "TP " << listaPrac[i].second.typPracy << '\n'
//                << "TT " << listaPrac[i].second.tytul << '\n'
//                << "AN " << listaPrac[i].second.nazwiskoAutora << '\n'
//                << "AI " << listaPrac[i].second.imionaAutora << '\n'
//                << "II " << listaPrac[i].second.inicjalyAutora << '\n'
//                << "YY " << listaPrac[i].second.rok << '\n'
//                << "PN " << listaPrac[i].second.nazwiskoPromotora << '\n'
//                << "PI " << listaPrac[i].second.imionaPromotora << '\n'
//                << "SK " << listaPrac[i].second.slowaKluczowe << '\n'
//                << "ST " << listaPrac[i].second.streszczenie << '\n';
//    }
//    myfile.close();
//}

// Pozwala edytowac wybrana prace
 void Biblioteka::edytujPrace(std::vector<std::pair<int, Praca>> listaPrac) {

    std::cout << "Podaj ID pracy, ktora chcesz edytowac" << std::endl;

    int temp;
    int temp2 = 0;
    std::cin >> temp;

    for (int i = 0; i < listaPrac.size(); i++) {
        if (listaPrac[i].first == temp) {
            std::cout << "Znaleziono prace" << std::endl;
            temp2 = listaPrac[i].first;
        }
        else std::cout << "Nie ma takiej pracy!" << std::endl;
    }
    
    editMessage(); 

}

// Wyszukuje 
 void Biblioteka::szukaj() {
    searchMenuMessage();
}

// Wyswietla liczbe prac w bibliotece
 void Biblioteka::ilePrac() {

}

// Wyswietla liczbe prac dla danego promotora
 void Biblioteka::ilePracPromotora() {

}

// Wyswietla najczesciej wystepujace slowa kluczowe
 void Biblioteka::najczSlowaKluczowe() {

}