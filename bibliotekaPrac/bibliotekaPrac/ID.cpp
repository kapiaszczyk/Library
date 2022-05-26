#include "ID.h"

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm> // std::sort


 int getID(std::vector<std::pair<int, Praca>> listaPrac) {
     std::sort(listaPrac.begin(), listaPrac.end());
     return listaPrac.back().first;
}

/*
 void ID::overwriteLastId() {

    std::fstream file;
    file.open("prace.txt", std::ios::out);

    if (file.good())
    {
        file << returnLastID();
    }

    else {
        throw std::invalid_argument("Plik uszkodzony - nie mozna zapisac ostatniego ID");
    }

}
*/